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
    size_t i = 0;

    result = parser.getInputString(input, &i);
    cr_assert_eq(result, "regina");
    cr_assert_eq(i, 6);
}

Test(check_parsing_with_semicolon, GetInputString)
{
    std::string input = "regina;XXL x2";
    std::string result;
    Parser parser;
    size_t i = 0;

    result = parser.getInputString(input, &i);
    cr_assert_eq(result, "regina");
    cr_assert_eq(i, 6);
}

Test(check_parsing_with_string_end, GetInputString)
{
    std::string input = "regina";
    std::string result;
    Parser parser;
    size_t i = 0;

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

Test(check_two_digits_pizza_number, IsAuthorized)
{
    std::string input = "x10";
    Parser parser;

    cr_assert_eq(parser.isAuthorized(input), true);
}

Test(check_other_two_digits_pizza_number, IsAuthorized)
{
    std::string input = "x99";
    Parser parser;

    cr_assert_eq(parser.isAuthorized(input), true);
}

Test(check_too_big_pizza_number, IsAuthorized)
{
    std::string input = "x100";
    Parser parser;

    cr_assert_eq(parser.isAuthorized(input), false);
}

Test(check_too_low_pizza_number, IsAuthorized)
{
    std::string input = "x0";
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

Test(Pizza, setPizza)
{
    Parser parser;
    std::string size1 = "S";
    std::string pizza1 = "regina";
    std::shared_ptr<IPizza> result1 = parser.setPizza(pizza1, size1);
    cr_assert_eq(result1->getSize(), PizzaSize::S);
    cr_assert_eq(result1->getType(), PizzaType::Regina);

    std::string size2 = "M";
    std::string pizza2 = "americana";
    std::shared_ptr<IPizza> result2 = parser.setPizza(pizza2, size2);
    cr_assert_eq(result2->getSize(), PizzaSize::M);
    cr_assert_eq(result2->getType(), PizzaType::Americana);

    std::string size3 = "L";
    std::string pizza3 = "fantasia";
    std::shared_ptr<IPizza> result3 = parser.setPizza(pizza3, size3);
    cr_assert_eq(result3->getSize(), PizzaSize::L);
    cr_assert_eq(result3->getType(), PizzaType::Fantasia);

    std::string size4 = "XL";
    std::string pizza4 = "margarita";
    std::shared_ptr<IPizza> result4 = parser.setPizza(pizza4, size4);
    cr_assert_eq(result4->getSize(), PizzaSize::XL);
    cr_assert_eq(result4->getType(), PizzaType::Margarita);

    std::string size5 = "XXL";
    std::string pizza5 = "regina";
    std::shared_ptr<IPizza> result5 = parser.setPizza(pizza5, size5);
    cr_assert_eq(result5->getSize(), PizzaSize::XXL);
    cr_assert_eq(result5->getType(), PizzaType::Regina);
}

Test(vector_of_unique_valid_pizzas, setPizzas)
{
    std::vector<std::string> input = {"regina", "S", "x1", "margarita", "M", "x1"};
    Parser parser;
    std::vector<std::shared_ptr<IPizza>> result = parser.setPizzas(input);

    cr_assert_eq(result[0]->getSize(), PizzaSize::S);
    cr_assert_eq(result[0]->getType(), PizzaType::Regina);

    cr_assert_eq(result[1]->getSize(), PizzaSize::M);
    cr_assert_eq(result[1]->getType(), PizzaType::Margarita);
}

Test(vector_of_multiple_valid_pizzas, setPizzas)
{
    std::vector<std::string> input = {"regina", "S", "x2", "margarita", "M", "x2"};
    Parser parser;
    std::vector<std::shared_ptr<IPizza>> result = parser.setPizzas(input);

    cr_assert_eq(result[0]->getSize(), PizzaSize::S);
    cr_assert_eq(result[0]->getType(), PizzaType::Regina);

    cr_assert_eq(result[1]->getSize(), PizzaSize::S);
    cr_assert_eq(result[1]->getType(), PizzaType::Regina);

    cr_assert_eq(result[2]->getSize(), PizzaSize::M);
    cr_assert_eq(result[2]->getType(), PizzaType::Margarita);

    cr_assert_eq(result[3]->getSize(), PizzaSize::M);
    cr_assert_eq(result[3]->getType(), PizzaType::Margarita);
}
