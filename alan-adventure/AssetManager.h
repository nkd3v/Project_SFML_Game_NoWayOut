#pragma once

class AssetManager
{
private:

  std::map<std::string, sf::Texture> textures;
  std::map<std::string, sf::Font> fonts;
  std::map<std::string, sf::SoundBuffer> soundBuffers;

public:

  void loadTexture(const std::string& key, const std::string& filename);
  void loadFont(const std::string& key, const std::string& filename);
  void loadSoundBuffer(const std::string& key, const std::string& filename);

  sf::Texture& getTexture(const std::string & key);
  sf::Font& getFont(const std::string& key);
  sf::SoundBuffer& getSoundBuffer(const std::string& key);
};

extern AssetManager am;