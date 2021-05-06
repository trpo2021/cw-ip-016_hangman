#pragma once

#include <SFML/Graphics.hpp>

typedef struct {
    sf::RectangleShape form;
    sf::Text text;
} st_button;

bool is_window_closed(sf::RenderWindow& window, sf::Event event);
