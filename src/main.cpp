#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Player.h"
#include "Tile.h"

int main() {
    const int gameWidth = 1000;
    const int gameHeight = 900;
    sf::Texture texture;
    if (!texture.loadFromFile("resources/image.png")) {
        std::cout << "Unable to load texture" << std::endl;
    }

    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "Icy Tower",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(false);

    std::vector<Tile> tileVector;
    tileVector.emplace_back(1000, 30, 0, 870, &texture);
    tileVector.emplace_back(200, 30, 250, 750, &texture);
    tileVector.emplace_back(200, 30, 550, 650, &texture);
    Player player(300, 200, gameWidth, gameHeight);
    player.setPosition(100, 100);
    sf::Event event{};


    sf::Clock clock;
    while (window.isOpen()) {
        window.clear(sf::Color(0, 0, 0));
        player.update(clock.restart().asSeconds());
        player.intersectTileVector(tileVector);
        for (const auto &tile: tileVector) {
            tile.draw(window);
        }
        player.draw(window);
        // Display things on screen
        window.display();

        // Process events
        while (window.pollEvent(event)) {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return EXIT_SUCCESS;
}
