#pragma once

#include <libhangman/constants.h>
#include <libhangman/service.h>

#include <SFML/Graphics.hpp>

void draw_word_lines(sf::RenderWindow& window, int* word_size);

void create_stand(sf::RectangleShape lines[]);

void create_head(sf::CircleShape& head);

void create_body(sf::RectangleShape& body);

void draw_lhand(sf::RectangleShape& lhand);

void draw_rhand(sf::RectangleShape& rhand);

int draw_alphabet(sf::RenderWindow& window, st_button abc[]);
