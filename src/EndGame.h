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
    /**
    *   EndGame class is used to generate and display the welcome screen and starting menu
    */
public:
    EndGame(std::shared_ptr<sf::RenderWindow> window, int score, int highScore);
    /**
     *  EndGame class constructor
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
    int option{ 0 };
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
    std::vector<int> getScoreVector(std::string fileName);
    /**
     *  getScoreVector() Method reading the highscore data from file
     *  @param fileName File storing the highscore data
     *
     */
    void updateScoreVector(std::string fileName);
    /**
     *  getScoreVector() Method checking and, if necessary, updating the highscore storage file
     *  @param fileName File storing the highscore data
     *
     */
    void setupHighScoreText();
    /**
     *  setupHighScoreText() Sets up whole highscore table to display
     *
     */
    unsigned int selectedItem{ 0 };
    /**
     *  selectedItem Property storing the id of currently chosen option
     *
    */
    sf::Sprite background;
    /**
     *  background Background object
     *
    */
    sf::Sprite leftLogo;
    /**
     *  leftLogo The game's logo displayed on the left
     *
    */
    sf::Sprite rightLogo;
    /**
     *  rightLogo The game's logo displayed on the right
     *
    */
    std::vector<UIButton> buttonVector;
    /**
     *  buttonVector Vector storing Button objects used to generate the menu
     *
     */
    std::vector<sf::Text> scoreTextVector;
    /**
     *  scoreTextVector Vector with all the Text objects used to generate the highscore table
     *
     */
    std::shared_ptr<sf::RenderWindow> window;
    /**
     *  window Window in which the Menu is generated
     *
     */
    sf::Text scoreText;
    /**
     *  scoreText Text object storing the player's last score
     *
     */
    sf::Text highScoreText;
    /**
     *  highScoreText Text object storing the player's highest score during the current session
     *
     */
    bool selected{ false };
    /**
    *   selected Bool used to determine wether an option has been chosen
    */
    sf::Font font;
    /**
     *  font Font used in Text objects
     *
    */
    int _score;
    /**
     *  _score Score achieved during the last game 
     *
     */
    int _highScore;
    /**
     *  _highScore Player's highest result in the current session
     *
     */

};


#endif //ICYTOWER_ENDGAME_H
