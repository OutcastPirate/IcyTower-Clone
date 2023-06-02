//
// Created by pawel on 23.04.23.
//

#ifndef ICYTOWER_GAME_H
#define ICYTOWER_GAME_H
#define HIGHSCORE 0

#include "Player.h"
#include "Tile.h"
#include "TextureManager.h"
#include "FilePaths.h"
#include "GameSettings.h"



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
