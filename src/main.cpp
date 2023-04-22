#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include "Player.h"
#include "Tile.h"
#include "TextureManager.h"
#include "Wall.h"

// To change environments comment unnecessary lines, and uncomment yours :)
const std::string tilePath("resources/image.png");
const std::string wallPath("resources/stoneWall.png");
const std::string leftPlayerPath("resources/left.png");
const std::string rightPlayerPath("resources/right.png");

//const std::string tilePath("C:/Programowanie/IcyTower/proi_projekt/resources/image.png");
//const std::string wallPath("C:/Programowanie/IcyTower/proi_projekt/resources/stoneWall.png");
//const std::string leftPlayerPath("C:/Programowanie/IcyTower/proi_projekt/resources/left.png");
//const std::string rightPlayerPath("C:/Programowanie/IcyTower/proi_projekt/resources/right.png");


int main() {
    srand(time(NULL));
    int tileHeight = 0;
    const int gameWidth = 1000;
    const int gameHeight = 900;
    auto textureManager = TextureManager();
    auto tileTexture = TextureManager::insertTexture("tile", tilePath);
    auto wallTexture = TextureManager::insertTexture("wall", wallPath);
    auto leftPlayerTexture = TextureManager::insertTexture("left", leftPlayerPath);
    auto rightPlayerTexture = TextureManager::insertTexture("right", rightPlayerPath);

    sf::View camera(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(gameWidth, gameHeight));

    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "Icy Tower",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(false);


    std::vector<Tile> tileVector;
    tileVector.emplace_back(1000, 200, 0, 850, tileTexture.get());
    for (int i = 0; i < 1000; i++) {
        int xPosition = 50 + (std::rand() % (750- 50 + 1));
        int width = 100 + (std::rand() % (400 - 100 + 1));
        if ((i + 1) % 50 == 0 && i != 100) {
            width = 1000;
            xPosition = 0;
        }
        tileVector.emplace_back(width, 30, xPosition, (750 - tileHeight), tileTexture.get());
        tileHeight += 100;
    }
    Player player(400, 450, gameWidth, gameHeight, leftPlayerTexture.get(), rightPlayerTexture.get());
    player.setPosition(500, 800);
    sf::Event event{};

    int maxCameraPlacement = 500;


    sf::Font font;
    if (!font.loadFromFile("resources/Roboto.ttf"))
    {
        std::cout << "Cannot load font" << std::endl;
    }
    sf::Text text;
    text.setFont(font); // font is a sf::Font
    text.setString("Hello world");
    text.setCharacterSize(24); // in pixels, not points!
    text.setFillColor(sf::Color::Red);

    Tile leftWall = Tile(50, 100000, 0, -99130, wallTexture.get());
    Tile rightWall = Tile(50, 100000, 950, -99130, wallTexture.get());

    sf::Clock clock;
    while (window.isOpen()) {
        window.clear(sf::Color(0, 0, 0));


        player.intersectTileVector(tileVector);
        player.intersectWalls(leftWall, rightWall);
        player.update(clock.restart().asSeconds());

        
        if (player.getPosition().y > maxCameraPlacement) {
            if (player.getPosition().y > (maxCameraPlacement + 500)) {
                window.close();
                std::cout << "Out of bounds" << std::endl;
            }
            camera.setCenter(sf::Vector2f(gameWidth / 2, maxCameraPlacement));
        } else {
            camera.setCenter(sf::Vector2f(gameWidth / 2, player.getPosition().y));
            maxCameraPlacement = player.getPosition().y;
        }
        
        // Set camera view;
        window.setView(camera);

        for (const auto &tile: tileVector) {
            tile.draw(window);
        }


        leftWall.draw(window);
        rightWall.draw(window);

        player.draw(window);
        window.draw(text);
        window.display();


        // Process events
        while (window.pollEvent(event)) {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return EXIT_SUCCESS;
}
