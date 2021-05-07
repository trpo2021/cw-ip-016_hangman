#pragma once

#include <libhangman/constants.h>

#include <SFML/Graphics.hpp>

typedef struct {
    sf::RectangleShape form;
    sf::Text text;
} st_button;

enum buttons_theme { random_t, animals, countries, nature, school, sport };

bool is_window_closed(sf::RenderWindow& window, sf::Event event);

int choose_the_word(
        int* choosen_theme, std::string* string_theme, std::string* final_word);
