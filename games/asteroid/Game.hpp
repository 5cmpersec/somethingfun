#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Asteroid.hpp"
#include "SpaceShip.hpp"

class Game final: sf::NonCopyable
{
public:
    Game();
    void run(int fps);

private:
    void processEvents();
    void update(sf::Time delta);
    void render();

private:
    sf::RenderWindow window_;
    SpaceShip spaceShip_;
    std::vector<Asteroid> asteroids_;
};