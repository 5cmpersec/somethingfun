#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <memory>
#include <string>
#include <vector>

class Animator;

using SpritePtr = std::shared_ptr<sf::Sprite>;
using AnimatorPtr = std::shared_ptr<Animator>;

struct Animation {
  std::string name{""};
  sf::Time duration{sf::Time::Zero};
  bool looping{false};
  std::vector<sf::IntRect> frames{};
};

class Animator {
 public:
  Animator(SpritePtr sprite, Animation animation);

  void Update(const sf::Time& elapsed);
  bool IsDone() const;

 private:
  SpritePtr sprite_;
  Animation animation_;
  bool is_done_{false};

  sf::Time current_time_{sf::Time::Zero};
};