#include "EndGame.h"
#include "Game.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>


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
    window->draw(leftLogo);
    window->draw(rightLogo);

    for (auto& item : buttonVector) {
        item.draw(*window);
    }
    for (auto& item : scoreTextVector) {
        window->draw(item);
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
    
    leftLogo = sf::Sprite(*TextureManager::getTexture("menu_logo"));
    leftLogo.setTextureRect({ 0,0, 500, 500 });
    leftLogo.setScale({ 0.5, 0.5 });
    leftLogo.setPosition(15, 170);

    rightLogo = sf::Sprite(*TextureManager::getTexture("menu_logo"));
    rightLogo.setTextureRect({ 0,0, 500, 500 });
    rightLogo.setScale({ 0.5, 0.5 });
    rightLogo.setPosition(750, 170);

    buttonVector.emplace_back(*TextureManager::getTexture("menu_button_play"), *TextureManager::getTexture("menu_button_play_selected"), 1);
    buttonVector[0].setPosition(300, 350);
    buttonVector.emplace_back(*TextureManager::getTexture("menu_button_close"), *TextureManager::getTexture("menu_button_close_selected"), -1);
    buttonVector[1].setPosition(300, 450);
    buttonVector[0].changeState();

    updateScoreVector(scoreTablePath);
    setupHighScoreText();
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


std::vector<int> EndGame::getScoreVector(std::string fileName) {
    std::vector<int> scoreVector = {};
    std::ifstream fileReader;
    int score = 0;
    fileReader.open(fileName);
    for (int i = 0; i < 5; i++) {
        fileReader >> score;
        scoreVector.push_back(score);
    }
    fileReader.close();
    return scoreVector;
}


void EndGame::updateScoreVector(std::string fileName) {
    std::vector<int> scoreVector = getScoreVector(fileName);
    std::ofstream fileSaver;
    fileSaver.open(fileName);
    int tempScore = 0;
    int tempHigh = _score;
    for (int i = 0; i < 5; i++) {
        if (tempHigh == scoreVector[i]) {
            break;
        }
        if (tempHigh > scoreVector[i]) {
            tempScore = scoreVector[i];
            scoreVector[i] = tempHigh;
            tempHigh = tempScore;
        }
    }
    for (int i = 0; i < 5; i++) {
        fileSaver << scoreVector[i] << std::endl;
    }
    fileSaver.close();
}

void EndGame::setupHighScoreText() {
    if (!font.loadFromFile(fontPath))
        std::cout << "Cannot load font" << std::endl;
    scoreText.setFont(font); // font is a sf::Font
    scoreText.setString("SCORE: " + std::to_string(_score));
    scoreText.setCharacterSize(70); // in pixels, not points!
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(370, 150);
    scoreText.setStyle(sf::Text::Bold);
    highScoreText.setFont(font); // font is a sf::Font
    highScoreText.setString("HIGHSCORE: " + std::to_string(_highScore));
    highScoreText.setCharacterSize(70); // in pixels, not points!
    highScoreText.setFillColor(sf::Color::White);
    highScoreText.setPosition(300, 50);
    highScoreText.setStyle(sf::Text::Bold);
    std::vector<int> scoreVector = getScoreVector(scoreTablePath);
    sf::Text TitleScore;
    TitleScore.setFont(font); // font is a sf::Font
    TitleScore.setString("HIGHSCORE TABLE:");
    TitleScore.setCharacterSize(70);
    TitleScore.setFillColor(sf::Color::White);
    TitleScore.setPosition(270, 570 );
    TitleScore.setStyle(sf::Text::Bold);
    scoreTextVector.emplace_back(TitleScore);
    for (int i = 0; i < 5; i++) {
        sf::Text tempScore;
        tempScore.setFont(font); // font is a sf::Font
        tempScore.setString(std::to_string(i+1) + ". " + std::to_string(scoreVector[i]));
        tempScore.setCharacterSize(50);
        tempScore.setFillColor(sf::Color::White);
        tempScore.setPosition(440, 650 + (i*40));
        tempScore.setStyle(sf::Text::Bold);
        scoreTextVector.emplace_back(tempScore);
    }
}