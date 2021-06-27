#include "asset_manager.h"

#include <spdlog/fmt/fmt.h>
#include <cstdlib>

AssetManager& AssetManager::Instance() {
  static AssetManager instance;
  return instance;
}

sf::Texture& AssetManager::Texture(std::string_view filename) {
  const std::string filepath = fmt::format("{}/{}", res_dir_, filename);
  const auto& it = textures_.find(filepath);
  if (it != textures_.end()) {
    return it->second;
  }

  sf::Texture texture;
  if (!texture.loadFromFile(filepath)) {
    throw std::runtime_error("Cannot load texture: " + filepath);
  }

  textures_[filepath] = std::move(texture);
  return textures_.at(filepath);
}

sf::Font& AssetManager::Font(std::string_view filename) {
  const std::string filepath = fmt::format("{}/font/{}", res_dir_, filename);
  const auto& it = fonts_.find(filepath);
  if (it != fonts_.end()) {
    return it->second;
  }

  sf::Font font;
  if (!font.loadFromFile(filepath)) {
    throw std::runtime_error("Cannot load font: " + filepath);
  }
  fonts_[filepath] = std::move(font);
  return fonts_.at(filepath);
}

std::string AssetManager::ResourcesDirectory() {
  const auto* dir = std::getenv("RESOURCES_DIR");
  if (dir == nullptr) {
    return "";
  }

  return dir;
}