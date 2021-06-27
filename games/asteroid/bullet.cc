#include "bullet.h"
#include "asset_manager.h"

#include <algorithm>
#include <cmath>
#include <iostream>

constexpr float DEG2RAD = 0.0174532925f;

Bullet::Bullet(float x, float y, float angle)
    : sprite_{AssetManager::Instance().Texture("spaceship.png")},
      x_{x},
      y_{y},
      angle_{angle},
      active_{true} {
  sprite_.setTextureRect(sf::IntRect(4, 130, 4, 10));
  sprite_.setOrigin(2, 5);
  sprite_.setScale(3.0, 3.0);
  sprite_.setPosition(x_, y_);
  sprite_.setRotation(angle_);
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(sprite_, states);
}

void Bullet::Update(sf::Time elapsed) {
  x_ += std::sin(angle_ * DEG2RAD) * 3;
  y_ -= std::cos(angle_ * DEG2RAD) * 3;

  sprite_.setPosition(x_, y_);
}

sf::FloatRect Bullet::Bounds() const {
  return sprite_.getGlobalBounds();
}

void Bullet::SetActive(bool active) {
  active_ = active;
}

bool Bullet::IsActive() const {
  return active_ == true;
}

const sf::Sprite& Bullet::Sprite() const {
  return sprite_;
}