#include "bombardier.h"
#include "Vecteur.h"
#include <iostream>
#include "constantes.h"
#include "bomb.h"
#include <vector>
#include <stdio.h>

#include<bits/stdc++.h>

Bombardier::Bombardier (int numBombardier){
    if (numBombardier==1) {
      texture.loadFromFile("ressources/sprite_bombardier.png");
    } else {
        texture.loadFromFile("ressources/sprite_bombardier2.png");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
    sprite.setPosition(50, 50);
}

void Bombardier::display(sf::RenderWindow& window, float time) {
    window.draw(sprite);
    for (int i=0;i<bombList.size();i++) {
        if (time>bombList[i].dropTime+bombList[i].FALL_TIME && time<bombList[i].dropTime+bombList[i].FALL_TIME+bombList[i].LIFE_SPAN) {
            window.draw(bombList[i].sprite);
        }
    }
}

void Bombardier::refreshState(sf::Event const& event) {
    accelerating = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    turnLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    turnRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    shoot = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}

void Bombardier::update(float time, float globalTime) {
    if (accelerating) {
        speed += Vecteur::speedFromAngle(ACCEL * time, sprite.getRotation());
    } else {
        speed = Vecteur::speedFromAngle(speed.getSize(), sprite.getRotation());
    }
    if (speed.getSize()>MIN_SPEED){
        speed-=speed*COEF*time;
    }
    auto deplacement = speed*time;
    sprite.move(deplacement.x,deplacement.y);
    if (turnLeft) {
        sprite.rotate(-ANGULAR_SPEED);
    }
    if (turnRight) {
        sprite.rotate(ANGULAR_SPEED);
    }
    if (sprite.getPosition().x>WINDOW_WIDTH) {
        sprite.setPosition(0,sprite.getPosition().y);
    } else if (sprite.getPosition().x<0) {
        sprite.setPosition(WINDOW_WIDTH,sprite.getPosition().y);
    }
    if (sprite.getPosition().y>WINDOW_HEIGHT) {
        sprite.setPosition(sprite.getPosition().x,0);
    } else if (sprite.getPosition().y<0) {
        sprite.setPosition(sprite.getPosition().x,WINDOW_HEIGHT);
    }
    shootCooldown-=time;
    if (shoot && shootCooldown<0) {
        dropBomb(globalTime);
        shootCooldown=SHOOT_COOLDOWN;
    }
}

void Bombardier::dropBomb(float time) {
    auto bomb = Bomb(sprite.getPosition().x,sprite.getPosition().y,time);
    bombList.push_back(bomb);
}
