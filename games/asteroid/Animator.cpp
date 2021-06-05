#include "Animator.hpp"

#include <iostream>

Animator::Animator(sf::Sprite& sprite, Animation animation)
    : sprite_(sprite), animation_(std::move(animation)) {}

void Animator::update(const sf::Time& elapsed) {
  current_time_ += elapsed;

  auto num_frames = animation_.frames.size();
  auto frame_per_second = animation_.duration.asSeconds() / num_frames;
  auto current_frame =
      static_cast<int>(current_time_.asSeconds() / frame_per_second);

  if (animation_.looping) {
    current_frame %= num_frames;
  } else {
    current_frame = num_frames - 1;
  }

  sprite_.setTextureRect(animation_.frames[current_frame]);
}