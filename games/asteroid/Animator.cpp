#include "Animator.hpp"

#include <iostream>

Animator::Animator(SpritePtr sprite, Animation animation)
    : sprite_(std::move(sprite)), animation_(std::move(animation)) {}

void Animator::update(const sf::Time& elapsed) {
  current_time_ += elapsed;

  const auto num_frames = animation_.frames.size();
  const auto frame_per_second = animation_.duration.asSeconds() / num_frames;
  auto current_frame =
      static_cast<size_t>(current_time_.asSeconds() / frame_per_second);

  if (animation_.looping) {
    current_frame %= num_frames;
  } else if (current_frame >= num_frames) {
    current_frame = num_frames - 1;
    isDone_ = true;
  }

  sprite_->setTextureRect(animation_.frames[current_frame]);
}

bool Animator::isDone() const {
  return isDone_;
}