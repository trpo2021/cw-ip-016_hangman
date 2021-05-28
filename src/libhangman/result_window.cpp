#include "result_window.h"

const int result_button_length = 300;
const int result_button_height = 100;
const int result_b_coord_length = 400;
const int result_b_coord_height = 220;

void create_result_buttons(st_button buttons[], int amount, sf::Font& font)
{
    const int result_t_coord_length = result_b_coord_length + 95;
    const int result_t_coord_height = result_b_coord_height + 25;

    int delta_height = 0;

    std::string button_names[amount] = {"Again", " Quit"};

    for (int i = 0; i < amount; ++i) {
        buttons[i].form.setSize(
                sf::Vector2f(result_button_length, result_button_height));
        buttons[i].form.move(
                result_b_coord_length, result_b_coord_height + delta_height);
        buttons[i].form.setFillColor(sf::Color::White);
        buttons[i].form.setOutlineThickness(1);
        buttons[i].form.setOutlineColor(sf::Color::Black);

        buttons[i].text.setFont(font);
        buttons[i].text.setPosition(
                result_t_coord_length, result_t_coord_height + delta_height);
        buttons[i].text.setString(button_names[i]);
        buttons[i].text.setCharacterSize(40);
        buttons[i].text.setFillColor(sf::Color::Black);

        delta_height += 110;
    }
}

void create_text_result(sf::Text& text, bool is_win, sf::Font& font)
{
    text.setFont(font);

    if (is_win)
        text.setString("You win!");
    else
        text.setString("You lose!");

    text.setStyle(sf::Text::Underlined);
    text.setCharacterSize(70);
    text.setFillColor(sf::Color::Black);
    sf::FloatRect rect_res = text.getLocalBounds();
    text.setOrigin(
            rect_res.left + rect_res.width / 2,
            rect_res.top + rect_res.height / 2);
    text.setPosition(sf::Vector2f(window_length / 2, 50));
}

void create_text_gword(sf::Text& text, std::string word_in_text, sf::Font& font)
{
    text.setFont(font);
    text.setString("Answer is: " + word_in_text);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Black);
    sf::FloatRect rect_word = text.getLocalBounds();
    text.setOrigin(
            rect_word.left + rect_word.width / 2,
            rect_word.top + rect_word.height / 2);
    text.setPosition(sf::Vector2f(window_length / 2, 150));
}

int open_result_window(
        sf::RenderWindow& window, bool is_win, std::string the_word)
{
    sf::Font font;
    if (!font.loadFromFile("../res/sansation.ttf")) {
        return CANNOT_LOAD_FONT;
    }

    sf::Text text_result;
    create_text_result(text_result, is_win, font);

    sf::Text text_the_word;
    create_text_gword(text_the_word, the_word, font);

    const int result_buttons_amount = 2;
    st_button result_buttons[result_buttons_amount];
    create_result_buttons(result_buttons, result_buttons_amount, font);

    if (!is_win)
        sf::sleep(sf::seconds(3));

    while (window.isOpen()) {
        int go_next = -1;

        for (int i = 0; i < result_buttons_amount; ++i) {
            if (sf::IntRect(
                        result_b_coord_length,
                        result_b_coord_height + 110 * i,
                        result_button_length,
                        result_button_height)
                        .contains(sf::Mouse::getPosition(window))) {
                result_buttons[i].form.setFillColor(sf::Color(
                        (int)PrButColor::r,
                        (int)PrButColor::g,
                        (int)PrButColor::b));
                go_next = i;
            } else
                result_buttons[i].form.setFillColor(sf::Color::White);
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

        window.draw(text_result);
        window.draw(text_the_word);
        for (int i = 0; i <= 1; ++i) {
            window.draw(result_buttons[i].form);
            window.draw(result_buttons[i].text);
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
