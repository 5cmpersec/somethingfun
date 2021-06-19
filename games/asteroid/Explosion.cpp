#include "Explosion.hpp"

#include "AssetManager.hpp"

Explosion::Explosion(float x, float y) : x_{x}, y_{y} {
  sprite_ = std::make_shared<sf::Sprite>(
      AssetManager::getInstance().GetTexture("explosion.png")),
  sprite_->setOrigin(25, 25);
  sprite_->setTextureRect(sf::IntRect(0, 0, 50, 50));
  sprite_->setScale(2.0, 2.0);
  sprite_->setPosition(x_, y_);

  sf::Vector2i frameSize{50, 50};
  std::vector<sf::IntRect> v{};
  for (int i = 0; i < 5; ++i) {
    v.emplace_back(frameSize.x * i, 0, frameSize.x, frameSize.y);
  }

  Animation a;
  a.name = "Explosion";
  a.duration = sf::seconds(1);
  a.looping = false;
  a.frames = v;

  animator_ = std::make_shared<Animator>(sprite_, a);
}

void Explosion::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(*sprite_, states);
}

void Explosion::update(sf::Time elapsed) {
  animator_->update(elapsed);
}

bool Explosion::isDoneAnimation() const {
  return animator_->isDone();
}