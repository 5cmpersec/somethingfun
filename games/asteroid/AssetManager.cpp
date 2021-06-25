#include "AssetManager.hpp"

#include <spdlog/fmt/fmt.h>
#include <cstdlib>

AssetManager& AssetManager::getInstance() {
  static AssetManager instance;
  return instance;
}

sf::Texture& AssetManager::GetTexture(std::string_view filename) {
  const std::string filepath = fmt::format("{}/{}", m_res_dir, filename);
  const auto& it = m_Textures.find(filepath);
  if (it != m_Textures.end()) {
    return it->second;
  }

  sf::Texture texture;
  if (!texture.loadFromFile(filepath)) {
    throw std::runtime_error("Cannot load texture: " + filepath);
  }

  m_Textures[filepath] = std::move(texture);
  return m_Textures.at(filepath);
}

sf::Font& AssetManager::GetFont(std::string_view filename) {
  const std::string filepath = fmt::format("{}/font/{}", m_res_dir, filename);
  const auto& it = m_Fonts.find(filepath);
  if (it != m_Fonts.end()) {
    return it->second;
  }

  sf::Font font;
  if (!font.loadFromFile(filepath)) {
    throw std::runtime_error("Cannot load font: " + filepath);
  }
  m_Fonts[filepath] = std::move(font);
  return m_Fonts.at(filepath);
}

std::string AssetManager::ResourcesDirectory() {
  const auto* dir = std::getenv("RESOURCES_DIR");
  if (dir == nullptr) {
    return "";
  }

  return dir;
}