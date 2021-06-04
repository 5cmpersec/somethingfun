#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <string>
#include <vector>

struct Animation {
    std::string name{""};
    sf::Time duration{sf::Time::Zero};
    bool looping{false};
    std::vector<sf::IntRect> frames{};
};

class Animator
{
public:
    Animator(sf::Sprite& sprite, Animation animation);

    void update(const sf::Time& elapsed);

private:
    sf::Sprite& sprite_;
    Animation animation_;

    sf::Time current_time_{sf::Time::Zero};
};