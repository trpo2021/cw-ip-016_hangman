#include "theme_window.h"

const int theme_button_length = 300;
const int theme_button_height = 100;
const int theme_b_coord_length = 400;
const int theme_b_coord_height = 20;

void create_theme_buttons(st_button buttons[], int amount, sf::Font& font)
{
    const int theme_t_coord_length = theme_b_coord_length + 65;
    const int theme_t_coord_height = 45;

    int delta_height = 0;

    std::string button_names[amount]
            = {" Random",
               " Animals",
               "Countries",
               "  Nature",
               "  School",
               "   Sport"};

    for (int i = random_t; i < amount; ++i) {
        buttons[i].form.setSize(
                sf::Vector2f(theme_button_length, theme_button_height));
        buttons[i].form.move(
                theme_b_coord_length, theme_b_coord_height + delta_height);
        buttons[i].form.setFillColor(sf::Color::White);
        buttons[i].form.setOutlineThickness(1);
        buttons[i].form.setOutlineColor(sf::Color::Black);

        buttons[i].text.setFont(font);
        buttons[i].text.setPosition(
                theme_t_coord_length, theme_t_coord_height + delta_height);
        buttons[i].text.setString(button_names[i]);
        buttons[i].text.setCharacterSize(40);
        buttons[i].text.setFillColor(sf::Color::Black);

        delta_height += theme_button_height + 10;
    }
}

int open_theme_window(sf::RenderWindow& window)
{
    sf::Font font;
    if (!font.loadFromFile("../res/sansation.ttf")) {
        return CANNOT_LOAD_FONT;
    }

    st_button theme_buttons[sport + 1];
    create_theme_buttons(theme_buttons, sport + 1, font);

    sf::sleep(sf::seconds(0.2));

    while (window.isOpen()) {
        int choosen_theme = -1;

        for (int i = random_t; i <= sport; ++i) {
            if (sf::IntRect(
                        theme_b_coord_length,
                        theme_b_coord_height + 110 * i,
                        theme_button_length,
                        theme_button_height)
                        .contains(sf::Mouse::getPosition(window))) {
                theme_buttons[i].form.setFillColor(sf::Color(
                        (int)PrButColor::r,
                        (int)PrButColor::g,
                        (int)PrButColor::b));
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    choosen_theme = i;
                    open_game_window(window, &choosen_theme);
                }
            } else
                theme_buttons[i].form.setFillColor(sf::Color::White);
        }

        window.clear(
                sf::Color((int)BgColor::r, (int)BgColor::g, (int)BgColor::b));

        for (int i = random_t; i <= sport; ++i) {
            window.draw(theme_buttons[i].form);
            window.draw(theme_buttons[i].text);
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
