//
// Created by pawel on 12.04.23.
//

#ifndef ICYTOWER_TILE_H
#define ICYTOWER_TILE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>


class Tile {
public:
    Tile(float width, float height, float x, float y, sf::Texture *texture);
    void draw(sf::RenderWindow &window) const;
    sf::RectangleShape shape;
};


#endif //ICYTOWER_TILE_H
