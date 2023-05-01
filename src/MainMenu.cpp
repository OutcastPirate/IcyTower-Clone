//
// Created by pawel on 01.05.23.
//

#include "MainMenu.h"
#include "Game.h"
#include<iostream>

MainMenu::MainMenu(std::shared_ptr<sf::RenderWindow> window) {
    this->window = window;
    setupTextures();
}

void MainMenu::update() {
    handleInput();
    window->clear(sf::Color(0, 0, 0));
    window->draw(background);
    for(auto &item : buttonVector) {
        item.draw(*window);
    }
    window->display();
}

void MainMenu::handleInput() {
    // Process events
    sf::Event event{};
    while (window->pollEvent(static_cast<sf::Event &>(event))) {
        // Close window : exit
        if (event.type == sf::Event::Closed)
            window->close();

        if (event.type == sf::Event::KeyPressed)
        {
            switch(event.key.code) {
                case sf::Keyboard::Up :
                    buttonVector[selectedItem].changeState();
                    selectedItem = (selectedItem + 1) % 2;
                    buttonVector[selectedItem].changeState();
                    break;
                case sf::Keyboard::Down :
                    buttonVector[selectedItem].changeState();
                    selectedItem = (selectedItem - 1) % 2;
                    buttonVector[selectedItem].changeState();
                    break;
                case sf::Keyboard::Return :
                    selected = true;
                    break;
                default:
                    break;
            }
        }
    }
}

bool MainMenu::optionSelected() {
    return selected;
}

void MainMenu::setupTextures() {
    TextureManager::insertTexture("menu_background", backgroundPath);
    TextureManager::insertTexture("menu_button_play", playPath);
    TextureManager::insertTexture("menu_button_play_selected", playSelectedPath);
    TextureManager::insertTexture("menu_button_close", closePath);
    TextureManager::insertTexture("menu_button_close_selected", closeSelectedPath);

    background = sf::Sprite(*TextureManager::getTexture("menu_background"));
    background.setTextureRect({0,0, gameWidth, gameHeight});



    buttonVector.emplace_back(*TextureManager::getTexture("menu_button_play"), *TextureManager::getTexture("menu_button_play_selected"));
    buttonVector[0].setPosition(100, 200);
    buttonVector[0].changeState();
    buttonVector.emplace_back(*TextureManager::getTexture("menu_button_close"), *TextureManager::getTexture("menu_button_close_selected"));
    buttonVector[1].setPosition(100, 300);
}
