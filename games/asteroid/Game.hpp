#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "Explosion.hpp"
#include "SpaceShip.hpp"

class Game final : sf::NonCopyable {
 public:
  Game();
  void run(int fps);

 private:
  void processEvents();
  void update(sf::Time delta);
  void render();

  void handleSpaceshipFire();
  void handleCollision();
  void handleObjectOutofBound();
  void handleExpiredExplosions();
  void handleReset();

 private:
  sf::RenderWindow window_;
  SpaceShip spaceShip_;
  std::vector<Asteroid> asteroids_;
  std::vector<Explosion> explosions_;
  std::vector<Bullet> bullets_;
};