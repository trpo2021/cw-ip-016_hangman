#include "start_window.h"

#include <SFML/Graphics.hpp>

int begin_the_game()
{
    sf::RenderWindow window(
            sf::VideoMode(1120, 700),
            "Hangman - the game",
            sf::Style::Titlebar | sf::Style::Close);

    sf::Font font;
    if (!font.loadFromFile("../res/sansation.ttf")) {
        return 999;
    }

    sf::RectangleShape button_play(sf::Vector2f(300, 110));
    button_play.move(400, 200);
    button_play.setFillColor(sf::Color(255, 255, 255));
    button_play.setOutlineThickness(1);
    button_play.setOutlineColor(sf::Color(0, 0, 0));

    sf::Text text_play;
    text_play.setFont(font);
    text_play.setString("Play");
    text_play.setCharacterSize(50);
    text_play.setFillColor(sf::Color(0, 0, 0));
    text_play.setPosition(500, 220);

    sf::RectangleShape button_quit(sf::Vector2f(300, 110));
    button_quit.move(400, 350);
    button_quit.setFillColor(sf::Color(255, 255, 255));
    button_quit.setOutlineThickness(1);
    button_quit.setOutlineColor(sf::Color(0, 0, 0));

    sf::Text text_quit;
    text_quit.setFont(font);
    text_quit.setString("Quit");
    text_quit.setCharacterSize(50);
    text_quit.setFillColor(sf::Color(0, 0, 0));
    text_quit.setPosition(500, 370);

    while (window.isOpen()) {
        int go_next = 0;

        if (sf::IntRect(400, 200, 300, 110)
                    .contains(sf::Mouse::getPosition(window))) {
            button_play.setFillColor(sf::Color(236, 223, 255));
            go_next = 1;
        } else
            button_play.setFillColor(sf::Color(255, 255, 255));

        if (sf::IntRect(400, 350, 300, 110)
                    .contains(sf::Mouse::getPosition(window))) {
            button_quit.setFillColor(sf::Color(236, 223, 255));
            go_next = 2;
        } else
            button_quit.setFillColor(sf::Color(255, 255, 255));

        while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (go_next == 1) {
                break;
            }

            if (go_next == 2) {
                window.close();
            }
        }

        window.clear(sf::Color(255, 235, 200));

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

    return 0;
}
