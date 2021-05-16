#include <ctest.h>

#include <libhangman/service.h>

#include <cstring>

CTEST(words_check, theme_random)
{
    int theme_number = random_t;
    std::string theme;
    std::string word;

    choose_the_word(&theme_number, &theme, &word);

    int unexp_theme = 0;

    ASSERT_NOT_EQUAL(unexp_theme, theme_number);
}

CTEST(words_check, theme_animals)
{
    int theme_number = animals;
    std::string theme;
    std::string word;

    choose_the_word(&theme_number, &theme, &word);

    char exp_theme[] = "Animals";

    char* res_theme = new char[word.length() + 1];
    strcpy(res_theme, theme.c_str());

    ASSERT_STR(exp_theme, res_theme);

    delete[] res_theme;
}

CTEST(words_check, theme_countries)
{
    int theme_number = countries;
    std::string theme;
    std::string word;

    choose_the_word(&theme_number, &theme, &word);

    char exp_theme[] = "Countries";

    char* res_theme = new char[word.length() + 1];
    strcpy(res_theme, theme.c_str());

    ASSERT_STR(exp_theme, res_theme);

    delete[] res_theme;
}

CTEST(words_check, theme_nature)
{
    int theme_number = nature;
    std::string theme;
    std::string word;

    choose_the_word(&theme_number, &theme, &word);

    char exp_theme[] = "Nature";

    char* res_theme = new char[word.length() + 1];
    strcpy(res_theme, theme.c_str());

    ASSERT_STR(exp_theme, res_theme);

    delete[] res_theme;
}

CTEST(words_check, theme_school)
{
    int theme_number = school;
    std::string theme;
    std::string word;

    choose_the_word(&theme_number, &theme, &word);

    char exp_theme[] = "School";

    char* res_theme = new char[word.length() + 1];
    strcpy(res_theme, theme.c_str());

    ASSERT_STR(exp_theme, res_theme);

    delete[] res_theme;
}

CTEST(words_check, theme_sport)
{
    int theme_number = sport;
    std::string theme;
    std::string word;

    choose_the_word(&theme_number, &theme, &word);

    char exp_theme[] = "Sport";

    char* res_theme = new char[word.length() + 1];
    strcpy(res_theme, theme.c_str());

    ASSERT_STR(exp_theme, res_theme);

    delete[] res_theme;
}
