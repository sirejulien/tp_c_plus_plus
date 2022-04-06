#ifndef BOMBARDIER_H_INCLUDED
#define BOMBARDIER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Vecteur.h"

class Bombardier {
    public:
        Bombardier(int numBombardier);
        void display(sf::RenderWindow& window);
        void refreshState(sf::Event const& event);
        void update(float time);
    private:
        Vecteur speed{0.f,0.f};
        bool accelerating{false};
        bool turnLeft{false};
        bool turnRight{false};
        sf::Texture texture;
        sf::Sprite sprite;
        const float ACCEL{1000.f};
        const float COEF{2.f};
        const float ANGULAR_SPEED{0.25f};
};

#endif // BOMBARDIER_H_INCLUDED
