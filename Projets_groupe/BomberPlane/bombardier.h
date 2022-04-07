#ifndef BOMBARDIER_H_INCLUDED
#define BOMBARDIER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "bomb.h"
#include <vector>
#include <iostream>

class Bombardier {
    public:
        Bombardier(int numBombardier);
        void display(sf::RenderWindow& window, float time);
        void refreshState(sf::Event const& event);
        void update(float time,float globalTime);
        void dropBomb(float time);
        sf::Sprite sprite;
    private:
        Vecteur speed{0.f,0.f};
        bool accelerating{false};
        bool turnLeft{false};
        bool turnRight{false};
        bool shoot{false};
        sf::Texture texture;
        const float ACCEL{1500.f};
        const float COEF{2.f};
        const float ANGULAR_SPEED{0.12f};
        const float MIN_SPEED{250.f};
        std::vector <Bomb> bombList;
        float shootCooldown {0};
};

#endif // BOMBARDIER_H_INCLUDED
