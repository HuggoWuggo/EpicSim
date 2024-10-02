#include "Dog.h"

sf::Vector2f static Interpolate(const sf::Vector2<float>& pointA, const sf::Vector2<float>& pointB, float factor) {
    if (factor > 1.f)
        factor = 1.f;

    else if (factor < 0.f)
        factor = 0.f;

    return pointA + (pointB - pointA) * factor;
}

Dog::Dog() {
    isRight = true;
    currentSprite = 6;
    Moving = false;

    // Init vars
    dead = false;

    // Load Image
    spritesheet.loadFromFile("Resources/Sprites/walkR.png");

    // Init texture
    dogTex.loadFromImage(spritesheet, sf::IntRect(0, 0, 64, 64));
    dogTex.setRepeated(false);

    // Init Sprite
    dogSpr.setPosition(600, 10);
    dogSpr.setScale(1.5, 1.5);
    dogSpr.setTexture(dogTex);

    // Init Outline
    dogOut.setSize(sf::Vector2f(96, 96));
    dogOut.setFillColor(sf::Color(0, 0, 0, 0));
    dogOut.setOutlineColor(sf::Color::Black);
    dogOut.setOutlineThickness(2);

    // Init Collision
    dogcol.setSize(sf::Vector2f(75, 20));
    dogcol.setFillColor(sf::Color(0, 0, 0, 0));
    dogcol.setOutlineColor(sf::Color::Blue);
    dogcol.setOutlineThickness(2);
}

void Dog::moveTowards(std::vector<sf::RectangleShape> placed)
{
    Moving = true;
    sf::RectangleShape rect = (sf::RectangleShape)placed.back();
    sf::Vector2f pointB = rect.getPosition();
    
    if (!dogcol.getGlobalBounds().intersects(rect.getGlobalBounds())) {

        if (pointB.x > dogSpr.getPosition().x) {
            spritesheet.loadFromFile("Resources/Sprites/walkR.png");
            isRight = true;
        }
        else if (pointB.x < dogSpr.getPosition().x) {
            spritesheet.loadFromFile("Resources/Sprites/walkL.png");
            isRight = false;
        }

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
    if (Moving && dead == false) {
        if (clock.getElapsedTime().asMilliseconds() > 50) {
            if (currentSprite >= 5) {
                currentSprite = 1;
            }
            else {
                currentSprite += 1;
            }
            clock.restart();
        }
    }

    dogOut.setPosition(dogSpr.getPosition().x, dogSpr.getPosition().y);
    dogcol.setPosition(dogSpr.getPosition().x + 8, dogSpr.getPosition().y + 60);

    this->tileX = std::floor((dogSpr.getPosition().x + (96 / 2)) / 64);
    this->tileY = std::floor((dogSpr.getPosition().y + (96/ 2))/ 64);
}

void Dog::render(sf::RenderWindow& window)
{
    dogTex.loadFromImage(spritesheet, sf::IntRect(currentSprite * 64, 0, 64, 64));
    window.draw(dogSpr);
    //window.draw(dogOut);
    //window.draw(dogcol);
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
    dogSpr.setPosition(600, 10);
    Moving = false;
    isRight = true;
    spritesheet.loadFromFile("Resources/Sprites/walkR.png");
    currentSprite = 6;
}

void Dog::dead_anim()
{
    if (isRight == true)
        spritesheet.loadFromFile("Resources/Sprites/deathL.png");
    else
        spritesheet.loadFromFile("Resources/Sprites/deathR.png");
}