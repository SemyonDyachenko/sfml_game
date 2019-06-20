#include "Player.h"


using namespace sf;




int main() {
    Player player("../res/hero.png");
    RenderWindow window(VideoMode(800, 600), "SFML");
    player.view.reset(sf::FloatRect(0,0,800/1.2,600/1.2));




    sf::Clock clock;


    while (window.isOpen()) {
        double time = clock.restart().asMicroseconds()/700;
        Event event;
        while (window.pollEvent(event)) {
         if(event.type == Event::Closed)
            window.close();
        }

        window.setView(player.view);
        window.clear();
        player.update(time);



        player.render(window);
        window.display();

    }

    return 0;
}