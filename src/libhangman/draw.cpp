#include "draw.h"

#include <string>

void draw_word_lines(sf::RenderWindow& window, int* word_size)
{
    sf::RectangleShape underlines[*word_size];

    const int indent = 130;
    const int coord_lines_height = 250;
    const int lines_size = 50;
    const int lines_thickness = 2;

    int delta_bw_lines = 20;

    for (int i = 0; i < *word_size; ++i) {
        underlines[i].setSize(sf::Vector2f(lines_size, lines_thickness));
        underlines[i].setFillColor(sf::Color::Black);
        underlines[i].setPosition(
                window_length - indent - delta_bw_lines, coord_lines_height);

        delta_bw_lines += 80;

        window.draw(underlines[i]);
    }
}

int draw_alphabet(sf::RenderWindow& window, st_button abc[])
{
    std::string abc_string[abc_length]
            = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
               "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    sf::Font font;
    if (!font.loadFromFile("../res/sansation.ttf")) {
        return CANNOT_LOAD_FONT;
    }

    const int letter_button_size = 50;
    const int letter_size = 40;
    const int letter_indent = 80;
    const int length_indent = 150;
    const int height_indent = 350;
    const int first_row = 8;

    int printed_letters = 0;
    int delta_height = -30;
    int delta_length = window_length / 2;

    for (int i = 0; i < abc_length; ++i) {
        if (printed_letters == first_row || printed_letters == first_row * 2) {
            delta_height += letter_indent;
            delta_length = window_length / 2;
        }

        if (printed_letters == first_row * 3) {
            delta_height += letter_indent;
            delta_length = window_length / 2 - letter_indent * 3;
        }

        abc[i].form.setSize(
                sf::Vector2f(letter_button_size, letter_button_size));
        abc[i].form.move(
                window_length - length_indent - delta_length,
                height_indent + delta_height);
        abc[i].form.setFillColor(sf::Color::White);
        abc[i].form.setOutlineThickness(button_thickness);
        abc[i].form.setOutlineColor(sf::Color::Black);

        abc[i].text.setFont(font);
        abc[i].text.setString(abc_string[i]);
        abc[i].text.setCharacterSize(letter_size);
        abc[i].text.setFillColor(sf::Color::Black);
        abc[i].text.setOrigin(
                -window_length + length_indent + delta_length - 10,
                -height_indent - delta_height);

        if (sf::IntRect(
                    window_length - length_indent - delta_length,
                    height_indent + delta_height,
                    letter_button_size,
                    letter_button_size)
                    .contains(sf::Mouse::getPosition(window))) {
            abc[i].form.setFillColor(
                    sf::Color(pr_button_r, pr_button_g, pr_button_b));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                // Scan the letter
            }
        } else
            abc[i].form.setFillColor(sf::Color::White);

        delta_length -= letter_indent;

        window.draw(abc[i].form);
        window.draw(abc[i].text);

        printed_letters++;
    }

    return SUCCESS;
}
