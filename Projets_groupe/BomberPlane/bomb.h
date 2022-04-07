#ifndef BOMB_H_INCLUDED
#define BOMB_H_INCLUDED

#include <SFML/Graphics.hpp>

struct Bomb {
    public:
    Bomb(float x, float y, float time);
    ~Bomb();
    //void display(sf::RenderWindow& window);
    sf::Texture *texture;
    sf::Sprite sprite;
    float dropTime;
    const float FALL_TIME {1.f};
    const float LIFE_SPAN {1.5f};
};


#endif // BOMB_H_INCLUDED
