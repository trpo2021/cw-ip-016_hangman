#include "theme_window.h"

int open_theme_window(sf::RenderWindow& window)
{
    while (window.isOpen()) {
        window.clear(sf::Color(bg_color_r, bg_color_g, bg_color_b));
        window.display();
    }

    return SUCCESS;
}
