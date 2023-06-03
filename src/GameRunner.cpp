#include "GameRunner.h"
#include "MainMenu.h"
#include "EndGame.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>



GameRunner::GameRunner() {
	this -> score = 0;
	this -> highScore = 0;
}

int GameRunner::start() {
    // Setting up render window.
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(gameWidth, gameHeight, 32), "Icy Tower",
        sf::Style::Titlebar | sf::Style::Close, settings);
    window->setVerticalSyncEnabled(false);

    auto mainMenu = MainMenu(window);
    while (!mainMenu.optionSelected()) {
        mainMenu.update();
    }

    if (mainMenu.getSelectedOption() <= 0) {
        window->close();
        return 0;
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