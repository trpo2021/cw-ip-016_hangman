#include "service.h"

#include <ctime>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

bool is_window_closed(sf::RenderWindow& window, sf::Event event)
{
    while (window.pollEvent(event))
        if ((event.type == sf::Event::Closed)
            || ((event.type == sf::Event::KeyPressed)
                && (event.key.code == sf::Keyboard::Escape))) {
            return true;
        }
    return false;
}

int choose_the_word(
        int* choosen_theme, std::string* string_theme, std::string* final_word)
{
    srand(time(NULL));

    std::string word_buffer[max_words_amount];

    if (*choosen_theme == random_t)
        *choosen_theme = rand() % theme_amount + 1;

    std::ifstream file_theme;
    switch (*choosen_theme) {
    case animals:
        *string_theme = " Animals ";
        file_theme.open("../res/animals.txt");
        break;
    case countries:
        *string_theme = "Countries";
        file_theme.open("../res/countries.txt");
        break;
    case nature:
        *string_theme = "  Nature ";
        file_theme.open("../res/nature.txt");
        break;
    case school:
        *string_theme = "  School ";
        file_theme.open("../res/school.txt");
        break;
    case sport:
        *string_theme = "    Sport";
        file_theme.open("../res/sport.txt");
        break;
    }

    if (!file_theme.is_open()) {
        return CANNOT_OPEN_TXT_FILE;
    }

    int words_amount = 0;
    while (!file_theme.eof() && words_amount < max_words_amount) {
        file_theme >> word_buffer[words_amount];
        words_amount++;
    }

    int word_number = rand() % words_amount;

    if (word_buffer[word_number].size() > 8)
        return TOO_LONG_WORD;

    *final_word = word_buffer[word_number];

    return SUCCESS;
}
