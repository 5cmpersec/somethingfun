#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "asteroid.h"
#include "bullet.h"
#include "explosion.h"
#include "spaceship.h"

#include <list>
#include <vector>

class Game final : sf::NonCopyable {
 public:
  Game();
  void Run(int fps);

 private:
  void ProcessEvents();
  void Update(sf::Time delta);
  void Render();

  void HandleSpaceshipFire();
  void HandleCollision();
  void HandleObjectOutofBound();
  void HandleExpiredExplosions();
  void HandleReset();

  void RenderBounds();

  static bool IsCollide(const sf::Sprite& left, const sf::Sprite& right);

 private:
  sf::RenderWindow window_;
  sf::Text score_text_;
  sf::Int32 score_;
  Spaceship spaceship_;
  std::vector<Asteroid> asteroids_;
  std::vector<Explosion> explosions_;
  std::vector<Bullet> bullets_;
  bool should_render_bounds_;
  sf::Sound gunshot_sound_;
  std::list<sf::Sound> explosion_sounds_;
};