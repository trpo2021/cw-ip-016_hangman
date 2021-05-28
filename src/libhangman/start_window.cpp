#include "start_window.h"

#include <SFML/Audio.hpp>

const int start_button_length = 300;
const int start_button_height = 110;
const int start_b_coord_length = 400;
const int start_b_coord_height = 200;

void create_start_buttons(st_button buttons[], int amount, sf::Font& font)
{
    const int start_t_coord_length = start_b_coord_length + 100;
    const int start_t_coord_height = start_b_coord_height + 20;

    int delta_height = 0;

    std::string buttons_names[amount] = {"Play", "Quit"};

    for (int i = 0; i < amount; ++i) {
        buttons[i].form.setSize(
                sf::Vector2f(start_button_length, start_button_height));
        buttons[i].form.move(
                start_b_coord_length, start_b_coord_height + delta_height);
        buttons[i].form.setFillColor(sf::Color::White);
        buttons[i].form.setOutlineThickness(1);
        buttons[i].form.setOutlineColor(sf::Color::Black);

        buttons[i].text.setFont(font);
        buttons[i].text.setPosition(
                start_t_coord_length, start_t_coord_height + delta_height);
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

    // sf::Music music;
    // music.openFromFile("../res/Sweet_Life.ogg");
    // music.setVolume(7);
    // music.play();
    // music.setLoop(true);

    const int start_buttons_amount = 2;
    st_button start_buttons[start_buttons_amount];
    create_start_buttons(start_buttons, start_buttons_amount, font);

    while (window.isOpen()) {
        int go_next = -1;

        for (int i = 0; i < start_buttons_amount; ++i) {
            if (sf::IntRect(
                        start_b_coord_length,
                        start_b_coord_height + 150 * i,
                        start_button_length,
                        start_button_height)
                        .contains(sf::Mouse::getPosition(window))) {
                start_buttons[i].form.setFillColor(sf::Color(
                        (int)PrButColor::r,
                        (int)PrButColor::g,
                        (int)PrButColor::b));
                go_next = i;
            } else
                start_buttons[i].form.setFillColor(sf::Color::White);
        }

        while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            switch (go_next) {
            case 0:
                open_theme_window(window);
                break;
            case 1:
                window.close();
                break;
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
