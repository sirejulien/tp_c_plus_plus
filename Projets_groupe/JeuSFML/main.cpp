#include <SFML/Graphics.hpp>
#include "vaisseau.h"

int main()
{
    sf::RenderWindow fenetre(sf::VideoMode(1200,675), "SFML works!");
    auto clock = sf::Clock();
    auto vaisseau = Vaisseau(sf::Color::Green);

    while (fenetre.isOpen())
    {
        sf::Event evenement;
        while (fenetre.pollEvent(evenement))
        {
            if (evenement.type == sf::Event::Closed) {
                fenetre.close();
            }
            vaisseau.actualiserEtat(evenement);
        }
        vaisseau.update(clock.restart().asSeconds());
        fenetre.clear(sf::Color(255, 255, 255));
        vaisseau.afficher(fenetre);
        fenetre.display();
    }

    return 0;
}
