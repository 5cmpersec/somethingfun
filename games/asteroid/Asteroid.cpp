#include "Asteroid.hpp"
#include "AssetManager.hpp"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>

constexpr float DEG2RAD = 0.0174532925f;

Asteroid::Asteroid()
    : x_{static_cast<float>(std::rand() % 1200)},
      y_{static_cast<float>(std::rand() % 800)},
      angle_{static_cast<float>(std::rand() % 360)},
      speed_{static_cast<float>(std::rand() % 15 + 1)},
      scale_{(std::rand() % 8 + 1) * 0.1f},
      active_{true} {
  sprite_ = std::make_shared<sf::Sprite>(
      AssetManager::getInstance().GetTexture("asteroids.png"));
  sprite_->setPosition(x_, y_);
  sprite_->setTextureRect(sf::IntRect(0, 0, 128, 128));
  sprite_->setOrigin(64, 64);
  sprite_->setScale(scale_, scale_);
  sprite_->setRotation(angle_);

  const sf::Vector2i frameSize{128, 128};
  std::vector<sf::IntRect> v{};
  int row = 4 * (rand() % 2);
  for (int i = row; i < row + 4; ++i)
    for (int j = 0; j < 8; ++j)
      v.emplace_back(frameSize.x * j, frameSize.y * i, frameSize.x,
                     frameSize.y);
  v.pop_back();

  Animation a{"Asteroid_1", sf::seconds(1), true, v};
  animator_ = std::make_shared<Animator>(sprite_, std::move(a));
}

void Asteroid::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(*sprite_, states);

  // box for debug
  const auto& bound = sprite_->getGlobalBounds();
  sf::RectangleShape box{sf::Vector2f{bound.width, bound.height}};
  box.setPosition(bound.left, bound.top);
  box.setFillColor(sf::Color::Transparent);
  box.setOutlineColor(sf::Color::Red);
  box.setOutlineThickness(1.f);
  target.draw(box, states);
}

void Asteroid::update(sf::Time elapsed) {
  animator_->update(elapsed);

  x_ += std::sin(angle_ * DEG2RAD) * 0.2;
  y_ += -std::cos(angle_ * DEG2RAD) * 0.2;

  sprite_->setPosition(x_, y_);
}

sf::FloatRect Asteroid::Bounds() const {
  return sprite_->getGlobalBounds();
}

void Asteroid::setActive(bool active) {
  active_ = active;
}

bool Asteroid::isActive() const {
  return active_ == true;
}

const sf::Sprite& Asteroid::Sprite() const {
  return *sprite_;
}