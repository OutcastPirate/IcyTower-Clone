#ifndef ICYTOWER_UIBUTTON_H
#define ICYTOWER_UIBUTTON_H
#include <SFML/Graphics.hpp>
#include <memory>

class UIButton {
public:
    UIButton(sf::Texture& inactiveTexture, sf::Texture& activeTexture, int button_code);
    /**
     * UIButton class constructor
     * @param inactiveTexture button's display while not chosen
     * @param activeTexture button's display while chosen
     * @param button_code value stored to identifiy which button has been pressed
     *
     */
    void changeState();
    /**
     * changeState() - method used to switch between active and inactive button states
     */
    void draw(sf::RenderWindow& window);
    /**
     * draw() - allows to render the Tile object inside a window
     * @param windows Reference to a window in which the Tile is supposed to be displayed
     *
     */
    void setPosition(int x, int y);
    /**
     * setPosition() - sets the button at given vertical and horizontal offset
     * @param x Horizontal offset off the button
     * @param y Vertical offset off the button
     *
     */
    sf::Sprite sprite;
    int button_code;
    /**
     * button_code value stored to identifiy which button has been pressed
     */
    bool active{false};
    /**
     * active bool used to determine the button's state
     */
private:
    sf::Texture inactiveTexture;
    /**
     * inactiveTexture button's texture to display while in inactive state
     *
     */
    sf::Texture activeTexture;
    /**
     * inactiveTexture button's texture to display while in active state
     *
     */
};


#endif //ICYTOWER_UIBUTTON_H
