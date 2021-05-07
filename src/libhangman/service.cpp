#include "service.h"

bool is_window_closed(sf::RenderWindow& window, sf::Event event)
{
    while (window.pollEvent(event))
        if ((event.type == sf::Event::Closed)
            || ((event.type == sf::Event::KeyPressed)
                && (event.key.code == sf::Keyboard::Escape))) {
            return true;
        }
    return false;
}
