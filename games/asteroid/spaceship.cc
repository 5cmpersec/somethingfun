#include "spaceship.h"

#include "asset_manager.h"

#include <algorithm>
#include <cmath>
#include <iostream>

constexpr float DEG2RAD = 0.0174532925f;

Spaceship::Spaceship()
    : sprite_{AssetManager::Instance().Texture("spaceship.png")},
      x_{300},
      y_{300},
      angle_{0.0},
      speed_{15} {
  sprite_.setTextureRect(sf::IntRect(40, 0, 40, 40));
  sprite_.setOrigin(20, 20);
}

void Spaceship::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(sprite_, states);
}

void Spaceship::Update(sf::Time elapsed) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    angle_ += 3;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    angle_ += -3;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    x_ += std::sin(angle_ * DEG2RAD) * 3;
    y_ -= std::cos(angle_ * DEG2RAD) * 3;
  }

  sprite_.setPosition(x_, y_);
  sprite_.setRotation(angle_);
}

sf::Vector2f Spaceship::Position() const {
  return {x_, y_};
}

float Spaceship::Angle() const {
  return angle_;
}