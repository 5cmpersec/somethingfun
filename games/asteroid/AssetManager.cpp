#include "AssetManager.hpp"

AssetManager& AssetManager::getInstance() {
  static AssetManager instance;
  return instance;
}

sf::Texture& AssetManager::GetTexture(std::string_view filename) {
  const auto& it = m_Textures.find(filename);
  if (it != m_Textures.end()) {
    return it->second;
  } else {
    sf::Texture texture;
    if (!texture.loadFromFile(std::string(filename))) {
      throw std::runtime_error("Cannot load texture: " + std::string(filename));
    }
    m_Textures[filename] = texture;
    return m_Textures.at(filename);
  }
}