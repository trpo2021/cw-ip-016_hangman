#include "game_window.h"

#include <iostream> //get rid of warning unused parametr

int open_game_window(sf::RenderWindow& window, int* choosen_theme)
{
    std::cout << *choosen_theme; // get rid of warning unused parametr

    while (window.isOpen()) {
        window.clear(sf::Color(bg_color_r, bg_color_g, bg_color_b));

        window.display();

        sf::Event event_close_app;
        if (is_window_closed(window, event_close_app)) {
            window.close();
        }
    }

    return SUCCESS;
}
