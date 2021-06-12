#pragma once

#include "Animator.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Explosion final : public sf::Drawable {
 public:
  Explosion(float x, float y);

 public:
  void update(sf::Time elapsed);
  bool isDoneAnimation() const;

 private:
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  float x_;
  float y_;

  SpritePtr sprite_{nullptr};
  AnimatorPtr animator_{nullptr};
};