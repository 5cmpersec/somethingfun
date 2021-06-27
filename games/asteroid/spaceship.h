#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Spaceship final : public sf::Drawable {
 public:
  Spaceship();

 public:
  void Update(sf::Time elapsed);
  sf::Vector2f Position() const;
  float Angle() const;

 private:
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  sf::Sprite sprite_;
  float x_;
  float y_;
  float angle_;
  float speed_;
};