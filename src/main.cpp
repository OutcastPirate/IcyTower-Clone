#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <iostream>

#include "Game.h"
#include "MainMenu.h"
#include "EndGame.h"


int main() {
    // Setting up render window.
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(gameWidth, gameHeight, 32), "Icy Tower",
        sf::Style::Titlebar | sf::Style::Close, settings);
    window->setVerticalSyncEnabled(false);
    int score = 0;
    int highScore = 0;


    auto mainMenu = MainMenu(window);
    while (!mainMenu.optionSelected()) {
        mainMenu.update();
    }

    if (mainMenu.getSelectedOption() <= 0) {
        window->close();
        return EXIT_SUCCESS;
    }

    while (true) {
        auto game = Game(window);
        while (!game.isPlayerOutOfScreen()) {
            game.update();
            //std::cout << game.highScore << std::endl;
            if (game.highScore > highScore) {
                highScore = game.highScore;
            }
            score = game.highScore;
            std::cout << highScore << std::endl;
        }
        auto camera = sf::View(sf::Vector2f(static_cast<float>(gameWidth) / 2, 450), sf::Vector2f(gameWidth, gameHeight));
        window->setView(camera);

        auto endGame = EndGame(window, score, highScore);
        while (!endGame.optionSelected()) {
            endGame.update();
        }
        if (endGame.getSelectedOption() > 0) {
            continue;
        }
        else {
            break;
        }
    }



    window->close();

    return 0;
}

//void counterSetup() {
//    floorCounter = Tile(90, 90, 60, (maxCameraPlacement - 430), counterTexture.get());
//    int textOffset = 10 * (std::to_string(currentFloor).length());
//    text.setPosition((110 - textOffset), (maxCameraPlacement - 405));
//    currentFloor = (-1) * ((int(player.getPosition().y) - 831) / 100);
//    text.setString(std::to_string(currentFloor));
//}