#include "GameLoop.h"

int main() {

    GameLoop game;

	while (game.running())
    {
        game.pollEvents();

        game.update();

        game.render();
    }

}