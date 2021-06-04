#pragma once

#include "Animator.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <memory>

class Asteroid final: public sf::Drawable
{
public:
    Asteroid();

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
    float scale_;

    std::unique_ptr<Animator> animator_{nullptr};
};