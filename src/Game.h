#ifndef ICYTOWER_GAME_H
#define ICYTOWER_GAME_H
#define HIGHSCORE 0

#include "Player.h"
#include "Tile.h"
#include "TextureManager.h"
#include "FilePaths.h"
#include "GameSettings.h"



class Game {
    /**
     * Main Game class, keeps information about current game. Manages refreshing the screen, displaying
     * menus and keeping track of points.
     */
public:
    explicit Game(std::shared_ptr<sf::RenderWindow> window);
    /**
     * Game class explicit constructor.
     * @arg sf::RenderWindow pointer - passed pointer is used inside of the class as main window for displaying and
     * drawing the game.
     */

    bool isWindowOpen() const;

    void update();
    /**
     * Update method is used in a loop - calling this method redraws all objects and calculates their new position -
     * physics.
     */

    bool isPlayerOutOfScreen();

    int  highScore = 0;

private:
    static void setupTextures();

    void generateTiles();
    /**
     * Method that fills empty tileVector with freshly generated tile objects in a random position.
     */
    inline std::pair<int, int> getRandomTilePosition();
    /**
     * Helper method used for generating random tiles. Returns a pair of ints that are used for setting width
     * and x position of tiles.
     */
    void manageTiles();
    /**
     * This method checks player position and depending on y position moves not visible tiles from bottom to top,
     * changing theirs width and x position, so they seem pseudo-random.
     */

    void drawEntities();
    /**
     * Draws every defined texture on the screen.
     */

    void setScreen();
    /**
     * Sets camera object to center of character, moves camera with constant velocity.
     */


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
