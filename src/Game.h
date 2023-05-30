//
// Created by pawel on 23.04.23.
//

#ifndef ICYTOWER_GAME_H
#define ICYTOWER_GAME_H
#define HIGHSCORE 0

#include "Player.h"
#include "Tile.h"
#include "TextureManager.h"

// Game constants.

const int gameWidth = 1000;
const int gameHeight = 900;


// To change environments comment unnecessary lines, and uncomment yours :)
//const std::string tilePath("resources/image.png");
//const std::string wallPath("resources/stoneWall.png");
//const std::string leftPlayerPath("resources/left.png");
//const std::string rightPlayerPath("resources/right.png");
//const std::string backgroundPath("resources/background.jpg");
//const std::string counterPath("resources/counterTexture.png");
//const std::string iconPath("resources/icon.png");
//const std::string fontPath("resources/Roboto.ttf");
//const std::string soundTrackPath("resources/sound_track.wav");


const std::string tilePath("C:/Programowanie/IcyTower/proi_projekt/resources/image.png");
const std::string wallPath("C:/Programowanie/IcyTower/proi_projekt/resources/stoneWall.png");
const std::string leftPlayerPath("C:/Programowanie/IcyTower/proi_projekt/resources/left.png");
const std::string rightPlayerPath("C:/Programowanie/IcyTower/proi_projekt/resources/right.png");
const std::string backgroundPath("C:/Programowanie/IcyTower/proi_projekt/resources/background.jpg");
const std::string counterPath("C:/Programowanie/IcyTower/proi_projekt/resources/counterTexture.png");
const std::string iconPath("C:/Programowanie/IcyTower/proi_projekt/resources/icon.png");
const std::string fontPath("C:/Programowanie/IcyTower/proi_projekt/resources/VT323-Regular.ttf");

class Game {
public:
    explicit Game(std::shared_ptr<sf::RenderWindow> window);

    bool isWindowOpen() const;

    void update();

    bool isPlayerOutOfScreen();

    int  highScore = 0;

private:
    static void setupTextures();

    void generateTiles();
    inline std::pair<int, int> getRandomTilePosition();
    void manageTiles();

    void drawEntities();

    void setScreen();


    float _deltaTime{0};
    std::shared_ptr<sf::RenderWindow> _window;
    sf::View _camera;

    std::vector<Tile> _tileVector;
    std::unique_ptr<Tile> _leftWall;
    std::unique_ptr<Tile> _rightWall;
    std::unique_ptr<Player> _player;

    sf::Sprite _backgroundSprite;
    sf::Sprite _counterSprite;
    sf::Font _font;
    sf::Text _scoreText;
    sf::Event _event{};
    std::unique_ptr<sf::Clock> _clock;
    sf::SoundBuffer soundTrack;
    sf::Sound sound;

    bool _paused{false};

    float _maxCameraPlacement{500};
    float _lastCameraPlacement{};
    unsigned int _textOffset{};
    int _currentFloor{0};
    int _gameLevel{0};
    int _lowestTileIndex{0};
    int _highestTilePositionY;
};


#endif //ICYTOWER_GAME_H
