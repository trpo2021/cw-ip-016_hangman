#pragma once

#include <libhangman/constants.h>

#include <SFML/Graphics.hpp>

typedef struct {
    sf::RectangleShape form;
    sf::Text text;
} st_button;

enum buttons_theme { random_t, animals, countries, nature, school, sport };

bool is_window_closed(sf::Event event);

bool is_word_correct(std::string choosen_word);

int check_input_symbol(char symbol);

int choose_the_word(
        int* choosen_theme, std::string* string_theme, std::string* final_word);
