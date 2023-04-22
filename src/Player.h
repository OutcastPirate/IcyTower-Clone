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
    Player(float speed, float jumpHeight, const int &gameWidth, const int &gameHeight, sf::Texture *leftTexture, sf::Texture *rightTexture);
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

    void intersectWalls(Tile& leftWall, Tile& rightWall);

    sf::Vector2f getPosition() const;

private:
    static sf::Vector3f getManifold(const sf::FloatRect& overlap, const sf::Vector2f& collisionNormal) ;
    void resolve(const sf::Vector3f& manifold);
    sf::Vector2f reflect(const sf::Vector2f& velocity, const sf::Vector2f& normal);
    float dot(const sf::Vector2f& lv, const sf::Vector2f& rv);
    sf::RectangleShape _body;

    sf::FloatRect _overlap;
    sf::FloatRect _bounds;

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

    sf::Texture *_leftTexture;
    sf::Texture *_rightTexture;
};


#endif  // ICYTOWER_PLAYER_H
