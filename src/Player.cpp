//
// Created by pawel on 20.03.23.
//
#include "Player.h"
#include <cmath>
#include<iostream>


Player::Player(float speed, float jumpHeight, const int &gameWidth, const int &gameHeight) : _gameWidth(gameWidth),
                                                                                             _gameHeight(gameHeight) {
    _speed = speed;
    _jumpHeight = jumpHeight;
    _facingRight = true;
    _canJump = true;
    _speedMultiply = 1.5;
    _tmpSpeed = _speed * _speedMultiply;
    _body.setSize(sf::Vector2f(CHARACTER_WIDTH, CHARACTER_HEIGHT));
    _body.setOrigin(_body.getSize() / 2.0f);
}

void Player::setPosition(int x, int y) { _body.setPosition(x, y); }

sf::Vector2f Player::getPosition() const { return _body.getPosition(); }


void Player::update(float deltaTime) {
    _canJump = _collision;
    sf::Vector2f pos = _body.getPosition();
    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Left))) {
        _velocity.x = -_tmpSpeed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _velocity.x = _tmpSpeed;
    } else {
        if (_velocity.x > 0)
            _velocity.x -= 1900.0f * deltaTime;
        else if (_velocity.x < 0)
            _velocity.x += 1900.0f * deltaTime;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->_canJump) {
        _canJump = false;
        _isJumping = true;
        _velocity.y = -sqrtf(2.0f * 981.0f * this->_jumpHeight);
    }

    if (_isJumping || !_collision) {
        _velocity.y += 981.0f * deltaTime;
    }
    if (_collision && _velocity.y >= 0) {
        _canJump = true;
        _isJumping = false;
        _velocity.y = 0.0f;
    }
    _body.move(_velocity * deltaTime);
}

void Player::draw(sf::RenderWindow &window) { window.draw(_body); }

void Player::intersectTileVector(std::vector<Tile> &tileVector) {
    for (const auto &tile: tileVector) {
        if (_body.getGlobalBounds().intersects(tile.shape.getGlobalBounds())) {
            _collision = true;
            return;
        }
    }
    _collision = false;
}