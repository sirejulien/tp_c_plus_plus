#include <SFML/Graphics.hpp>
#include "bombardier.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280,720), "Bomber Plane!", sf::Style::Fullscreen);
    auto clock = sf::Clock();
    auto bombardier1 = Bombardier(1);
    auto bombardier2 = Bombardier(2);

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
            bombardier1.refreshState(event);
            bombardier2.refreshState(event);
        }
        bombardier1.update(clock.restart().asSeconds());
        bombardier2.update(clock.restart().asSeconds());
        window.clear(sf::Color(255, 255, 255));
        bombardier1.display(window);
        bombardier2.display(window);
        window.display();
    }

    return 0;
}
