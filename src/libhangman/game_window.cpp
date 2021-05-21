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

    if (is_random_theme)
        choosen_theme_string = "Random";

    st_button abc_buttons[abc_length];

    int remaining_tries = 7;

    std::string display_tries = "Your tries: 7";

    std::string hidden_word;
    hidden_word.append(choosen_word_string.size(), hidden_letter);

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
    text_used_letters.setOrigin(-410, -250);

    st_button abc[abc_length];
    create_alphabet(abc, font);

    bool is_repeating[abc_length];
    std::fill_n(is_repeating, abc_length, false);

    sf::RectangleShape lines[7];
    sf::CircleShape head;
    sf::RectangleShape body;
    sf::RectangleShape lhand;
    sf::RectangleShape rhand;
    sf::RectangleShape lleg;
    sf::RectangleShape rleg;

    bool is_win = false;

    window.setKeyRepeatEnabled(false);

    while (window.isOpen()) {
        if (foo_ctw != SUCCESS) {
            window.close();
            return foo_ctw;
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::TextEntered
                && event.text.unicode <= ascii_letter_z
                && event.text.unicode >= ascii_letter_a && remaining_tries != 0
                && is_repeating[event.text.unicode - ascii_letter_a] == false) {
                char ascii_entered_letter = event.text.unicode;

                if (check_input_symbol(ascii_entered_letter) != SUCCESS) {
                    window.close();
                    return ERROR_SYMBOL_INPUT;
                }

                is_repeating[ascii_entered_letter - ascii_letter_a] = true;

                size_t letter_pos
                        = choosen_word_string.find(ascii_entered_letter);

                if (letter_pos != std::string::npos) {
                    put_guessed_letters(
                            letter_pos,
                            ascii_entered_letter,
                            choosen_word_string,
                            &hidden_word);

                    if (is_word_guessed(choosen_word_string, hidden_word)) {
                        is_win = true;
                        open_result_window(
                                window, is_win, &choosen_word_string);
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
                    case 6:
                        create_stand(lines);
                        break;
                    case 5:
                        create_head(head);
                        break;
                    case 4:
                        create_body(body);
                        break;
                    case 3:
                        create_lhand(lhand);
                        break;
                    case 2:
                        create_rhand(rhand);
                        break;
                    case 1:
                        create_lleg(lleg);
                        break;
                    case 0:
                        create_rleg(rleg);
                        window.draw(rleg);
                        window.display();

                        is_win = false;
                        open_result_window(
                                window, is_win, &choosen_word_string);
                        break;
                    }
                }

                abc[event.text.unicode - ascii_letter_a].text.setString(' ');
                used_letters_display
                        = used_letters_display + ascii_entered_letter + ", ";
                text_used_letters.setString(used_letters_display);
            }

            if (is_window_closed(event)) {
                window.close();
            }
        }

        window.clear(sf::Color(
                (int)bg_color::r, (int)bg_color::g, (int)bg_color::b));

        for (int i = 0; i < abc_length; ++i) {
            window.draw(abc[i].form);
            window.draw(abc[i].text);
        }
        window.draw(text_theme);
        window.draw(text_tries);
        window.draw(text_used_letters);
        window.draw(text_hidden_word);

        if (remaining_tries < 1)
            window.draw(rleg);
        if (remaining_tries < 2)
            window.draw(lleg);
        if (remaining_tries < 3)
            window.draw(rhand);
        if (remaining_tries < 4)
            window.draw(lhand);
        if (remaining_tries < 5)
            window.draw(body);
        if (remaining_tries < 6)
            window.draw(head);
        if (remaining_tries < 7)
            for (size_t i = 0; i < sizeof(lines) / sizeof(lines[0]); ++i)
                window.draw(lines[i]);

        window.display();
    }

    return SUCCESS;
}
