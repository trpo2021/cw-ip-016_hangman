#include "start_window.h"

#include <SFML/Graphics.hpp>

#include <string>

int begin_the_game()
{
    const std::string app_name = "Hangman - the game";

    const int window_length = 1120;
    const int window_height = 700;

    sf::RenderWindow window(
            sf::VideoMode(window_length, window_height),
            app_name,
            sf::Style::Titlebar | sf::Style::Close);

    sf::Font font;
    if (!font.loadFromFile("../res/sansation.ttf")) {
        return CANNOT_LOAD_FONT;
    }

    const int button_length = 300;
    const int button_height = 110;

    sf::RectangleShape button_play(sf::Vector2f(button_length, button_height));
    button_play.move(400, 200);
    button_play.setFillColor(sf::Color::White);
    button_play.setOutlineThickness(1);
    button_play.setOutlineColor(sf::Color::Black);

    sf::Text text_play;
    text_play.setFont(font);
    text_play.setString("Play");
    text_play.setCharacterSize(50);
    text_play.setFillColor(sf::Color::Black);
    text_play.setPosition(500, 220);

    sf::RectangleShape button_quit(sf::Vector2f(button_length, button_height));
    button_quit.move(400, 350);
    button_quit.setFillColor(sf::Color::White);
    button_quit.setOutlineThickness(1);
    button_quit.setOutlineColor(sf::Color::Black);

    sf::Text text_quit;
    text_quit.setFont(font);
    text_quit.setString("Quit");
    text_quit.setCharacterSize(50);
    text_quit.setFillColor(sf::Color::Black);
    text_quit.setPosition(500, 370);

    while (window.isOpen()) {
        int go_next = -1;

        if (sf::IntRect(400, 200, 300, 110)
                    .contains(sf::Mouse::getPosition(window))) {
            button_play.setFillColor(sf::Color(236, 223, 255));
            go_next = 0;
        } else
            button_play.setFillColor(sf::Color(255, 255, 255));

        if (sf::IntRect(400, 350, 300, 110)
                    .contains(sf::Mouse::getPosition(window))) {
            button_quit.setFillColor(sf::Color(236, 223, 255));
            go_next = 1;
        } else
            button_quit.setFillColor(sf::Color(255, 255, 255));

        while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (go_next == 0) {
                open_theme_window(window);
                break;
            }

            if (go_next == 1) {
                window.close();
            }
        }

        window.clear(sf::Color(bg_color_r, bg_color_g, bg_color_b));

        window.draw(button_play);
        window.draw(button_quit);

        window.draw(text_play);
        window.draw(text_quit);

        window.display();

        sf::Event event_close_game;
        while (window.pollEvent(event_close_game))
            if ((event_close_game.type == sf::Event::Closed)
                || ((event_close_game.type == sf::Event::KeyPressed)
                    && (event_close_game.key.code == sf::Keyboard::Escape))) {
                window.close();
                break;
            }
    }

    return SUCCESS;
}
