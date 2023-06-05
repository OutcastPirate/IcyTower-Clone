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
    /**
    *   MainMenu class is used to generate and display the welcome screen and starting menu
    */
public:
    MainMenu(std::shared_ptr<sf::RenderWindow> window);
    /**
     *  MainMenu class constructor
     *  @param window Window in which the Main Menu should be generated
     *
    */
    void update();
    /**
     *  update Method used to update contents of the Menu
     *
    */
    bool optionSelected();
    /**
     *  optionSelected Method used to define whether an option has been chosen
     *
    */
    int getSelectedOption();
    /**
     *  getSelectedOption Method used to determine which option has been chosen
     *
    */
    int option{0};
private:
    void setupTextures();
    /**
     *  setupTextures Method used to setup all necessary objects and their textures to generate 
     *
    */
    void handleInput();
    /**
     *  handleInput Method used to handle and process user input while in the Main Menu
     *
    */
    unsigned int selectedItem{0};
    /**
     *  selectedItem Property storing the id of currently chosen option
     *
    */
    sf::Sprite background;
    /**
     *  background Background object
     *
    */
    sf::Sprite gameLogo;
    /**
     *  gameLogo The game's logo displayed on the welcome screen
     *
    */
    std::vector<UIButton> buttonVector;
    /**
     *  buttonVector Vector of UIButton objects that are later renderen as a menu
     *
    */
    std::shared_ptr<sf::RenderWindow> window;
    /**
     *  window Window in which the Menu is generated
     *
    */
    bool selected{false};
    /**
    *   selected Bool used to determine wether an option has been chosen
    */
    sf::Font font;
    /**
     *  font Font used in Text objects
     *
    */
};


#endif //ICYTOWER_MAINMENU_H
