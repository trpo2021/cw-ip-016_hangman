#include "theme_window.h"

int open_theme_window(sf::RenderWindow& window)
{
    sf::Font font;
    if (!font.loadFromFile("../res/sansation.ttf")) {
        return CANNOT_LOAD_FONT;
    }

    st_button theme_buttons[sport + 1];

    std::string button_names[sport + 1]
            = {" Random",
               " Animals",
               "Countries",
               "  Nature",
               "  School",
               "   Sport"};

    const int button_coord_length = 400;
    const int button_coord_height = 20;
    const int text_size = 40;
    int delta_height = 0;

    for (int i = random_t; i <= sport; ++i) {
        theme_buttons[i].form.setSize(
                sf::Vector2f(menu_button_length, menu_button_height));
        theme_buttons[i].form.move(
                button_coord_length, button_coord_height + delta_height);
        theme_buttons[i].form.setFillColor(sf::Color::White);
        theme_buttons[i].form.setOutlineThickness(button_thickness);
        theme_buttons[i].form.setOutlineColor(sf::Color::Black);

        theme_buttons[i].text.setFont(font);
        theme_buttons[i].text.setString(button_names[i]);
        theme_buttons[i].text.setCharacterSize(text_size);
        theme_buttons[i].text.setFillColor(sf::Color::Black);
        theme_buttons[i].text.setOrigin(
                -button_coord_length - text_size - 25, -delta_height - 45);

        delta_height += menu_button_height + 10;
    }

    while (window.isOpen()) {
        int delta_coord_height = 0;
        int choosen_theme = -1;

        for (int i = random_t; i <= sport; ++i) {
            if (sf::IntRect(
                        button_coord_length,
                        button_coord_height + delta_coord_height,
                        menu_button_length,
                        menu_button_height)
                        .contains(sf::Mouse::getPosition(window))) {
                theme_buttons[i].form.setFillColor(
                        sf::Color(pr_button_r, pr_button_g, pr_button_b));
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    choosen_theme = i;
                    open_game_window(window, &choosen_theme);
                }
            } else
                theme_buttons[i].form.setFillColor(sf::Color::White);

            delta_coord_height += 110;
        }

        window.clear(sf::Color(bg_color_r, bg_color_g, bg_color_b));

        for (int i = random_t; i <= sport; ++i) {
            window.draw(theme_buttons[i].form);
            window.draw(theme_buttons[i].text);
        }

        window.display();

        sf::Event event_close_app;
        if (is_window_closed(window, event_close_app)) {
            window.close();
        }
    }

    return SUCCESS;
}
