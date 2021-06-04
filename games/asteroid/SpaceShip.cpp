#include "SpaceShip.hpp"
#include "AssetManager.hpp"

#include <cmath>
#include <algorithm>
#include <iostream>

constexpr float DEG2RAD = 0.0174532925f;

SpaceShip::SpaceShip()
    : sprite_{AssetManager::getInstance().GetTexture("../res/spaceship.png")}
    , x_{300}
    , y_{300}
    , angle_{0.0}
    , speed_{15}
{
    sprite_.setTextureRect(sf::IntRect(40, 0, 40, 40));
    sprite_.setOrigin(20, 20);
}

void SpaceShip::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite_, states);
}

void SpaceShip::update(sf::Time elapsed)
{
    float dx{0.0}, dy{0.0};
    bool moving{false};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        angle_ += 3;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        angle_ += -3;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        moving = true;
        dx += std::sin(angle_ * DEG2RAD) * 3;
        dy += -std::cos(angle_ * DEG2RAD) *3;
    }

    // angle_ = std::clamp(angle_, -360.f, 360.f);

    if (moving)
    {
        x_ += dx;
        y_ += dy;
    }

    // angle *= elapsed.asSeconds() * speed_;

    sprite_.setPosition(x_, y_);
    sprite_.setRotation(angle_);
}