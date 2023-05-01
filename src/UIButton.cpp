//
// Created by pawel on 01.05.23.
//

#include "UIButton.h"

UIButton::UIButton(sf::Texture &inactiveTexture, sf::Texture &activeTexture) {
    this->inactiveTexture = inactiveTexture;
    this->activeTexture = activeTexture;
    sprite = sf::Sprite(inactiveTexture);
}

void UIButton::setPosition(int x, int y) {
    sprite.setPosition(x, y);
}

void UIButton::changeState() {
    active = !active;
    if(active) {
        sprite.setTexture(activeTexture);
    } else {
        sprite.setTexture(inactiveTexture);
    }
}
void UIButton::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}
