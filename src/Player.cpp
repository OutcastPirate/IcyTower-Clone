//
// Created by pawel on 20.03.23.
//
#include "Player.h"
#include <cmath>
#include<iostream>


Player::Player(float speed, float jumpHeight, const int& gameWidth, const int& gameHeight) : _gameWidth(gameWidth), _gameHeight(gameHeight) {
  /**
   * Player class constructor
   * @param speed Possible Speed
   * @param jumpHeight Maximum jumping heigh
   */
  _speed = speed;
  _jumpHeight = jumpHeight;
  _facingRight = true;
  _canJump = true;
  _speedMultiply = 1.5;
  _body.setSize(sf::Vector2f(CHARACTER_WIDTH, CHARACTER_HEIGHT));
}

void Player::setPosition(int x, int y) { _body.setPosition(x, y); }

sf::Vector2f Player::getPosition() const { return _body.getPosition(); }


void Player::update(float deltaTime) {
  _velocity.x = 0.0f;
  sf::Vector2f pos = _body.getPosition();

  if (pos.x >= 0.0f && sf::Keyboard::isKeyPressed((sf::Keyboard::Left))) {
    float tmpSpeed = _speed * _speedMultiply;
    _velocity.x -= tmpSpeed;
  }
  // pos.x <= _gameWidth - 20
  // 20 is player width. Point (0,0) of player is on bottom left part of rectangle.
  if (pos.x <= _gameWidth - CHARACTER_WIDTH && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    float tmpSpeed = _speed * _speedMultiply;
    _velocity.x += tmpSpeed;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->_canJump) {
    _canJump = false;
    _isJumping = true;
    _velocity.y = -sqrtf(2.0f * 981.0f * this->_jumpHeight);
  }

  if (_isJumping || !_collision) {
    _velocity.y += 981.0f * deltaTime;
  }
  if(_collision && _velocity.y >= 0)
  {
      _canJump = true;
      _isJumping = false;
      _velocity.y = 0.0f;
//      setPosition(pos.x, shape.getPosition().y - shape.getSize().y);
  }
//  else if (pos.y > _gameHeight - CHARACTER_HEIGHT) {
//    _canJump = true;
//    _isJumping = false;
//    _velocity.y = 0.0f;
//    setPosition(pos.x, _gameHeight - CHARACTER_HEIGHT);
//  }

  _body.move(_velocity * deltaTime);
}

void Player::draw(sf::RenderWindow &window) { window.draw(_body); }

void Player::intersectTileVector(std::vector<Tile>& tileVector) {
    for(const auto& tile : tileVector)
    {
        if(_body.getGlobalBounds().intersects(tile.shape.getGlobalBounds()))
        {
            _collision = true;
            return;
        }
    }
    _collision = false;
}