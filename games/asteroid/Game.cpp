#include "Game.hpp"

#include <spdlog/spdlog.h>

#include <cstdlib>

Game::Game()
    : window_(sf::VideoMode(1200, 800), "Asteroid v1"),
      spaceShip_{},
      asteroids_{rand() % 90 + 10},
      explosions_{},
      bullets_{} {
  explosions_.emplace_back(Explosion{});
}

void Game::run(int fps) {
  sf::Clock clock{};
  sf::Time time_since_last_update{sf::Time::Zero};
  sf::Time time_per_frame = sf::seconds(1.f / static_cast<float>(fps));

  while (window_.isOpen()) {
    this->processEvents();

    bool repaint{false};
    time_since_last_update += clock.restart();
    while (time_since_last_update > time_per_frame) {
      repaint = true;
      time_since_last_update -= time_per_frame;
      this->update(time_per_frame);
    }

    if (repaint) {
      this->render();
    }
  }
}

void Game::processEvents() {
  sf::Event event;
  while (window_.pollEvent(event)) {
    switch (event.type) {
      case sf::Event::EventType::Closed:
        window_.close();
        break;
      default:
        break;
    }
  }
}

void Game::update(sf::Time time_per_frame) {
  spaceShip_.update(time_per_frame);

  for (auto& a : asteroids_) {
    a.update(time_per_frame);
  }

  for (auto& e : explosions_) {
    e.update(time_per_frame);
  }

  for (auto& b : bullets_) {
    b.update(time_per_frame);
  }
}

void Game::render() {
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

  window_.draw(spaceShip_);

  window_.display();
}