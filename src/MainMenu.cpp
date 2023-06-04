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
    window->draw(gameLogo);
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
        {
            window->close();
            selected = true;
            option = -1;
            return;
        }

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
                case sf::Keyboard::Space :
                case sf::Keyboard::Return:
                    selected = true;
                    break;
                default:
                    break;
            }
        }
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        auto mousePosition = sf::Mouse::getPosition(*window);
        auto translated_pos = window->mapPixelToCoords((mousePosition));

        for(auto& button : buttonVector)
        {
            if(button.sprite.getGlobalBounds().contains(translated_pos)) {
                button.changeState();
                selected = true;
                option = button.button_code;
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
    TextureManager::insertTexture("menu_logo", logoPath);

    background = sf::Sprite(*TextureManager::getTexture("menu_background"));
    background.setTextureRect({0,0, gameWidth, gameHeight});

    gameLogo = sf::Sprite(*TextureManager::getTexture("menu_logo"));
    gameLogo.setTextureRect({0,0, 500, 500});
    gameLogo.setScale({0.8, 0.8});
    gameLogo.setPosition(300, 100);


    buttonVector.emplace_back(*TextureManager::getTexture("menu_button_play"), *TextureManager::getTexture("menu_button_play_selected"), 1);
    buttonVector[0].setPosition(300, 500);
    buttonVector.emplace_back(*TextureManager::getTexture("menu_button_close"), *TextureManager::getTexture("menu_button_close_selected"), -1);
    buttonVector[1].setPosition(300, 600);
    buttonVector[0].changeState();
}

int MainMenu::getSelectedOption() {
    for(auto& button : buttonVector){
        if(button.active)
        {
            option = button.button_code;
            break;
        }
    }
    return option;
}
