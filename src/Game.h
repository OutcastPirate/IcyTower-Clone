//
// Created by pawel on 23.04.23.
//

#ifndef ICYTOWER_GAME_H
#define ICYTOWER_GAME_H

#include "Player.h"
#include "Tile.h"
#include "TextureManager.h"

// Game constants.

const int gameWidth = 1000;
const int gameHeight = 900;


// To change environments comment unnecessary lines, and uncomment yours :)
const std::string tilePath("resources/image.png");
const std::string wallPath("resources/stoneWall.png");
const std::string leftPlayerPath("resources/left.png");
const std::string rightPlayerPath("resources/right.png");
const std::string backgroundPath("resources/background.jpg");
const std::string counterPath("resources/counterTexture.png");
const std::string fontPath("resources/Roboto.ttf");


//const std::string tilePath("C:/Programowanie/IcyTower/proi_projekt/resources/image.png");
//const std::string wallPath("C:/Programowanie/IcyTower/proi_projekt/resources/stoneWall.png");
//const std::string leftPlayerPath("C:/Programowanie/IcyTower/proi_projekt/resources/left.png");
//const std::string rightPlayerPath("C:/Programowanie/IcyTower/proi_projekt/resources/right.png");
//const std::string backgroundPath("C:/Programowanie/IcyTower/proi_projekt/resources/background.jpg");
//const std::string counterPath("C:/Programowanie/IcyTower/proi_projekt/resources/counterTexture.png");
//const std::string fontPath("C:/Programowanie/IcyTower/proi_projekt/resources/Roboto.ttf");

class Game {
public:
    Game();

    bool isWindowOpen() const;

    void update();

private:
    static void setupTextures();

    void generateTiles();

    void drawEntities();

    void setScreen();

    bool isPlayerOutOfScreen();

    float _deltaTime{0};
    std::unique_ptr<sf::RenderWindow> _window;
    sf::View _camera;

    std::vector<Tile> _tileVector;
    std::unique_ptr<Tile> _leftWall;
    std::unique_ptr<Tile> _rightWall;
    std::unique_ptr<Player> _player;

    sf::Sprite _backgroundSprite;
    sf::Sprite _counterSprite;
    sf::Font _font;
    sf::Text _scoreText;
    sf::Event _event;
    std::unique_ptr<sf::Clock> _clock;

    bool _paused{false};

    float _maxCameraPlacement{500};
    float _lastCameraPlacement;
    unsigned int _textOffset;
    int currentFloor{0};
};


#endif //ICYTOWER_GAME_H
