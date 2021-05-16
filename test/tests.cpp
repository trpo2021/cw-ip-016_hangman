#include <ctest.h>

#include <libhangman/service.h>

#include <cstring>

CTEST(theme_check, random)
{
    int theme_number = random_t;
    std::string theme;
    std::string word;

    choose_the_word(&theme_number, &theme, &word);

    int unexp_theme = 0;

    ASSERT_NOT_EQUAL(unexp_theme, theme_number);
}

CTEST(theme_check, animals)
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

CTEST(theme_check, countries)
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

CTEST(theme_check, nature)
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

CTEST(theme_check, school)
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

CTEST(theme_check, sport)
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

CTEST(words_check, word_correct_1)
{
    std::string word = "fox";

    bool exp = is_word_correct(word);

    ASSERT_TRUE(exp);
}

CTEST(words_check, word_correct_2)
{
    std::string word = "swimming";

    bool exp = is_word_correct(word);

    ASSERT_TRUE(exp);
}

CTEST(words_check, word_correct_3)
{
    std::string word = "machine";

    bool exp = is_word_correct(word);

    ASSERT_TRUE(exp);
}

CTEST(words_check, word_error_short)
{
    std::string word = "ok";

    bool exp = is_word_correct(word);

    ASSERT_FALSE(exp);
}

CTEST(words_check, word_error_long)
{
    std::string word = "translate";

    bool exp = is_word_correct(word);

    ASSERT_FALSE(exp);
}

CTEST(words_check, word_error_symbols_1)
{
    std::string word = "Game";

    bool exp = is_word_correct(word);

    ASSERT_FALSE(exp);
}

CTEST(words_check, word_error_symbols_2)
{
    std::string word = "staR";

    bool exp = is_word_correct(word);

    ASSERT_FALSE(exp);
}

CTEST(words_check, word_error_symbols_3)
{
    std::string word = "jo_in";

    bool exp = is_word_correct(word);

    ASSERT_FALSE(exp);
}

CTEST(words_check, word_error_symbols_4)
{
    std::string word = "1nature";

    bool exp = is_word_correct(word);

    ASSERT_FALSE(exp);
}

CTEST(words_check, word_error_symbols_5)
{
    std::string word = "k-ey";

    bool exp = is_word_correct(word);

    ASSERT_FALSE(exp);
}

CTEST(words_check, word_error_symbols_6)
{
    std::string word = "poo]l";

    bool exp = is_word_correct(word);

    ASSERT_FALSE(exp);
}

CTEST(words_check, word_error_symbols_7)
{
    std::string word = "notice*";

    bool exp = is_word_correct(word);

    ASSERT_FALSE(exp);
}

CTEST(input_check, symbol_correct_1)
{
    char symbol = 'a';

    int exp = check_input_symbol(symbol);

    ASSERT_EQUAL(SUCCESS, exp);
}

CTEST(input_check, symbol_correct_2)
{
    char symbol = 'm';

    int exp = check_input_symbol(symbol);

    ASSERT_EQUAL(SUCCESS, exp);
}

CTEST(input_check, symbol_correct_3)
{
    char symbol = 'z';

    int exp = check_input_symbol(symbol);

    ASSERT_EQUAL(SUCCESS, exp);
}

CTEST(input_check, symbol_error_1)
{
    char symbol = 'A';

    int exp = check_input_symbol(symbol);

    ASSERT_EQUAL(ERROR_SYMBOL_INPUT, exp);
}

CTEST(input_check, symbol_error_2)
{
    char symbol = '-';

    int exp = check_input_symbol(symbol);

    ASSERT_EQUAL(ERROR_SYMBOL_INPUT, exp);
}

CTEST(input_check, symbol_error_3)
{
    char symbol = 'O';

    int exp = check_input_symbol(symbol);

    ASSERT_EQUAL(ERROR_SYMBOL_INPUT, exp);
}

CTEST(input_check, symbol_error_4)
{
    char symbol = '7';

    int exp = check_input_symbol(symbol);

    ASSERT_EQUAL(ERROR_SYMBOL_INPUT, exp);
}
