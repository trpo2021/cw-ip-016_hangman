#include "draw.h"

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
