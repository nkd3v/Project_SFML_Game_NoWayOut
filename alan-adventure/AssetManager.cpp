#include "stdafx.h"
#include "AssetManager.h"

void AssetManager::loadTexture(const std::string& key, const std::string& filename)
{
  if (textures.find(key) != textures.end())
    return;

  if (!textures[key].loadFromFile(filename))
    throw;
}

void AssetManager::loadFont(const std::string& key, const std::string& filename)
{
  if (fonts.find(key) != fonts.end())
    return;

  if (!fonts[key].loadFromFile(filename))
    throw;
}

void AssetManager::loadSoundBuffer(const std::string& key, const std::string& filename)
{
  if (soundBuffers.find(key) != soundBuffers.end())
    return;

  if (!soundBuffers[key].loadFromFile(filename))
    throw;
}

void AssetManager::loadImage(const std::string& key, const std::string& filename)
{
  if (images.find(key) != images.end())
    return;

  if (!images[key].loadFromFile(filename))
    throw;
}

sf::Texture& AssetManager::getTexture(const std::string & key)
{
  if (textures.find(key) == textures.end())
    throw;

  return textures[key];
}

sf::Font& AssetManager::getFont(const std::string& key)
{
  if (fonts.find(key) == fonts.end())
    throw;

  return fonts[key];
}

sf::SoundBuffer& AssetManager::getSoundBuffer(const std::string& key)
{
  if (soundBuffers.find(key) == soundBuffers.end())
    throw;

  return soundBuffers[key];
}

sf::Image& AssetManager::getImage(const std::string& key)
{
  if (images.find(key) == images.end())
    throw;

  return images[key];
}

AssetManager am;