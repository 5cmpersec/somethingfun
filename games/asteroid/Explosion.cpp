#include "Explosion.hpp"

#include "AssetManager.hpp"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>

constexpr float DEG2RAD = 0.0174532925f;

Explosion::Explosion()
    : sprite_{AssetManager::getInstance().GetTexture("explosion.png")},
      x_{600},
      y_{400} {
  sprite_.setPosition(x_, y_);
  sprite_.setScale(3.0, 3.0);
  sprite_.setTextureRect(sf::IntRect(0, 0, 50, 50));

  sf::Vector2i frameSize{50, 50};
  std::vector<sf::IntRect> v{};
  for (int i = 0; i < 20; ++i) {
    v.emplace_back(frameSize.x * i, 0, frameSize.x, frameSize.y);
  }

  Animation a;
  a.name = "Explosion";
  a.duration = sf::seconds(2);
  a.looping = false;
  a.frames = v;

  animator_ = std::make_unique<Animator>(sprite_, a);
}

void Explosion::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(sprite_, states);
}

void Explosion::update(sf::Time elapsed) {
  animator_->update(elapsed);
}