//
// Created by pawel on 20.03.23.
//

#ifndef ICYTOWER_PLAYER_H
#define ICYTOWER_PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

const float GRAVITY = 0.5f;
const int CHARACTER_WIDTH = 20;
const int CHARACTER_HEIGHT = 40;

class Player {
public:
    Player(float speed, float jumpHeight, const int &gameWidth, const int &gameHeight);
    /**
     *  Player class constructor
     *  @param speed Possible Speed
     *  @param jumpHeight Maximum jumping height
    */
    void update(float deltaTime);
    /**
     * This method applies physics to the character.
     * @param deltaTime Parameter needed to calculate proper acceleration.
     * @brief Updating all physics parameters.
     */

    void setPosition(int x, int y);

    void draw(sf::RenderWindow &window);

    void intersectTileVector(std::vector<Tile> &tileVector);
    /**
     * @param tileVector std::vector of Tile objects.
     *
     * @brief This method takes tileVector and checks whether Player character
     * is intersecting - colliding with any of Tile objects inside of tileVector
     * and sets up _collides boolean value accordingly.
     */

    sf::Vector2f getPosition() const;

private:
    sf::RectangleShape _body;

    sf::Vector2f _velocity;
    const int &_gameWidth;
    const int &_gameHeight;
    float _speed;
    float _tmpSpeed;
    float _jumpHeight;
    float _speedMultiply;
    float maxJumpHeight = 300.0f;
    bool _facingRight;
    bool _isJumping{};
    bool _canJump;
    bool _leftWall;
    bool _collision{};
};


#endif  // ICYTOWER_PLAYER_H
