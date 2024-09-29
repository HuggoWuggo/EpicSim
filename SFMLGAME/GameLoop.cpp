#include "GameLoop.h"

GameLoop::GameLoop()
{
    // Init window and events
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "It Works!", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);

    if (!grass.loadFromFile("Resources/Textures/grass.png"))
        std::cout << "Couldn't load texture: GRASS" << std::endl;
    grass.setRepeated(true);

    BKG.setTexture(grass);
    BKG.setScale(1.5, 1.5);
    BKG.setTextureRect(sf::IntRect(0, 0, 800, 600));
}

void GameLoop::pollEvents()
{
    // Poll events
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::RectangleShape rect{ { 20, 20 } };
            rect.setPosition(sf::Vector2f(sf::Mouse::getPosition(*window)));
            rect.setFillColor(sf::Color::Yellow);
            placed.push_back(rect);
        }
    }
}

void GameLoop::update()
{
    //Update
    dog.update();
    if (placed.size() != 0)
        dog.moveTowards(placed);

}

void GameLoop::render()
{
    // Render
    window->clear();

    // Draw Background
    window->draw(BKG);

    //Draw Sprites
    for (auto& e : placed) {
        window->draw(e);
    }
    dog.render(*window);

    window->display();
}

bool GameLoop::running()
{
    return window->isOpen();
}
