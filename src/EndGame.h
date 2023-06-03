//
// Created by pawel on 01.05.23.
//

#ifndef ICYTOWER_ENDGAME_H
#define ICYTOWER_ENDGAME_H
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <string>
#include "TextureManager.h"
#include "FilePaths.h"
#include "UIButton.h"
#include "MainMenu.h"



class EndGame {
public:
    EndGame(std::shared_ptr<sf::RenderWindow> window, int score, int highScore);
    void update();
    bool optionSelected();
    int getSelectedOption();
    int option{ 0 };
    //bool gameContinue = false;
private:
    void setupTextures();
    void handleInput();
    std::vector<int> getScoreVector(std::string fileName);
    void updateScoreVector(std::string fileName);
    void setupHighScoreText();
    unsigned int selectedItem{ 0 };
    sf::Sprite background;
    sf::Sprite leftLogo;
    sf::Sprite rightLogo;
    std::vector<UIButton> buttonVector;
    std::vector<sf::Text> scoreTextVector;
    std::shared_ptr<sf::RenderWindow> window;
    sf::Text scoreText;
    sf::Text highScoreText;
    bool selected{ false };
    sf::Font font;
    int _score;
    int _highScore;
};


#endif //ICYTOWER_ENDGAME_H
