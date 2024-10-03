#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

class Dog {
private:
    sf::Texture walkingRightTexture;
    sf::Texture dogTex;
    sf::RectangleShape dogcol;
    sf::RectangleShape dogOut;
    bool dead;

    int currentSprite;
    //Init image
    sf::Image spritesheet;

    sf::Clock clock;
    bool isRight;

public:

    bool Moving;
    sf::Sprite dogSpr;
    int tileX;
    int tileY;

    float factor = 0.f, speed = .03f;
    Dog();

    void moveTowards(std::vector<sf::RectangleShape> placed);

    void update();

    void render(sf::RenderWindow& window);

    bool returnDeath() const;

    void setDeath(bool val);

    void reset();

    void dead_anim();
};