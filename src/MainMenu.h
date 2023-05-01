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

const std::string playPath = "resources/menu_play.jpg";
const std::string playSelectedPath = "resources/menu_play_selected.jpg";
const std::string closePath = "resources/menu_close.jpg";
const std::string closeSelectedPath = "resources/menu_close_selected.jpg";


class MainMenu {
public:
    MainMenu(std::shared_ptr<sf::RenderWindow> window);
    void update();
    bool optionSelected();
private:
    void setupTextures();
    void handleInput();

    unsigned int selectedItem{0};
    sf::Sprite background;
    std::vector<UIButton> buttonVector;
    std::shared_ptr<sf::RenderWindow> window;
    bool selected{false};
    sf::Font font;
};


#endif //ICYTOWER_MAINMENU_H
