//
// Created by pawel on 01.05.23.
//

#ifndef ICYTOWER_UIBUTTON_H
#define ICYTOWER_UIBUTTON_H
#include <SFML/Graphics.hpp>
#include <memory>

class UIButton {
public:
    UIButton(sf::Texture& inactiveTexture, sf::Texture& activeTexture, int button_code);
    void changeState();
    void draw(sf::RenderWindow& window);
    void setPosition(int x, int y);
    sf::Sprite sprite;
    int button_code;
    bool active{false};
private:
    sf::Texture inactiveTexture;
    sf::Texture activeTexture;
};


#endif //ICYTOWER_UIBUTTON_H
