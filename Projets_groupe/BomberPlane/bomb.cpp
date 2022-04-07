#include "bomb.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Bomb::Bomb (float x, float y, float time){
    texture = new sf::Texture;
    texture->loadFromFile("ressources/sprite_explosion.png");
    sprite.setTexture(*texture);
    sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
    sprite.setPosition(x,y);
    dropTime = time;
}

Bomb::~Bomb() {

}
/*void Bomb::display(sf::RenderWindow& window) {
    window.draw(sprite);
}*/
