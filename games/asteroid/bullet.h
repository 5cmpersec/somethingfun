#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Bullet final : public sf::Drawable {
 public:
  Bullet(float x, float y, float angle);

 public:
  void Update(sf::Time elapsed);
  sf::FloatRect Bounds() const;
  const sf::Sprite& Sprite() const;

  void SetActive(bool active);
  bool IsActive() const;

 private:
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  sf::Sprite sprite_;
  float x_;
  float y_;
  float angle_;

  bool active_;
};