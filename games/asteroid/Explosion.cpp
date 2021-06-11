#include "Explosion.hpp"

#include "AssetManager.hpp"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>

constexpr float DEG2RAD = 0.0174532925f;

Explosion::Explosion() : x_{400}, y_{400} {
  sprite_ = std::make_shared<sf::Sprite>(
      AssetManager::getInstance().GetTexture("explosion.png")),
  sprite_->setScale(3.0, 3.0);
  sprite_->setPosition(x_, y_);
  sprite_->setTextureRect(sf::IntRect(0, 0, 50, 50));

  sf::Vector2i frameSize{50, 50};
  std::vector<sf::IntRect> v{};
  for (int i = 0; i < 5; ++i) {
    v.emplace_back(frameSize.x * i, 0, frameSize.x, frameSize.y);
  }

  Animation a;
  a.name = "Explosion";
  a.duration = sf::seconds(2);
  a.looping = true;
  a.frames = v;

  animator_ = std::make_shared<Animator>(sprite_, a);
}

void Explosion::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(*sprite_, states);
}

void Explosion::update(sf::Time elapsed) {
  animator_->update(elapsed);
}