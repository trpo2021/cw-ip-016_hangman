#pragma once

#include <libhangman/constants.h>
#include <libhangman/service.h>
#include <libhangman/theme_window.h>

#include <SFML/Graphics.hpp>

int open_result_window(
        sf::RenderWindow& window, bool is_win, std::string the_word);
