#include "service.h"

#include <ctime>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

bool is_window_closed(sf::Event event)
{
    if ((event.type == sf::Event::Closed)
        || ((event.type == sf::Event::KeyPressed)
            && (event.key.code == sf::Keyboard::Escape))) {
        return true;
    }
    return false;
}

bool is_word_correct(std::string choosen_word)
{
    size_t is_correct
            = choosen_word.find_first_not_of("abcdefghijklmnopqrstuvwxyz");

    return choosen_word.size() <= max_word_length
            && choosen_word.size() >= min_word_length
            && is_correct == std::string::npos;
}

int check_input_symbol(char symbol)
{
    if (symbol >= ascii_letter_a && symbol <= ascii_letter_z)
        return SUCCESS;
    return ERROR_SYMBOL_INPUT;
}

void put_guessed_letters(
        size_t letter_pos,
        char letter,
        std::string word,
        std::string* hidden_word)
{
    while (letter_pos != std::string::npos) {
        hidden_word->replace(letter_pos, 1, 1, letter);
        letter_pos = word.find(letter, letter_pos + 1);
    }
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
        *string_theme = "Animals";
        file_theme.open("../res/animals.txt");
        break;
    case countries:
        *string_theme = "Countries";
        file_theme.open("../res/countries.txt");
        break;
    case nature:
        *string_theme = "Nature";
        file_theme.open("../res/nature.txt");
        break;
    case school:
        *string_theme = "School";
        file_theme.open("../res/school.txt");
        break;
    case sport:
        *string_theme = "Sport";
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

    if (!is_word_correct(word_buffer[word_number]))
        return INCORRECT_WORD_IN_TXT_FILE;

    *final_word = word_buffer[word_number];

    return SUCCESS;
}
