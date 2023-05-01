//
// Created by pawel on 01.05.23.
//

#ifndef ICYTOWER_UIBUTTON_H
#define ICYTOWER_UIBUTTON_H
#include <SFML/Graphics.hpp>
#include <memory>

class UIButton {
public:
    UIButton(sf::Texture& inactiveTexture, sf::Texture& activeTexture);
    void changeState();
    void draw(sf::RenderWindow& window);
    void setPosition(int x, int y);
private:
    bool active{false};
    sf::Texture inactiveTexture;
    sf::Texture activeTexture;

    sf::Sprite sprite;
};


#endif //ICYTOWER_UIBUTTON_H
