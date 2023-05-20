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

Test(check_valid_pizza_name, IsAuthorized)
{
    std::string input = "regina";
    Parser parser;

    cr_assert_eq(parser.isAuthorized(input), true);
}

Test(check_invalid_pizza_name, IsAuthorized)
{
    std::string input = "regin";
    Parser parser;

    cr_assert_eq(parser.isAuthorized(input), false);
}

Test(check_valid_pizza_size, IsAuthorized)
{
    std::string input = "S";
    Parser parser;

    cr_assert_eq(parser.isAuthorized(input), true);
}

Test(check_invalid_pizza_size, IsAuthorized)
{
    std::string input = "T";
    Parser parser;

    cr_assert_eq(parser.isAuthorized(input), false);
}

Test(check_valid_pizza_number, IsAuthorized)
{
    std::string input = "x2";
    Parser parser;

    cr_assert_eq(parser.isAuthorized(input), true);
}

Test(check_invalid_pizza_number, IsAuthorized)
{
    std::string input = "x";
    Parser parser;

    cr_assert_eq(parser.isAuthorized(input), false);
}

Test(check_too_big_pizza_number, IsAuthorized)
{
    std::string input = "x10";
    Parser parser;

    cr_assert_eq(parser.isAuthorized(input), false);
}
