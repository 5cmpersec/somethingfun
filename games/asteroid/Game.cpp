#include "Game.hpp"

#include <cstdlib>

Game::Game()
    : window_(sf::VideoMode(1200, 800), "Asteroid v1"),
      spaceShip_{},
      asteroids_{rand() % 90 + 10},
      explosion_{} {}

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

void Game::update([[maybe_unused]] sf::Time time_per_frame) {
  spaceShip_.update(time_per_frame);
  for (auto& a : asteroids_) {
    a.update(time_per_frame);
  }
  explosion_.update(time_per_frame);
}

void Game::render() {
  window_.clear();

  for (auto& a : asteroids_) {
    window_.draw(a);
  }

  window_.draw(spaceShip_);
  window_.draw(explosion_);

  window_.display();
}