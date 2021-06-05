#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class SpaceShip final : public sf::Drawable {
 public:
  SpaceShip();

 public:
  void update(sf::Time elapsed);

 private:
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  sf::Sprite sprite_;
  float x_;
  float y_;
  float angle_;
  float speed_;
};