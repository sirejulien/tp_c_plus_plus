#include <SFML/Graphics.hpp>
#include "bombardier.h"
#include "constantes.h"
#include "bomb.h"
#include <iostream>
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "Bomber Plane!", sf::Style::Fullscreen);
    window.setMouseCursorVisible(false);
    auto clock = sf::Clock();
    auto clockGlobal = sf::Clock();

    sf::Font font;
    if (!font.loadFromFile("ressources/redemption.ttf"))
    {
        std::cout<<"erreur chargement police"<<std::endl;
    }
    auto clockText = sf::Text();
    clockText.setFont(font);
    clockText.setCharacterSize(24);
    clockText.setFillColor(sf::Color::White);
    clockText.setPosition(25,25);

    auto bombardier1 = Bombardier(1);
    //auto bombardier2 = Bombardier(2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
            bombardier1.refreshState(event);
            //bombardier2.refreshState(event);
        }
        clockText.setString("Time: "+std::to_string(static_cast<int>(clockGlobal.getElapsedTime().asSeconds())));
        bombardier1.update(clock.restart().asSeconds(),clockGlobal.getElapsedTime().asSeconds());
        //bombardier2.update(clock.restart().asSeconds());
        window.clear(sf::Color(39, 130, 31));
        bombardier1.display(window,clockGlobal.getElapsedTime().asSeconds());
        //bombardier2.display(window);
        window.draw(clockText);
        window.display();
    }

    return 0;
}
