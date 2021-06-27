#include "game.h"

#include "asset_manager.h"
#include "collision.h"

#include <spdlog/fmt/fmt.h>
#include <spdlog/spdlog.h>
#include <cstdlib>

Game::Game()
    : window_(sf::VideoMode(1200, 800), "Asteroid v1"),
      score_text_{},
      score_{0},
      spaceship_{},
      asteroids_{static_cast<size_t>(rand() % 90 + 10)},
      explosions_{},
      bullets_{},
      should_render_bounds_{false} {
  score_text_.setFont(AssetManager::Instance().Font("EvilEmpire-4BBVK.ttf"));
  score_text_.setPosition(10, 10);
  score_text_.setString("Score: 0");
  score_text_.setCharacterSize(32);
  score_text_.setFillColor(sf::Color::Red);
}

void Game::Run(int fps) {
  sf::Clock clock{};
  sf::Time time_since_last_update{sf::Time::Zero};
  sf::Time time_per_frame = sf::seconds(1.f / static_cast<float>(fps));

  while (window_.isOpen()) {
    this->ProcessEvents();

    bool repaint{false};
    time_since_last_update += clock.restart();
    while (time_since_last_update > time_per_frame) {
      repaint = true;
      time_since_last_update -= time_per_frame;
      this->Update(time_per_frame);
    }

    if (repaint) {
      this->Render();
    }
  }
}

void Game::ProcessEvents() {
  sf::Event event;
  while (window_.pollEvent(event)) {
    switch (event.type) {
      case sf::Event::EventType::Closed:
        window_.close();
        break;
      case sf::Event::EventType::KeyPressed:
        if (event.key.code == sf::Keyboard::Space) {
          HandleSpaceshipFire();
        } else if (event.key.code == sf::Keyboard::R) {
          HandleReset();
        } else if (event.key.code == sf::Keyboard::B) {
          should_render_bounds_ = !should_render_bounds_;
        }

        break;
      default:
        break;
    }
  }
}

void Game::Update(sf::Time time_per_frame) {
  HandleExpiredExplosions();
  HandleObjectOutofBound();
  HandleCollision();

  spaceship_.Update(time_per_frame);

  for (auto& a : asteroids_) {
    a.Update(time_per_frame);
  }

  for (auto& e : explosions_) {
    e.Update(time_per_frame);
  }

  for (auto& b : bullets_) {
    b.Update(time_per_frame);
  }
}

void Game::Render() {
  spdlog::info("Render: {} asteroids, {} bullets, {} explosions",
               asteroids_.size(), bullets_.size(), explosions_.size());
  window_.clear();

  for (const auto& a : asteroids_) {
    window_.draw(a);
  }

  for (const auto& e : explosions_) {
    window_.draw(e);
  }

  for (const auto& b : bullets_) {
    window_.draw(b);
  }

  if (should_render_bounds_) {
    RenderBounds();
  }

  window_.draw(spaceship_);

  score_text_.setString(fmt::format("Score: {}", score_));
  window_.draw(score_text_);

  window_.display();
}

void Game::HandleSpaceshipFire() {
  bullets_.emplace_back(spaceship_.Position().x, spaceship_.Position().y,
                        spaceship_.Angle());
}

void Game::HandleCollision() {
  for (auto& a : asteroids_) {
    for (auto& b : bullets_) {
      if (a.IsActive() && b.IsActive() && IsCollide(a.Sprite(), b.Sprite())) {
        a.SetActive(false);
        b.SetActive(false);
        explosions_.emplace_back(b.Bounds().left, b.Bounds().top);
        score_++;
      }
    }
  }

  auto pos = std::remove_if(begin(asteroids_), end(asteroids_),
                            [](auto& e) { return !e.IsActive(); });
  asteroids_.erase(pos, end(asteroids_));

  auto pos2 = std::remove_if(begin(bullets_), end(bullets_),
                             [](auto& e) { return !e.IsActive(); });
  bullets_.erase(pos2, end(bullets_));
}

void Game::HandleObjectOutofBound() {
  const sf::FloatRect bound{0, 0, 1200, 800};

  auto pos = std::remove_if(
      begin(asteroids_), end(asteroids_),
      [&bound](auto& e) { return !e.Bounds().intersects(bound); });
  asteroids_.erase(pos, end(asteroids_));

  auto pos2 = std::remove_if(begin(bullets_), end(bullets_), [&bound](auto& e) {
    return !e.Bounds().intersects(bound);
  });
  bullets_.erase(pos2, end(bullets_));
}

void Game::HandleExpiredExplosions() {
  auto pos = std::remove_if(begin(explosions_), end(explosions_),
                            [](auto& e) { return e.IsDoneAnimation(); });
  explosions_.erase(pos, end(explosions_));
}

void Game::HandleReset() {
  auto size = asteroids_.size();
  for (int i = 0; i + size <= 100; ++i) {
    asteroids_.emplace_back(Asteroid{});
  }
}

bool Game::IsCollide(const sf::Sprite& left, const sf::Sprite& right) {
  return collision::PixelPerfectTest(left, right);
}

void Game::RenderBounds() {
  for (const auto& a : asteroids_) {
    const auto& bound = a.Bounds();
    sf::RectangleShape box{sf::Vector2f{bound.width, bound.height}};
    box.setPosition(bound.left, bound.top);
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineColor(sf::Color::Red);
    box.setOutlineThickness(1.f);
    window_.draw(box);
  }

  for (const auto& b : bullets_) {
    const auto& bound = b.Bounds();
    sf::RectangleShape box{sf::Vector2f{bound.width, bound.height}};
    box.setPosition(bound.left, bound.top);
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineColor(sf::Color::Blue);
    box.setOutlineThickness(1.f);
    window_.draw(box);
  }
}