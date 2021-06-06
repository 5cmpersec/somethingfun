#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include <map>
#include <string_view>

class AssetManager final : sf::NonCopyable {
 public:
  static AssetManager& getInstance();
  sf::Texture& GetTexture(std::string_view filename);

 private:
  std::map<std::string, sf::Texture> m_Textures{};
  const std::string m_resources_dir{std::getenv("RESOURCES_DIR")};
};
