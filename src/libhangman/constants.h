#pragma once

const int abc_length = 26;

const int ascii_number_0 = 48;
const int ascii_hidden_letter = 95;
const int ascii_letter_a = 97;
const int ascii_letter_z = 122;

const int window_length = 1120;
const int window_height = 700;

const int max_words_amount = 256;
const int max_word_length = 8;
const int min_word_length = 3;

const int theme_amount = 5;

enum class BgColor { r = 255, g = 235, b = 200 };
enum class PrButColor { r = 236, g = 223, b = 255 };

#define SUCCESS 0
#define CANNOT_LOAD_FONT 999
#define CANNOT_OPEN_TXT_FILE 998
#define INCORRECT_WORD_IN_TXT_FILE 997
#define ERROR_SYMBOL_INPUT 996
