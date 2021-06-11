#include "Bullet.hpp"
#include "AssetManager.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>

constexpr float DEG2RAD = 0.0174532925f;

Bullet::Bullet()
    : sprite_{AssetManager::getInstance().GetTexture("spaceship.png")},
      x_{400},
      y_{400},
      angle_{0.0},
      speed_{15} {
  sprite_.setTextureRect(sf::IntRect(4, 130, 4, 10));
  sprite_.setOrigin(2, 5);
  sprite_.setScale(3.0, 3.0);
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(sprite_, states);
}

void Bullet::update(sf::Time elapsed) {
  float dx{0.0}, dy{0.0};

  dx += std::sin(angle_ * DEG2RAD) * 3;
  dy += -std::cos(angle_ * DEG2RAD) * 3;

  x_ += dx;
  y_ += dy;

  sprite_.setPosition(x_, y_);
  sprite_.setRotation(angle_);
}