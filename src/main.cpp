#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "Player.h"

int main()
{
    const int gameWidth = 800;
    const int gameHeight = 600;

    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "Icy Tower",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    Player player(800, 300, 200);
    player.setPosition(100, 100);
    float _deltaTime = 0.0f;

    sf::Clock clock;
    bool isPlaying = false;
    while (window.isOpen())
    {
        window.clear(sf::Color(0, 0, 0));
        player.update(clock.restart().asSeconds());
        player.draw(window);
        // Clear the window



        // Display things on screen
        window.display();
    }

    return EXIT_SUCCESS;
}
