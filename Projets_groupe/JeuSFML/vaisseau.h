#ifndef VAISSEAU_H_INCLUDED
#define VAISSEAU_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Vecteur.h"

class Vaisseau {
    public:
        Vaisseau() = default;
        Vaisseau (sf::Color const& couleur);
        void afficher(sf::RenderWindow& fenetre);
        void actualiserEtat(sf::Event const& evenement);
        void update(float time);
    private:
        Vecteur vitesse{0.f,0.f};
        bool acceleration{false};
        bool turnLeft{false};
        bool turnRight{false};
        sf::Texture texture;
        sf::Sprite sprite;
        const float ACCEL{5000.f};
        const float COEF{2.f};
        const float ANGULAR_SPEED{1.f};
};

#endif // VAISSEAU_H_INCLUDED
