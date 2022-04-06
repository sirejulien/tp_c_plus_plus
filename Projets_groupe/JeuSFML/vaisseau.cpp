#include "vaisseau.h"
#include "Vecteur.h"
#include <iostream>

Vaisseau::Vaisseau (sf::Color const& couleur){
    if (!texture.loadFromFile("ressources/vaisseau.png")) {
        std::cerr << "Image not found"<< std::endl;
    }
    //texture.loadFromFile("ressources/vaisseau.png");
    sprite.setTexture(texture);
    sprite.setColor(couleur);
    sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
    sprite.setPosition(50, 50);
}

void Vaisseau::afficher(sf::RenderWindow& fenetre) {
    fenetre.draw(sprite);
}

void Vaisseau::actualiserEtat(sf::Event const& evenement) {
    acceleration = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    turnLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    turnRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Vaisseau::update(float time) {
    if (acceleration) {
        vitesse += Vecteur::speedFromAngle(ACCEL * time, sprite.getRotation());
    }
    vitesse-=vitesse*COEF*time;
    auto deplacement = vitesse*time;
    sprite.move(deplacement.x,deplacement.y);
    if (turnLeft) {
        sprite.rotate(-ANGULAR_SPEED);
    }
    if (turnRight) {
        sprite.rotate(ANGULAR_SPEED);
    }
}
