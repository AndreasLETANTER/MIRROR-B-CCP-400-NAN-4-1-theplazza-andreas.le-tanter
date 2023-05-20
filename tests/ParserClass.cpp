/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** unit tests for Parser class
*/

#include <criterion/criterion.h>
#include "../src/Plazza/Parser/Parser.hpp"

Test(check_parsing_with_space, GetInputString)
{
    std::string input = "regina XXL x2";
    std::string result;
    Parser parser;
    int i = 0;

    result = parser.getInputString(input, &i);
    cr_assert_eq(result, "regina");
    cr_assert_eq(i, 6);
}

Test(check_parsing_with_semicolon, GetInputString)
{
    std::string input = "regina;XXL x2";
    std::string result;
    Parser parser;
    int i = 0;

    result = parser.getInputString(input, &i);
    cr_assert_eq(result, "regina");
    cr_assert_eq(i, 6);
}

Test(check_parsing_with_string_end, GetInputString)
{
    std::string input = "regina";
    std::string result;
    Parser parser;
    int i = 0;

    result = parser.getInputString(input, &i);
    cr_assert_eq(result, "regina");
    cr_assert_eq(i, 6);
}
