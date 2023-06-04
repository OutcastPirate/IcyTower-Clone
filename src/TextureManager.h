#ifndef ICYTOWER_TEXTUREMANAGER_H
#define ICYTOWER_TEXTUREMANAGER_H
#include <SFML/Graphics.hpp>
#include <memory>
#include <map>
#include <string>


class TextureManager {
    /**
     * TextureManager class allows for keeping all textures in one place, and using them in game;
     * loading necessary textures only at the start of the game speeds up runtime and decreases loading errors.
     *
     * All texture pointers are kept in a map - allowing for constant time access.
     */
public:
    TextureManager() = default;
    static std::shared_ptr<sf::Texture> insertTexture(std::string name, const std::string& texturePath);
    /**
     * insertTexture - allows for adding new textures to collection
     * @param name Name of the texture - later used to access texture
     * @param texturePath Path - absolute or relative to the texture file location
     * @return std::shared_ptr pointing to newly created texture object.
     *
     * @warning Method changes contents of texture object if the same name is reused!
     */


    // nodiscard - following method is pure; so if the result is not used - call wouldn't be made.
    [[nodiscard]]
    static std::shared_ptr<sf::Texture> getTexture(std::string name) ;
    /**
     * Texture pointer getter.
     * @param name Name of the texture to access.
     * @return std::shared_ptr pointing to texture object with given name.
     */
private:
    static std::map<std::string, std::shared_ptr<sf::Texture>> texturesMap;
};


#endif //ICYTOWER_TEXTUREMANAGER_H
