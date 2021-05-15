#include "game_window.h"

#include <string>

int open_game_window(sf::RenderWindow& window, int* choosen_theme)
{
    sf::Font font;
    if (!font.loadFromFile("../res/sansation.ttf")) {
        return CANNOT_LOAD_FONT;
    }

    bool is_random_theme = false;
    if (*choosen_theme == 0)
        is_random_theme = true;

    std::string choosen_word_string;
    std::string choosen_theme_string;

    int foo_ctw = choose_the_word(
            choosen_theme, &choosen_theme_string, &choosen_word_string);
    if (foo_ctw != SUCCESS)
        return foo_ctw;

    if (is_random_theme)
        choosen_theme_string = "Random";

    st_button abc_buttons[abc_length];

    int remaining_tries = 7;

    std::string display_tries = "Your tries: 7";

    std::string hidden_word;
    hidden_word.append(choosen_word_string.size(), ascii_underline);

    sf::Text text_hidden_word(hidden_word, font);
    text_hidden_word.setFillColor(sf::Color::Black);
    text_hidden_word.setCharacterSize(55);
    sf::FloatRect rect_hid = text_hidden_word.getLocalBounds();
    text_hidden_word.setOrigin(
            rect_hid.left + rect_hid.width / 2,
            rect_hid.top + rect_hid.height / 2);
    text_hidden_word.setPosition(sf::Vector2f(window_length / 2 + 150, 215));

    sf::Text text_theme;
    text_theme.setFont(font);
    text_theme.setString(choosen_theme_string);
    text_theme.setCharacterSize(70);
    text_theme.setFillColor(sf::Color::Black);
    sf::FloatRect rect_theme = text_theme.getLocalBounds();
    text_theme.setOrigin(
            rect_theme.left + rect_theme.width / 2,
            rect_theme.top + rect_theme.height / 2);
    text_theme.setPosition(sf::Vector2f(window_length / 2, 70));

    sf::Text text_tries;
    text_tries.setFont(font);
    text_tries.setString(display_tries);
    text_tries.setCharacterSize(35);
    text_tries.setFillColor(sf::Color::Black);
    text_tries.setOrigin(-850, -20 - 35);

    std::string used_letters_display = "Used letters: \n \t";

    sf::Text text_used_letters;
    text_used_letters.setFont(font);
    text_used_letters.setString(used_letters_display);
    text_used_letters.setCharacterSize(30);
    text_used_letters.setFillColor(sf::Color::Black);
    text_used_letters.setOrigin(-405, -250);

    window.setKeyRepeatEnabled(false);

    st_button abc[abc_length];

    bool is_repeating[abc_length];
    std::fill_n(is_repeating, abc_length, false);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::TextEntered
                && event.text.unicode <= ascii_letter_z
                && event.text.unicode >= ascii_letter_a && remaining_tries != 0
                && is_repeating[event.text.unicode - ascii_letter_a] == false) {
                char ascii_entered_letter = event.text.unicode;

                is_repeating[ascii_entered_letter - ascii_letter_a] = true;

                size_t letter_pos
                        = choosen_word_string.find(ascii_entered_letter);

                if (letter_pos != std::string::npos) {
                    while (letter_pos != std::string::npos) {
                        hidden_word.replace(
                                letter_pos, 1, 1, ascii_entered_letter);
                        letter_pos = choosen_word_string.find(
                                ascii_entered_letter, letter_pos + 1);
                    }

                    if (hidden_word.find(ascii_underline)
                        == std::string::npos) {
                        // Result window - win
                    }

                    text_hidden_word.setString(hidden_word);
                } else {
                    remaining_tries--;

                    char remaining_tries_char
                            = remaining_tries + ascii_number_0;
                    display_tries[display_tries.size() - 1]
                            = remaining_tries_char;
                    text_tries.setString(display_tries);

                    switch (remaining_tries) {
                        // Draw the picture
                    }

                    if (remaining_tries == 0) {
                        // Result window - lose
                    }
                }

                abc[event.text.unicode - ascii_letter_a].text.setString(' ');
                used_letters_display
                        = used_letters_display + ascii_entered_letter + ", ";
                text_used_letters.setString(used_letters_display);
            }

            if (event.type == sf::Event::Closed
                || ((event.type == sf::Event::KeyPressed)
                    && (event.key.code == sf::Keyboard::Escape)))
                window.close();
        }

        window.clear(sf::Color(bg_color_r, bg_color_g, bg_color_b));

        window.draw(text_theme);
        window.draw(text_tries);
        window.draw(text_used_letters);
        window.draw(text_hidden_word);

        window.display();
    }

    return SUCCESS;
}
