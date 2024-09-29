#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

sf::Vector2f Interpolate(const sf::Vector2<float>& pointA, const sf::Vector2<float>& pointB, float factor) {
    if (factor > 1.f)
        factor = 1.f;

    else if (factor < 0.f)
        factor = 0.f;

    return pointA + (pointB - pointA) * factor;
}

class Dog {
private:
    sf::Texture dogTex;
    sf::RectangleShape dogcol;
    sf::RectangleShape dogOut;
public:
    sf::Sprite dogSpr;
    float factor = 0.f, speed = .01f;
    Dog() {
        // Init texture
        dogTex.loadFromFile("Resources/Sprites/dog.png");
        dogTex.setRepeated(false);

        // Init Sprite
        dogSpr.setPosition(600, 20);
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

    void moveTowards(std::vector<sf::RectangleShape> placed) {
        sf::RectangleShape rect = (sf::RectangleShape)placed.back();
        sf::Vector2f pointB = rect.getPosition();
        if (!dogcol.getGlobalBounds().intersects(rect.getGlobalBounds())) {
            // Move towards factor
            factor = speed;
            dogSpr.setPosition(Interpolate(dogSpr.getPosition(), sf::Vector2f(pointB.x - 40, pointB.y - 40), factor));
        }
        else {
            std::cout << "Hello World" << std::endl;
        }
    }

    void update() {
        dogOut.setPosition(dogSpr.getPosition().x, dogSpr.getPosition().y);
        dogcol.setPosition(dogSpr.getPosition().x + 8, dogSpr.getPosition().y + 35);
    }

    void render(sf::RenderWindow& window) {
        window.draw(dogSpr);
        window.draw(dogOut);
        window.draw(dogcol);
    }
};

int main() {
    // Init window and events
	sf::RenderWindow window(sf::VideoMode(800, 600), "Chinese Simulator", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    
    // Create a Vector of Rectangles
    std::vector<sf::RectangleShape> placed;

    // Init grass texture
    sf::Texture grass;
    if (!grass.loadFromFile("Resources/Textures/grass.png"))
        std::cout << "Couldn't load texture: GRASS" << std::endl;
    grass.setRepeated(true);

    // Init dog
    Dog dog;
    // Init Background sprite
    sf::Sprite BKG;
    BKG.setTexture(grass);
    BKG.setScale(1.5, 1.5);
    BKG.setTextureRect(sf::IntRect(0, 0, 800, 600));
    

	while (window.isOpen())
    {

        // Poll events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::RectangleShape rect{ { 20, 20 } };
                rect.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
                rect.setFillColor(sf::Color::Yellow);
                placed.push_back(rect);
            }
        }

        //Update
        dog.update();
        if (placed.size() != 0)
            dog.moveTowards(placed);

        // Render
        window.clear();

        // Draw Background
        window.draw(BKG);

        //Draw Sprites
        dog.render(window);
        for (auto& e : placed) {
            window.draw(e);
        }

        window.display();
    }

}

//#include <vector>
//#include <SFML/Graphics.hpp>
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
//    std::vector<sf::RectangleShape> rects;
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//            else if (event.type == sf::Event::MouseButtonPressed &&
//                event.mouseButton.button == sf::Mouse::Left) {
                //sf::RectangleShape rect{ { 3, 3 } };
                //rect.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
                //rect.setFillColor(sf::Color::Green);
                //rects.push_back(rect);
//            }
//        }
//        window.clear();
//        for (const auto& r : rects)
//            window.draw(r);
//        window.display();
//    }
//}