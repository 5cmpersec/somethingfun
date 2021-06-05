#pragma once

#include "Animator.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <memory>

class Explosion final : public sf::Drawable {
 public:
  Explosion();

 public:
  void update(sf::Time elapsed);

 private:
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  sf::Sprite sprite_;
  float x_;
  float y_;

  std::unique_ptr<Animator> animator_{nullptr};
};