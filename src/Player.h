//
// Created by pawel on 20.03.23.
//

#ifndef ICYTOWER_PLAYER_H
#define ICYTOWER_PLAYER_H

#include <SFML/Graphics.hpp>

const float GRAVITY = 0.5f;
const int CHARACTER_WIDTH = 20;
const int CHARACTER_HEIGHT = 20;
const int JUMP_HEIGHT = 250;

class Player{
public:
    Player(float switchTime, float speed, float jumpHeight);
    void update(float deltaTime);
    void setPosition(int x, int y);
    void draw(sf::RenderWindow &window);
    sf::Vector2f getPosition();
private:
    sf::RectangleShape _body;

    sf::Vector2f _velocity;
    float _speed;
    float _jumpHeight;
    float _speedMultiply;
    bool _facingRight;
    bool _isJumping;
    bool _canJump;
};



#endif //ICYTOWER_PLAYER_H
