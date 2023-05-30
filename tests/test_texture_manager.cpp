#include "catch.hpp"
#include "../src/TextureManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/**
 * WARNING! When running tests it is important to set correct environment path!
 */
TEST_CASE("Loading texture", "[TextureManager]") {
    auto texture = TextureManager();
    texture.insertTexture("example1", "resources/image.png");
}

TEST_CASE("Loading non existent texture", "[TextureManager]") {
    auto texture = TextureManager();
    REQUIRE_THROWS(texture.insertTexture("example2", "resources/thereIsNoImageWithThisName.png"));
}

TEST_CASE("Getting texture", "[TextureManager]") {
    auto texture = TextureManager();
    texture.insertTexture("example1", "resources/image.png");
    REQUIRE(texture.getTexture("example1") != nullptr);
}

TEST_CASE("Getting non existent texture", "[TextureManager]") {
    auto texture = TextureManager();
    REQUIRE_THROWS(texture.getTexture("example1"));
}

TEST_CASE("Getting multiple textures", "[TextureManager]") {
    auto texture = TextureManager();
    texture.insertTexture("test1", "resources/image.png");
    texture.insertTexture("test2", "resources/menu_play.jpg");
    texture.insertTexture("test3", "resources/right.png");
    REQUIRE(texture.getTexture("test1") != nullptr);
    REQUIRE(texture.getTexture("test2") != nullptr);
    REQUIRE(texture.getTexture("test3") != nullptr);
}
