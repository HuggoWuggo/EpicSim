#include "Dog.h"


sf::Vector2f static Interpolate(const sf::Vector2<float>& pointA, const sf::Vector2<float>& pointB, float factor) {
    if (factor > 1.f)
        factor = 1.f;

    else if (factor < 0.f)
        factor = 0.f;

    return pointA + (pointB - pointA) * factor;
}

Dog::Dog() {
    // Init texture
    dogTex.loadFromFile("Resources/Sprites/dog.png");
    dogTex.setRepeated(false);

    // Init Sprite
    dogSpr.setPosition(0, 0);
    dogSpr.setScale(3, 3);
    dogSpr.setTexture(dogTex);

    // Init Outline
    dogOut.setSize(sf::Vector2f(96, 96));
    dogOut.setFillColor(sf::Color(0, 0, 0, 0));
    dogOut.setOutlineColor(sf::Color::Black);
    dogOut.setOutlineThickness(2);

    // Init Collision
    dogcol.setSize(sf::Vector2f(85, 24));
    dogcol.setFillColor(sf::Color(0, 0, 0, 0));
    dogcol.setOutlineColor(sf::Color::Blue);
    dogcol.setOutlineThickness(2);
}

void Dog::moveTowards(std::vector<sf::RectangleShape> placed)
{
    sf::RectangleShape rect = (sf::RectangleShape)placed.back();
    sf::Vector2f pointB = rect.getPosition();
    
    if (!dogcol.getGlobalBounds().intersects(rect.getGlobalBounds())) {

        // Move towards factor
        factor = speed;
        dogSpr.setPosition(Interpolate(dogSpr.getPosition(), sf::Vector2f(pointB.x - 40, pointB.y - 40), factor));
        //std::cout << "Tile X is: " <<  tileX << " " << "Tile Y is: " <<  tileY<< std::endl;
        dead = false;
       
    }
    else {
        dead = true;
    }
}

void Dog::update() {
    dogOut.setPosition(dogSpr.getPosition().x, dogSpr.getPosition().y);
    dogcol.setPosition(dogSpr.getPosition().x + 8, dogSpr.getPosition().y + 35);

    this->tileX = std::ceil(dogSpr.getPosition().x / 64);
    this->tileY = std::ceil(dogSpr.getPosition().y / 64);
}

void Dog::render(sf::RenderWindow& window)
{
    window.draw(dogSpr);
    window.draw(dogOut);
    window.draw(dogcol);
}

bool Dog::returnDeath() const
{
    return dead;
}

void Dog::setDeath(bool val)
{
    dead = val;
}

void Dog::reset()
{
    dogSpr.setPosition(0, 0);
    std::cout << "TODO RESET" << std::endl;
}
