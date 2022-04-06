#include "bombardier.h"
#include "Vecteur.h"
#include <iostream>

Bombardier::Bombardier (int numBombardier){
    if (numBombardier==1) {
      texture.loadFromFile("ressources/sprite_bombardier.png");
    } else {
        texture.loadFromFile("ressources/sprite_bombardier2.png");
    }
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
    sprite.setPosition(50, 50);
}

void Bombardier::display(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Bombardier::refreshState(sf::Event const& event) {
    accelerating = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    turnLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    turnRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Bombardier::update(float time) {
    if (accelerating) {
        speed += Vecteur::speedFromAngle(ACCEL * time, sprite.getRotation());
    }
    speed-=speed*COEF*time;
    auto deplacement = speed*time;
    sprite.move(deplacement.x,deplacement.y);
    if (turnLeft) {
        sprite.rotate(-ANGULAR_SPEED);
    }
    if (turnRight) {
        sprite.rotate(ANGULAR_SPEED);
    }
}
