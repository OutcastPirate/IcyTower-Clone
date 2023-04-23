//
// Created by pawel on 20.03.23.
//
#include "Player.h"
#include <cmath>
#include<iostream>


Player::Player(sf::Texture *leftTexture, sf::Texture *rightTexture) {
    _speed = SPEED;
    _jumpHeight = JUMP_HEIGHT;
    _facingRight = true;
    _canJump = true;
    _speedMultiply = 1.5;
    _tmpSpeed = _speed * _speedMultiply;
    _body.setSize(sf::Vector2f(CHARACTER_WIDTH, CHARACTER_HEIGHT));
    _body.setOrigin(_body.getSize() / 2.0f);

    _leftTexture = leftTexture;
    _rightTexture = rightTexture;
}

void Player::setPosition(float x, float y) { _body.setPosition(x, y); }

sf::Vector2f Player::getPosition() const { return _body.getPosition(); }

float Player::dot(const sf::Vector2f &lv, const sf::Vector2f &rv) {
    return lv.x * rv.x + lv.y * rv.y;
}

sf::Vector2f Player::reflect(const sf::Vector2f &velocity, const sf::Vector2f &normal) {
    return -2.f * dot(velocity, normal) * normal + velocity;
}

void Player::update(float deltaTime) {
    _canJump = _collision;
    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Left))) {
            _velocity.x = -_tmpSpeed;
            _facingRight = false;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            _velocity.x = _tmpSpeed;
            _facingRight = true;
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


    if(_facingRight){
        _body.setTexture(_rightTexture);
    } else {
        _body.setTexture(_leftTexture);
    }
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
    auto bottomPosition = _body.getPosition();
    bottomPosition.y -= static_cast<float>(CHARACTER_HEIGHT) / 2;

    for (const auto &tile: tileVector) {
        if (bottomPosition.y < tile.shape.getPosition().y && tile.shape.getGlobalBounds().intersects(_bounds, _overlap) && _velocity.y > 0.0f) {
            auto collisionNormal = tile.shape.getPosition() - _body.getPosition();
            auto manifold = getManifold(_overlap, collisionNormal);
            resolve({0, manifold.y, manifold.z});

            _collision = true;
            return;
        }
    }
    _collision = false;
}

void Player::intersectWalls(Tile &leftWall, Tile &rightWall) {
    _bounds = _body.getGlobalBounds();
    sf::Vector2f collisionNormal;
    if(leftWall.shape.getGlobalBounds().intersects(_bounds, _overlap)) {
        collisionNormal = leftWall.shape.getPosition() - _body.getPosition();
    } else if (rightWall.shape.getGlobalBounds().intersects(_bounds, _overlap)) {
        collisionNormal = rightWall.shape.getPosition() - _body.getPosition();
    } else {
        return;
    }

    auto manifold = getManifold(_overlap, collisionNormal);
    resolve(manifold);
    _velocity = reflect(_velocity, {manifold.x, -manifold.y});
}


