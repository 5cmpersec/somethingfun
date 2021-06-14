#include "Bullet.hpp"
#include "AssetManager.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>

constexpr float DEG2RAD = 0.0174532925f;

Bullet::Bullet(float x, float y, float angle)
    : sprite_{AssetManager::getInstance().GetTexture("spaceship.png")},
      x_{x},
      y_{y},
      angle_{angle},
      speed_{15},
      active_{true} {
  sprite_.setTextureRect(sf::IntRect(4, 130, 4, 10));
  sprite_.setOrigin(2, 5);
  sprite_.setScale(3.0, 3.0);
  sprite_.setPosition(x_, y_);
  sprite_.setRotation(angle_);
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(sprite_, states);

  // box for debug
  const auto& bound = sprite_.getGlobalBounds();
  sf::RectangleShape box{sf::Vector2f{bound.width, bound.height}};
  box.setPosition(bound.left, bound.top);
  box.setFillColor(sf::Color::Transparent);
  box.setOutlineColor(sf::Color::Blue);
  box.setOutlineThickness(1.f);
  target.draw(box, states);
}

void Bullet::update(sf::Time elapsed) {
  float dx{0.0}, dy{0.0};

  dx += std::sin(angle_ * DEG2RAD) * 3;
  dy += -std::cos(angle_ * DEG2RAD) * 3;

  x_ += dx;
  y_ += dy;

  sprite_.setPosition(x_, y_);
}

sf::FloatRect Bullet::Bounds() const {
  return sprite_.getGlobalBounds();
}

void Bullet::setActive(bool active) {
  active_ = active;
}

bool Bullet::isActive() const {
  return active_ == true;
}