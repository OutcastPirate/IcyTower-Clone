//
// Created by pawel on 23.04.23.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

#include "Game.h"


Game::Game() {
    // Setting up render window.
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    _window = std::make_unique<sf::RenderWindow>(sf::VideoMode(gameWidth, gameHeight, 32), "Icy Tower",
                                                 sf::Style::Titlebar | sf::Style::Close, settings);
    _window->setVerticalSyncEnabled(false);

    // Starting game clock.
    _clock = std::make_unique<sf::Clock>();

    // Setting up camera
    _camera = sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(gameWidth, gameHeight));


    setupTextures();
    generateTiles();

    // Loading font.
    if (!_font.loadFromFile(fontPath))
        std::cout << "Cannot load font" << std::endl;

    // Setting up player
    _player = std::make_unique<Player>(TextureManager::getTexture("left").get(),
                                       TextureManager::getTexture("right").get());
    _player->setPosition(500.0f, 800.0f);

    // Background setup
    _backgroundSprite.setTexture(*TextureManager::getTexture("background"));
    _backgroundSprite.setTextureRect({0, 0, gameWidth, gameHeight * 30});
    _backgroundSprite.setPosition({0, -gameHeight * 27});

    // Setup score counter.
    _counterSprite.setTexture(*TextureManager::getTexture("counter"));
    _counterSprite.setTextureRect({0, 0, 90, 90});
    _counterSprite.setPosition({50, 650});
    _scoreText.setFont(_font); // font is a sf::Font
    _scoreText.setString("0");
    _scoreText.setCharacterSize(32); // in pixels, not points!
    _scoreText.setFillColor(sf::Color::Red);
}

bool Game::isWindowOpen() const {
    return _window->isOpen();
}

void Game::update() {
    _deltaTime = _clock->restart().asSeconds();
    _window->clear(sf::Color(0, 0, 0));

    _player->intersectTileVector(_tileVector);
    _player->intersectWalls(*_leftWall, *_rightWall);
    _player->update(_deltaTime);

    // Set camera view;
    _window->setView(_camera);

    drawEntities();
    setScreen();

    //Handle player out of screen.
    if (isPlayerOutOfScreen()) {
        std::cout << "Out of bounds" << std::endl;
        _window->close();
    }

    // Process events
    while (_window->pollEvent(static_cast<sf::Event &>(_event))) {
        // Close window : exit
        if (_event.type == sf::Event::Closed)
            _window->close();
    }

}

void Game::setupTextures() {
    TextureManager::insertTexture("tile", tilePath);
    TextureManager::insertTexture("wall", wallPath);
    TextureManager::insertTexture("left", leftPlayerPath);
    TextureManager::insertTexture("right", rightPlayerPath);
    TextureManager::insertTexture("background", backgroundPath);
    TextureManager::insertTexture("counter", counterPath);
}

void Game::generateTiles() {
    // Setting up tiles
    int tileHeight = 0;
    _tileVector.emplace_back(1000, 200, 0, 850, TextureManager::getTexture("tile").get());
    for (int i = 0; i < 1000; i++) {
        int xPosition = 50 + (std::rand() % (750 - 50 + 1));
        int width = 100 + (std::rand() % (400 - 100 + 1));
        if ((i + 1) % 50 == 0 && i != 100) {
            width = 1000;
            xPosition = 0;
        }
        _tileVector.emplace_back(width, 30, xPosition, (750 - tileHeight), TextureManager::getTexture("tile").get());
        tileHeight += 100;
    }
    // Setting up left and right walls.
    _leftWall = std::make_unique<Tile>(50, 100000, 0, -99130, TextureManager::getTexture("wall").get());
    _rightWall = std::make_unique<Tile>(50, 100000, 950, -99130, TextureManager::getTexture("wall").get());
}

void Game::drawEntities() {
    _window->draw(_backgroundSprite);
    _leftWall->draw(*_window);
    _rightWall->draw(*_window);

    for (const auto &tile: _tileVector) {
        tile.draw(*_window);
    }

    _player->draw(*_window);
    _window->draw(_scoreText);
    _window->draw(_counterSprite);

    _window->display();
}

void Game::setScreen() {
    _lastCameraPlacement = _maxCameraPlacement;
    currentFloor = (-1) * ((int(_player->getPosition().y) - 831) / 100);
    _textOffset = 10 * (std::to_string(currentFloor).length());
    _scoreText.setString(std::to_string(currentFloor));
    _scoreText.setPosition(static_cast<float>(110 - _textOffset), (_maxCameraPlacement - 405));
    _counterSprite.setPosition(60, _maxCameraPlacement - 430);

    if (_player->getPosition().y > _maxCameraPlacement) {
        _camera.setCenter(sf::Vector2f(static_cast<float>(gameWidth) / 2, _maxCameraPlacement));
    } else {
        _camera.setCenter(sf::Vector2f(static_cast<float>(gameWidth) / 2, _player->getPosition().y));
        _maxCameraPlacement = _player->getPosition().y;
        if (_maxCameraPlacement != _lastCameraPlacement) {
            _backgroundSprite.setPosition(
                    {0, _backgroundSprite.getPosition().y + (_maxCameraPlacement - _lastCameraPlacement) / 2});
        }
    }
}

bool Game::isPlayerOutOfScreen() {
    return (_player->getPosition().y > (_maxCameraPlacement + 500));
}
