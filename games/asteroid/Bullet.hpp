#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Bullet final : public sf::Drawable {
 public:
  Bullet(float x, float y, float angle);

 public:
  void update(sf::Time elapsed);
  sf::FloatRect Bounds() const;

  void setActive(bool active);
  bool isActive() const;

 private:
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  sf::Sprite sprite_;
  float x_;
  float y_;
  float angle_;
  float speed_;

  bool active_;
};