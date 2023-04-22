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
    _leftWall = false;
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
        if (_body.getGlobalBounds().left <= 50) {
            _velocity.x = 0;
        }
        else {
            _velocity.x = -_tmpSpeed;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (_body.getGlobalBounds().left >= 930) {
            _velocity.x = 0;
        }
        else {
            _velocity.x = _tmpSpeed;
        }
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
        _velocity.y += 2137.0f * deltaTime;
    }
    if (_collision && _velocity.y >= 0) {
        _canJump = true;
        _isJumping = false;
        _velocity.y = 0.0f;
    }
    _body.move(_velocity * deltaTime);
}

void Player::draw(sf::RenderWindow &window) { window.draw(_body); }

sf::Vector3f Player::getManifold(const sf::FloatRect& overlap, const sf::Vector2f& collisionNormal)
{
    //the collision normal is stored in x and y, with the penetration in z
    sf::Vector3f manifold;

    if (overlap.width < overlap.height)
    {
        manifold.x = (collisionNormal.x < 0) ? 1.f : -1.f;
        manifold.z = overlap.width;
    }
    else
    {
        manifold.y = (collisionNormal.y < 0) ? 1.f : -1.f;
        manifold.z = overlap.height;
    }

    return manifold;
}

void Player::resolve(const sf::Vector3f& manifold)
{
    // Move player body out of solid object (tile or wall).
    sf::Vector2f normal(manifold.x, manifold.y);
    _body.move(normal * manifold.z);
}


void Player::intersectTileVector(std::vector<Tile> &tileVector) {
    _bounds = _body.getGlobalBounds();

    for (const auto &tile: tileVector) {
        if (tile.shape.getGlobalBounds().intersects(_bounds, _overlap) && _velocity.y > 0.0f) {
            auto collisionNormal = tile.shape.getPosition() - _body.getPosition();
            auto manifold = getManifold(_overlap, collisionNormal);
            resolve(manifold);
            _collision = true;
            return;
        }
    }
    if (_body.getGlobalBounds().left == 50) {
        _leftWall = true;
        return;
    }
    _collision = false;
}

