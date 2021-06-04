#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string_view>
#include <map>

class AssetManager final: sf::NonCopyable {
public:
    static AssetManager& getInstance();
    sf::Texture& GetTexture(std::string_view filename);

private:
    std::map<std::string_view, sf::Texture> m_Textures{};
};
