#include "game_window.h"

#include <iostream> //get rid of warning unused parametr

#include <string>

int open_game_window(sf::RenderWindow& window, int* choosen_theme)
{
    std::cout << *choosen_theme; // get rid of warning unused parametr

    std::string choosen_word_string;
    std::string choosen_theme_string;

    int foo_ctw = choose_the_word(
            choosen_theme, &choosen_theme_string, &choosen_word_string);
    if (foo_ctw != SUCCESS)
        return foo_ctw;

    sf::Font font;
    if (!font.loadFromFile("../res/sansation.ttf")) {
        return CANNOT_LOAD_FONT;
    }

    sf::Text text_theme;
    text_theme.setFont(font);
    text_theme.setString(choosen_theme_string);
    text_theme.setCharacterSize(70);
    text_theme.setFillColor(sf::Color::Black);
    text_theme.setOrigin(-400, -20);

    st_button abc_buttons[abc_length];

    while (window.isOpen()) {
        window.clear(sf::Color(bg_color_r, bg_color_g, bg_color_b));

        window.draw(text_theme);

        int word_size = choosen_word_string.size();
        draw_word_lines(window, &word_size);

        draw_alphabet(window, abc_buttons);

        window.display();

        sf::Event event_close_app;
        if (is_window_closed(window, event_close_app)) {
            window.close();
        }
    }

    return SUCCESS;
}
