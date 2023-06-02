//
// Created by pawel on 01.05.23.
//

#ifndef ICYTOWER_MAINMENU_H
#define ICYTOWER_MAINMENU_H
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <string>
#include "TextureManager.h"
#include "UIButton.h"
#include "FilePaths.h"


class MainMenu {
public:
    MainMenu(std::shared_ptr<sf::RenderWindow> window);
    void update();
    bool optionSelected();
    int getSelectedOption();
    int option{0};
private:
    void setupTextures();
    void handleInput();

    unsigned int selectedItem{0};
    sf::Sprite background;
    sf::Sprite gameLogo;
    std::vector<UIButton> buttonVector;
    std::shared_ptr<sf::RenderWindow> window;
    bool selected{false};
    sf::Font font;
};


#endif //ICYTOWER_MAINMENU_H
