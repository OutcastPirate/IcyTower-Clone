#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "Player.h"
#include "Tile.h"
#include "TextureManager.h"
#include "Wall.h"

// To change environments comment unnecessary lines, and uncomment yours :)
//const std::string tilePath("resources/image.png");
//const std::string wallPath("resources/stoneWall.png");
//const std::string leftPlayerPath("resources/left.png");
//const std::string rightPlayerPath("resources/right.png");
//const std::string backgroundPath("resources/background.jpg");
//const std::string counterPath("resources/counterTexture.png");


const std::string tilePath("C:/Programowanie/IcyTower/proi_projekt/resources/image.png");
const std::string wallPath("C:/Programowanie/IcyTower/proi_projekt/resources/stoneWall.png");
const std::string leftPlayerPath("C:/Programowanie/IcyTower/proi_projekt/resources/left.png");
const std::string rightPlayerPath("C:/Programowanie/IcyTower/proi_projekt/resources/right.png");
const std::string backgroundPath("C:/Programowanie/IcyTower/proi_projekt/resources/background.jpg");
const std::string counterPath("C:/Programowanie/IcyTower/proi_projekt/resources/counterTexture.png");


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
    auto backgroundTexture = TextureManager::insertTexture("background", backgroundPath);
    auto counterTexture = TextureManager::insertTexture("background", counterPath);


    sf::View camera(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(gameWidth, gameHeight));

    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "Icy Tower",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(false);

    // Background setup
    sf::Sprite background;
    backgroundTexture->setRepeated(true);
    background.setTexture(*backgroundTexture);
    background.setTextureRect({0,0,gameWidth, gameHeight * 30});
    background.setPosition({0,-gameHeight*27});

    // Setting up tiles
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
    Player player(leftPlayerTexture.get(), rightPlayerTexture.get());
    player.setPosition(500.0f, 800.0f);

    sf::Event event{};
    float maxCameraPlacement = 500;
    sf::Font font;
    //if (!font.loadFromFile("resources/Roboto.ttf"))
    if (!font.loadFromFile("C:/Programowanie/IcyTower/proi_projekt/resources/Roboto.ttf"))

    {
        std::cout << "Cannot load font" << std::endl;
    }
    sf::Text text;
    text.setFont(font); // font is a sf::Font
    text.setString("0"); 
    text.setCharacterSize(32); // in pixels, not points!
    text.setFillColor(sf::Color::Red);

    Tile leftWall = Tile(50, 100000, 0, -99130, wallTexture.get());
    Tile rightWall = Tile(50, 100000, 950, -99130, wallTexture.get());
    Tile floorCounter = Tile(90, 90, 50, 650, counterTexture.get());
    int currentFloor = 0;

    
    
    sf::Clock clock;
    while (window.isOpen()) {
        window.clear(sf::Color(0, 0, 0));
        window.draw(background);

        player.intersectTileVector(tileVector);
        player.intersectWalls(leftWall, rightWall);
        player.update(clock.restart().asSeconds());

        auto lastCamera = maxCameraPlacement;
        if (player.getPosition().y > maxCameraPlacement) {
            if (player.getPosition().y > (maxCameraPlacement + 500)) {
                window.close();
                std::cout << "Out of bounds" << std::endl;
            }
            camera.setCenter(sf::Vector2f(static_cast<float>(gameWidth) / 2, maxCameraPlacement));
            floorCounter = Tile(90, 90, 60, (maxCameraPlacement - 430), counterTexture.get());
            int textOffset = 10 * (std::to_string(currentFloor).length());
            text.setPosition((110 - textOffset), (maxCameraPlacement - 405));
            currentFloor = (-1) * ((int(player.getPosition().y) - 831) / 100);
            text.setString(std::to_string(currentFloor));
        }
        else {
            camera.setCenter(sf::Vector2f(static_cast<float>(gameWidth) / 2, player.getPosition().y));
            maxCameraPlacement = player.getPosition().y;
            floorCounter = Tile(90, 90, 60, (maxCameraPlacement - 430), counterTexture.get());
            int textOffset = 10 * (std::to_string(currentFloor).length());
            text.setPosition((110 - textOffset), (maxCameraPlacement - 405));
            currentFloor = (-1) * ((int(player.getPosition().y) - 831) / 100);
            text.setString(std::to_string(currentFloor));
            if (maxCameraPlacement != lastCamera) {            
            background.setPosition({ 0, background.getPosition().y + (maxCameraPlacement - lastCamera) / 2 });
            }
        }
        
        // Set camera view;
        window.setView(camera);

        for (const auto &tile: tileVector) {
            tile.draw(window);
        }


        leftWall.draw(window);
        rightWall.draw(window);
        floorCounter.draw(window);
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


//void counterSetup() {
//    floorCounter = Tile(90, 90, 60, (maxCameraPlacement - 430), counterTexture.get());
//    int textOffset = 10 * (std::to_string(currentFloor).length());
//    text.setPosition((110 - textOffset), (maxCameraPlacement - 405));
//    currentFloor = (-1) * ((int(player.getPosition().y) - 831) / 100);
//    text.setString(std::to_string(currentFloor));
//}