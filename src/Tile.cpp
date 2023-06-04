#include "Tile.h"

Tile::Tile(float width, float height, float x, float y, sf::Texture *texture) {
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    texture->setRepeated(true);
    auto textureRect = sf::Rect<int>(0, 0, width, height);
    shape.setTextureRect(textureRect);
    shape.setTexture(texture);
}

void Tile::draw(sf::RenderWindow &window) const {
    window.draw(shape);
}

void Tile::updateTexture() {
    auto textureRect = sf::Rect<int>(0, 0, shape.getSize().x, shape.getSize().y);
    shape.setTextureRect(textureRect);
}
