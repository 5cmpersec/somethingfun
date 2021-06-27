#pragma once

#include "animator.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <memory>

class Asteroid final : public sf::Drawable {
 public:
  Asteroid();

 public:
  void Update(sf::Time elapsed);
  sf::FloatRect Bounds() const;
  const sf::Sprite& Sprite() const;

  void SetActive(bool active);
  bool IsActive() const;

 private:
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  float x_;
  float y_;
  float angle_;
  float speed_;
  float scale_;
  bool active_;

  SpritePtr sprite_{nullptr};
  AnimatorPtr animator_{nullptr};
};