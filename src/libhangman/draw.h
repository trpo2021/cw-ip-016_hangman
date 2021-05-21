#pragma once

#include <libhangman/service.h>

#include <SFML/Graphics.hpp>

void create_alphabet(st_button abc[], sf::Font& font);

void create_stand(sf::RectangleShape lines[]);

void create_head(sf::CircleShape& head);

void create_body(sf::RectangleShape& body);

void create_lhand(sf::RectangleShape& lhand);

void create_rhand(sf::RectangleShape& rhand);

void create_lleg(sf::RectangleShape& lleg);

void create_rleg(sf::RectangleShape& rleg);
