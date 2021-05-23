#include "start_window.h"

#include <SFML/Graphics.hpp>

#include <string>

void create_start_buttons(st_button buttons[], int amount, sf::Font& font)
{
    const int button_length = 300;
    const int button_height = 110;

    const int b_coord_length = 400;
    const int b_coord_height = 200;

    const int t_coord_length = b_coord_length + 100;
    const int t_coord_height = b_coord_height + 20;

    int delta_height = 0;

    std::string buttons_names[amount] = {"Play", "Quit"};

    for (int i = 0; i < amount; ++i) {
        buttons[i].form.setSize(sf::Vector2f(button_length, button_height));
        buttons[i].form.move(b_coord_length, b_coord_height + delta_height);
        buttons[i].form.setFillColor(sf::Color::White);
        buttons[i].form.setOutlineThickness(1);
        buttons[i].form.setOutlineColor(sf::Color::Black);

        buttons[i].text.setFont(font);
        buttons[i].text.setPosition(
                t_coord_length, t_coord_height + delta_height);
        buttons[i].text.setString(buttons_names[i]);
        buttons[i].text.setCharacterSize(50);
        buttons[i].text.setFillColor(sf::Color::Black);

        delta_height += 150;
    }
}

int begin_the_game()
{
    const std::string app_name = "Hangman - the game";

    sf::RenderWindow window(
            sf::VideoMode(window_length, window_height),
            app_name,
            sf::Style::Titlebar | sf::Style::Close);

    sf::Font font;
    if (!font.loadFromFile("../res/sansation.ttf")) {
        return CANNOT_LOAD_FONT;
    }

    const int start_buttons_amount = 2;
    st_button start_buttons[start_buttons_amount];
    create_start_buttons(start_buttons, start_buttons_amount, font);

    while (window.isOpen()) {
        int go_next = -1;

        if (sf::IntRect(400, 200, 300, 110)
                    .contains(sf::Mouse::getPosition(window))) {
            start_buttons[0].form.setFillColor(sf::Color(236, 223, 255));
            go_next = 0;
        } else
            start_buttons[0].form.setFillColor(sf::Color(255, 255, 255));

        if (sf::IntRect(400, 350, 300, 110)
                    .contains(sf::Mouse::getPosition(window))) {
            start_buttons[1].form.setFillColor(sf::Color(236, 223, 255));
            go_next = 1;
        } else
            start_buttons[1].form.setFillColor(sf::Color(255, 255, 255));

        while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (go_next == 0) {
                open_theme_window(window);
                break;
            }

            if (go_next == 1) {
                window.close();
            }
        }

        window.clear(
                sf::Color((int)BgColor::r, (int)BgColor::g, (int)BgColor::b));

        for (int i = 0; i < start_buttons_amount; ++i) {
            window.draw(start_buttons[i].form);
            window.draw(start_buttons[i].text);
        }

        window.display();

        sf::Event event_close_app;
        while (window.pollEvent(event_close_app))
            if (is_window_closed(event_close_app)) {
                window.close();
            }
    }

    return SUCCESS;
}
