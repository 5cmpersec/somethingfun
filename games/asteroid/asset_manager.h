#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <map>
#include <string_view>

class AssetManager final : sf::NonCopyable {
 public:
  static AssetManager& Instance();
  sf::Texture& Texture(std::string_view filename);
  sf::Font& Font(std::string_view filename);
  sf::SoundBuffer& SoundBuffer(std::string_view filename);

 private:
  static std::string ResourcesDirectory();

 private:
  std::map<std::string, sf::Texture> textures_{};
  std::map<std::string, sf::Font> fonts_{};
  std::map<std::string, sf::SoundBuffer> sound_buffers_{};
  const std::string res_dir_{ResourcesDirectory()};
};
