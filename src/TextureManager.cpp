//
// Created by pawel on 22.04.23.
//

#include "TextureManager.h"

std::map<std::string, std::shared_ptr<sf::Texture>> TextureManager::texturesMap;

std::shared_ptr<sf::Texture> TextureManager::insertTexture(std::string name, const std::string& texturePath) {
    auto texturePointer = std::make_shared<sf::Texture>();
    // Try to load texture.
    if(texturePointer->loadFromFile(texturePath))
    {
        // Loading successful
        texturesMap[name] = texturePointer;
        return texturePointer;
    } else {
        throw std::invalid_argument("Unable to load texture from given path.");
    }
}

std::shared_ptr<sf::Texture> TextureManager::getTexture(std::string name) const {
    if(texturesMap.find(name) != texturesMap.end())
        return texturesMap[name];
    else
        throw std::invalid_argument("Unable to find texture from given path.");
}
