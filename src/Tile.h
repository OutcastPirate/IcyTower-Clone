#ifndef ICYTOWER_TILE_H
#define ICYTOWER_TILE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>


class Tile {
    /**
     * Tile class is used to generate platforms for the player to stand on.
     *
     */
public:
    Tile(float width, float height, float x, float y, sf::Texture *texture);
    /**
     * Tile - constructor of the Tile Class
     * @param width Width of the generated Tile
     * @param height Height of the generated Tile
     * @param x Horizontal offset of the generated Tile
     * @param y Vertical offset of the generated Tile
     * @param texture The Tile's texture
     *
     */
    void draw(sf::RenderWindow &window) const;
    /**
     * draw - allows to render the Tile object inside a window
     * @param windows Reference to a window in which the Tile is supposed to be displayed
     * 
     */
    sf::RectangleShape shape;
    /**
     * shape - base object used in creating the Tile instance taken from SFML library'
     * 
     */
    void updateTexture();
    /**
     * updateTexture() - allows to update the Tile's texture
     * 
     */
};


#endif //ICYTOWER_TILE_H
