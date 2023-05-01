#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>

#include "Game.h"
#include "MainMenu.h"

int main() {
    // Setting up render window.
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(gameWidth, gameHeight, 32), "Icy Tower",
                                                 sf::Style::Titlebar | sf::Style::Close, settings);
    window->setVerticalSyncEnabled(false);

    auto mainMenu = MainMenu(window);
    while(!mainMenu.optionSelected()){
        mainMenu.update();
    }

    auto game = Game(window);

    while(game.isWindowOpen()) {
        game.update();
    }
    return EXIT_SUCCESS;
}

//void counterSetup() {
//    floorCounter = Tile(90, 90, 60, (maxCameraPlacement - 430), counterTexture.get());
//    int textOffset = 10 * (std::to_string(currentFloor).length());
//    text.setPosition((110 - textOffset), (maxCameraPlacement - 405));
//    currentFloor = (-1) * ((int(player.getPosition().y) - 831) / 100);
//    text.setString(std::to_string(currentFloor));
//}