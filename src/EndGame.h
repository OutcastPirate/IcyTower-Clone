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
#include "UIButton.h"
#include "MainMenu.h"



class EndGame {
public:
    EndGame(std::shared_ptr<sf::RenderWindow> window);
    void update();
    bool optionSelected();
    int getSelectedOption();
    int option{ 0 };
    //bool gameContinue = false;
private:
    void setupTextures();
    void handleInput();

    unsigned int selectedItem{ 0 };
    sf::Sprite background;
    std::vector<UIButton> buttonVector;
    std::shared_ptr<sf::RenderWindow> window;
    bool selected{ false };
    sf::Font font;
};


#endif //ICYTOWER_ENDGAME_H
