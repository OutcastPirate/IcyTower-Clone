#include "catch.hpp"
#include "../src/TextureManager.h"
#define TEST
#include "../src/Tile.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


/**
 * WARNING! When running tests it is important to set correct environment path!
 */
TEST_CASE("Creating Tile Object", "[Tile]") {
    auto texture = TextureManager();
    texture.insertTexture("img1", "resources/image.png");

    Tile tile(100, 200, 0, 0, texture.getTexture("img1").get());
}

TEST_CASE("Tile parameter test", "[Tile]") {
    auto texture = TextureManager();
    texture.insertTexture("img1", "resources/image.png");

    Tile tile(100, 200, 0, 0, texture.getTexture("img1").get());
    REQUIRE(tile.shape.getPosition() == sf::Vector2f(0,0));
    REQUIRE(tile.shape.getSize() == sf::Vector2f(100,200));
}