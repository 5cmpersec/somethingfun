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
    throw std::runtime_error(fmt::format("Cannot load texture: {}", filepath));
  }

  auto ret = textures_.emplace(filepath, std::move(texture));
  if (!ret.second) {
    throw std::runtime_error(
        fmt::format("Cannot insert texture: {}", filepath));
  }

  return ret.first->second;
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

  auto ret = fonts_.emplace(filepath, std::move(font));
  if (!ret.second) {
    throw std::runtime_error(fmt::format("Cannot insert font: {}", filepath));
  }

  return ret.first->second;
}

sf::SoundBuffer& AssetManager::SoundBuffer(std::string_view filename) {
  const std::string filepath = fmt::format("{}/sound/{}", res_dir_, filename);
  const auto& it = sound_buffers_.find(filepath);
  if (it != sound_buffers_.end()) {
    return it->second;
  }

  sf::SoundBuffer sound_buffer;
  if (!sound_buffer.loadFromFile(filepath)) {
    throw std::runtime_error("Cannot load sound buffer: " + filepath);
  }

  auto ret = sound_buffers_.emplace(filepath, std::move(sound_buffer));
  if (!ret.second) {
    throw std::runtime_error(fmt::format("Cannot insert buffer: {}", filepath));
  }

  return ret.first->second;
}

std::string AssetManager::ResourcesDirectory() {
  const auto* dir = std::getenv("RESOURCES_DIR");
  if (dir == nullptr) {
    return "";
  }

  return dir;
}