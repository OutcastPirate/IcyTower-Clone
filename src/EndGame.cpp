#include "EndGame.h"
#include "Game.h"
#include<iostream>

EndGame::EndGame(std::shared_ptr<sf::RenderWindow> window, int score, int highScore) {
    this->window = window;
    this->_highScore = highScore;
    this->_score = score;
    setupTextures();
}

void EndGame::update() {
    handleInput();
    window->clear(sf::Color(0, 0, 0));
    window->draw(background);
    window->draw(scoreText);
    window->draw(highScoreText);
    for (auto& item : buttonVector) {
        item.draw(*window);
    }

    
    window->display();
}

void EndGame::handleInput() {
    // Process events
    sf::Event event{};
    while (window->pollEvent(static_cast<sf::Event&>(event))) {
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
            switch (event.key.code) {
            case sf::Keyboard::Up:
                buttonVector[selectedItem].changeState();
                selectedItem = (selectedItem + 1) % 2;
                buttonVector[selectedItem].changeState();
                break;
            case sf::Keyboard::Down:
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

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        auto mousePosition = sf::Mouse::getPosition(*window);
        auto translated_pos = window->mapPixelToCoords((mousePosition));

        for (auto& button : buttonVector)
        {
            if (button.sprite.getGlobalBounds().contains(translated_pos)) {
                button.changeState();
                selected = true;
                option = button.button_code;
                break;
            }
        }
    }
}

bool EndGame::optionSelected() {
    return selected;
}

void EndGame::setupTextures() {
    TextureManager::insertTexture("menu_background", backgroundPath);
    TextureManager::insertTexture("menu_button_play", playPath);
    TextureManager::insertTexture("menu_button_play_selected", playSelectedPath);
    TextureManager::insertTexture("menu_button_close", closePath);
    TextureManager::insertTexture("menu_button_close_selected", closeSelectedPath);

    background = sf::Sprite(*TextureManager::getTexture("menu_background"));
    background.setTextureRect({ 0,0, gameWidth, gameHeight });
    if (!font.loadFromFile(fontPath))
        std::cout << "Cannot load font" << std::endl;
    scoreText.setFont(font); // font is a sf::Font
    scoreText.setString("Score: " + std::to_string(_score));
    scoreText.setCharacterSize(70); // in pixels, not points!
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(300, 250);
    scoreText.setStyle(sf::Text::Bold);
    highScoreText.setFont(font); // font is a sf::Font
    highScoreText.setString("Highscore: " + std::to_string(_highScore));
    highScoreText.setCharacterSize(70); // in pixels, not points!
    highScoreText.setFillColor(sf::Color::White);
    highScoreText.setPosition(300, 150);
    highScoreText.setStyle(sf::Text::Bold);


    buttonVector.emplace_back(*TextureManager::getTexture("menu_button_play"), *TextureManager::getTexture("menu_button_play_selected"), 1);
    buttonVector[0].setPosition(300, 400);
    buttonVector.emplace_back(*TextureManager::getTexture("menu_button_close"), *TextureManager::getTexture("menu_button_close_selected"), -1);
    buttonVector[1].setPosition(300, 500);
    buttonVector[0].changeState();
}

int EndGame::getSelectedOption() {
    for (auto& button : buttonVector) {
        if (button.active)
        {
            option = button.button_code;
            break;
        }
    }
    return option;
}
