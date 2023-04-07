//
// Created by pawel on 20.03.23.
//

#ifndef ICYTOWER_PLAYER_H
#define ICYTOWER_PLAYER_H

#include <SFML/Graphics.hpp>

const float GRAVITY = 0.5f;
const int CHARACTER_WIDTH = 20;
const int CHARACTER_HEIGHT = 40;

class Player{
 public:
    Player(float speed, float jumpHeight, const int &gameWidth, const int &gameHeight);
    void update(float deltaTime, sf::RectangleShape shape);
    void setPosition(int x, int y);
    void draw(sf::RenderWindow &window);
    sf::Vector2f getPosition() const;
 private:
    sf::RectangleShape _body;

    sf::Vector2f _velocity;
    const int& _gameWidth;
    const int& _gameHeight;
    float _speed;
    float _jumpHeight;
    float _speedMultiply;
    float maxJumpHeight = 200.0f;
    bool _facingRight;
    bool _isJumping;
    bool _canJump;
    bool _collision;
};



#endif  // ICYTOWER_PLAYER_H
