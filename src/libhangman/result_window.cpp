#include "result_window.h"

int open_result_window(
        sf::RenderWindow& window, bool is_win, std::string the_word)
{
    sf::Font font;
    if (!font.loadFromFile("../res/sansation.ttf")) {
        return CANNOT_LOAD_FONT;
    }

    sf::Text text_result;
    text_result.setFont(font);
    if (is_win)
        text_result.setString("You win!");
    else
        text_result.setString("You lose!");
    text_result.setStyle(sf::Text::Underlined);
    text_result.setCharacterSize(70);
    text_result.setFillColor(sf::Color::Black);
    sf::FloatRect rect_res = text_result.getLocalBounds();
    text_result.setOrigin(
            rect_res.left + rect_res.width / 2,
            rect_res.top + rect_res.height / 2);
    text_result.setPosition(sf::Vector2f(window_length / 2, 50));

    sf::Text text_the_word;
    text_the_word.setFont(font);
    text_the_word.setString("Answer is: " + the_word);
    text_the_word.setCharacterSize(50);
    text_the_word.setFillColor(sf::Color::Black);
    sf::FloatRect rect_word = text_the_word.getLocalBounds();
    text_the_word.setOrigin(
            rect_word.left + rect_word.width / 2,
            rect_word.top + rect_word.height / 2);
    text_the_word.setPosition(sf::Vector2f(window_length / 2, 150));

    st_button result_buttons[2];

    int delta_height = 0;

    std::string button_names[2] = {"Again", " Quit"};
    int text_size = 40;

    for (int i = 0; i <= 1; ++i) {
        result_buttons[i].form.setSize(sf::Vector2f(300, 100));
        result_buttons[i].form.move(400, 220 + delta_height);
        result_buttons[i].form.setFillColor(sf::Color(255, 255, 255));
        result_buttons[i].form.setOutlineThickness(1);
        result_buttons[i].form.setOutlineColor(sf::Color::Black);

        result_buttons[i].text.setFont(font);
        result_buttons[i].text.setString(button_names[i]);
        result_buttons[i].text.setCharacterSize(text_size);
        result_buttons[i].text.setFillColor(sf::Color::Black);
        result_buttons[i].text.setOrigin(
                -400 - text_size - 25 - 30, -35 - delta_height - 210);

        delta_height += 100 + 10;
    }

    if (!is_win)
        sf::sleep(sf::seconds(3));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            int delta = 0;

            for (int i = 0; i <= 1; ++i) {
                if (sf::IntRect(400, 220 + delta, 300, 100)
                            .contains(sf::Mouse::getPosition(window))) {
                    result_buttons[i].form.setFillColor(sf::Color(
                            (int)PrButColor::r,
                            (int)PrButColor::g,
                            (int)PrButColor::b));
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        if (i == 0)
                            open_theme_window(window);
                        if (i == 1)
                            window.close();
                    }
                } else
                    result_buttons[i].form.setFillColor(sf::Color::White);

                delta += 110;
            }
            if (is_window_closed(event)) {
                window.close();
            }
        }

        window.clear(
                sf::Color((int)BgColor::r, (int)BgColor::g, (int)BgColor::b));

        window.draw(text_result);
        window.draw(text_the_word);
        for (int i = 0; i <= 1; ++i) {
            window.draw(result_buttons[i].form);
            window.draw(result_buttons[i].text);
        }

        window.display();
    }

    return SUCCESS;
}
