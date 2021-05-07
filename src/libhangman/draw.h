#pragma once

#include <libhangman/constants.h>
#include <libhangman/service.h>

#include <SFML/Graphics.hpp>

void draw_word_lines(sf::RenderWindow& window, int* word_size);

int draw_alphabet(sf::RenderWindow& window, st_button abc[]);
