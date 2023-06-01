#include "catch.hpp"
#include "../src/TextureManager.h"
#define TEST
#include "../src/Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<vector>
#include<memory>


/**
 * WARNING! When running tests it is important to set correct environment path!
 */

TEST_CASE("Creating Player object", "[Player]") {
    auto texture = TextureManager();
    texture.insertTexture("test1", "resources/image.png");
    texture.insertTexture("test2", "resources/image.png");

    Player player(texture.getTexture("test1").get(), texture.getTexture("test2").get());
}

TEST_CASE("Set position - Get position", "[Player]") {
    auto texture = TextureManager();
    texture.insertTexture("test1", "resources/image.png");
    texture.insertTexture("test2", "resources/image.png");

    Player player(texture.getTexture("test1").get(), texture.getTexture("test2").get());

    REQUIRE_NOTHROW(player.setPosition(100, 100));
    REQUIRE(player.getPosition() == sf::Vector2f(100, 100));

    REQUIRE_NOTHROW(player.setPosition(-100, 50));
    REQUIRE(player.getPosition() == sf::Vector2f(-100, 50));

    REQUIRE_NOTHROW(player.setPosition(9999, 0));
    REQUIRE(player.getPosition() == sf::Vector2f(9999, 0));
}

TEST_CASE("Accessing private methods test", "[Player]") {
    auto texture = TextureManager();
    texture.insertTexture("test1", "resources/image.png");
    texture.insertTexture("test2", "resources/image.png");

    Player player(texture.getTexture("test1").get(), texture.getTexture("test2").get());
    player.setPosition(100, 100);
    REQUIRE(player._wallCollision == false);
}

std::unique_ptr<std::vector<Tile>> generateTileVector(int amount) {
    auto texture = TextureManager();
    texture.insertTexture("test1", "resources/image.png");
    auto vectorPointer = std::make_unique<std::vector<Tile>>();
    for(int i = 0; i < amount; i++) {
        vectorPointer->emplace_back(100, 20, 0, 100*i, texture.getTexture("test1").get());
    }
    return vectorPointer;
}


TEST_CASE("Intersect with Tile Vector", "[Player]") {
    auto texture = TextureManager();
    texture.insertTexture("test1", "resources/image.png");
    texture.insertTexture("test2", "resources/image.png");

    Player player(texture.getTexture("test1").get(), texture.getTexture("test2").get());

    auto vectorPointer = generateTileVector(10);
    player._velocity.y = 0.05;
    player.setPosition(30,150);
    player.intersectTileVector(*vectorPointer);
    REQUIRE(player._collision == false);
}

