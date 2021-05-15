#pragma once

#include <libhangman/constants.h>
#include <libhangman/draw.h>
#include <libhangman/result_window.h>
#include <libhangman/service.h>

#include <SFML/Graphics.hpp>

int open_game_window(sf::RenderWindow& window, int* choosen_theme);
