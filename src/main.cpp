#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;




int main() {
    RenderWindow window(VideoMode(800, 600), "SFML");

    Player player("../res/hero.png");



    sf::Clock clock;
    while (window.isOpen()) {
        double time = clock.restart().asMicroseconds()/1000;
        Event event;
        while (window.pollEvent(event)) {
         if(event.type == Event::Closed)
            window.close();
        }

        window.clear();
        player.update(time);

        player.render(window);
        window.display();

    }

    return 0;
}