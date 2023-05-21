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

Test(string_in_vector, isInVector)
{
    std::vector<std::string> vector = {"regina", "margarita", "americana", "fantasia"};
    std::string str = "regina";
    Parser parser;

    cr_assert_eq(parser.isInVector(vector, str), true);
}

Test(string_not_in_vector, isInVector)
{
    std::vector<std::string> vector = {"regina", "margarita", "americana", "fantasia"};
    std::string str = "regin";
    Parser parser;

    cr_assert_eq(parser.isInVector(vector, str), false);
}

Test(Pizza, StringToPizzaSize)
{
    Parser parser;
    std::string input1 = "S";
    PizzaSize result1 = parser.stringToPizzaSize(input1);
    cr_assert_eq(result1, PizzaSize::S);

    std::string input2 = "M";
    PizzaSize result2 = parser.stringToPizzaSize(input2);
    cr_assert_eq(result2, PizzaSize::M);

    std::string input3 = "L";
    PizzaSize result3 = parser.stringToPizzaSize(input3);
    cr_assert_eq(result3, PizzaSize::L);

    std::string input4 = "XL";
    PizzaSize result4 = parser.stringToPizzaSize(input4);
    cr_assert_eq(result4, PizzaSize::XL);

    std::string input5 = "XXL";
    PizzaSize result5 = parser.stringToPizzaSize(input5);
    cr_assert_eq(result5, PizzaSize::XXL);
}
