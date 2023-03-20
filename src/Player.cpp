//
// Created by pawel on 20.03.23.
//
#include <cmath>
#include "Player.h"

Player::Player(float switchTime, float speed, float jumpHeight)
{
    _speed = speed;
    _jumpHeight = jumpHeight;
    _facingRight = true;
    _canJump = true;
    _speedMultiply = 1.5;
    _body.setSize(sf::Vector2f(20, 40));
}

void Player::setPosition(int x, int y) {
    _body.setPosition(x, y);
}

sf::Vector2f Player::getPosition() {
    return _body.getPosition();
}

void Player::update(float deltaTime) {
    _velocity.x = 0.0f;
    sf::Vector2f pos = _body.getPosition();

    float maxJumpHeight = 200.0f;

    if(pos.x >= 0.0f && sf::Keyboard::isKeyPressed((sf::Keyboard::Left)))
    {
        float tmpSpeed = _speed * _speedMultiply;
        _velocity.x -= tmpSpeed;
    }
    if (pos.x <= 624.0f && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        float tmpSpeed = _speed * _speedMultiply;
        _velocity.x += tmpSpeed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->_canJump) {
        _canJump = false;
        _isJumping = true;
        _velocity.y = -sqrtf(2.0f * 981.0f * this->_jumpHeight);
    }

    if (_isJumping) {
        _velocity.y += 981.0f * deltaTime;
    }

    if (pos.y > 435.0f) {
        _canJump = true;
        _isJumping = false;
        _velocity.y = 0.0f;
        setPosition(pos.x, 435);
    }

    _body.move(_velocity * deltaTime);
}

void Player::draw(sf::RenderWindow &window)
{
    window.draw(_body);
}