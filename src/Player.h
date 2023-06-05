#ifndef ICYTOWER_PLAYER_H
#define ICYTOWER_PLAYER_H

#ifdef TEST
#define private public
#endif

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"
#include "GameSettings.h"



class Player {
    /**
     * Player class is used to keep main gameplay character position and texture. Also allows for managing it's physical
     * properties and location.
     */
public:
    Player(sf::Texture *leftTexture, sf::Texture *rightTexture);
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

    void setPosition(float x, float y);
    /**
     * Method that sets player position.
     * @param x, y - new relative (window) position
     */

    void draw(sf::RenderWindow &window);

    void intersectTileVector(const std::vector<Tile> &tileVector);
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
    /**
     * Method used to calculate manifold of 2 colliding objects. Manifold is then used for separating colliding objects,
     * if they are overlaped.
     * @param sf::FloatRect overlap used
     * @param sf::Vector2f collisionNormal
     * @return sf::Vector3f manifold - calculated manifold.
     */
    void resolve(const sf::Vector3f& manifold);
    /**
     * Resolves calculated manifold by moving player character out of colliding object.
     */

    float dot(const sf::Vector2f& lv, const sf::Vector2f& rv);
    /**
     * Dot product of 2 vectors. MAKO2 - v1 = (a,b) v2 = (c,d)
     * v1 dot v2 = a*c+b*d
     * @return Dot product of 2 passed vectors.
     */
    void horizontalAcceleration(bool accelerateRight);
    sf::Vector2f reflect(const sf::Vector2f& velocity, const sf::Vector2f& normal);
    sf::RectangleShape _body;

    sf::FloatRect _overlap;
    sf::FloatRect _bounds;
    sf::Vector2f _velocity;
    sf::Vector2f _energy{};
    float _maximumSpeed;
    float _jumpHeight;
    float _speedMultiply;
    bool _facingRight;
    bool _isJumping{};
    bool _canJump;
    bool _collision{};
    bool _wallCollision{};
    bool _canWalljump;


    sf::Texture *_leftTexture;
    sf::Texture *_rightTexture;
};


#endif  // ICYTOWER_PLAYER_H
