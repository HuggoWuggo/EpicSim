#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

class Dog {
private:
    sf::Texture dogTex;
    sf::RectangleShape dogcol;
    sf::RectangleShape dogOut;
public:
    sf::Sprite dogSpr;
    float factor = 0.f, speed = .01f;
    Dog();

    void moveTowards(std::vector<sf::RectangleShape> placed);

    void update();

    void render(sf::RenderWindow& window);
};