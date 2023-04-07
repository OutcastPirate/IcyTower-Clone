#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "Player.h"

int main()
{
    const int gameWidth = 1000;
    const int gameHeight = 900;

    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "Icy Tower",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(false);

    Player player(300, 200, gameWidth, gameHeight);
    player.setPosition(100, 100);
    float _deltaTime = 0.0f;


    sf::RectangleShape shape(sf::Vector2f(130, 40));
    shape.setPosition(900, 750);
    shape.setFillColor(sf::Color(120, 30, 200));
    sf::Clock clock;
    while (window.isOpen())
    {
        window.clear(sf::Color(0, 0, 0));
        player.update(clock.restart().asSeconds(), shape);
        window.draw(shape);
        player.draw(window);
        // Display things on screen
        window.display();
    }

    return EXIT_SUCCESS;
}
