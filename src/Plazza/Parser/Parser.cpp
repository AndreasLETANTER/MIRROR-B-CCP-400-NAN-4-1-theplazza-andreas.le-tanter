/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Parser class implementation
*/
#include "Parser.hpp"
#include "../Pizza/Americana/AmericanaPizza.hpp"
#include "../Pizza/Fantasia/FantasiaPizza.hpp"
#include "../Pizza/Margarita/MargaritaPizza.hpp"
#include "../Pizza/Regina/ReginaPizza.hpp"
#include <iostream>

std::string Parser::getInputString(std::string input, int *i)
{
    std::string str;
    int start = *i;

    for (; input[*i] != ' ' && input[*i] != ';' && *i < (int)input.size(); (*i)++);
    str = input.substr(start, *i - start);
    return str;
}

bool Parser::isAuthorized(const std::string& inputParam)
{
    std::regex pattern("x[0-9]");

    for (int i = 0; i < (int)authorizedPizzas.size(); i++) {
        if (inputParam == authorizedPizzas[i])
            return true;
    }
    for (int i = 0; i < (int)authorizedSizes.size(); i++) {
        if (inputParam == authorizedSizes[i])
            return true;
    }
    if (std::regex_match(inputParam, pattern))
        return true;
    return false;
}

bool Parser::isInVector(std::vector<std::string> t_vector, const std::string& str_to_find)
{
    for (int i = 0; i < (int)t_vector.size(); i++) {
        if (t_vector[i] == str_to_find)
            return true;
    }
    return false;
}

PizzaSize Parser::stringToPizzaSize(const std::string& str)
{
    if (str == "S") {
        return PizzaSize::S;
    } else if (str == "M") {
        return PizzaSize::M;
    } else if (str == "L") {
        return PizzaSize::L;
    } else if (str == "XL") {
        return PizzaSize::XL;
    } else {
        return PizzaSize::XXL;
    }
}

std::shared_ptr<IPizza> Parser::setPizza(const std::string &pizzaName, const std::string &pizzaSize)
{
    if (pizzaName == "regina")
        return std::make_shared<ReginaPizza>(stringToPizzaSize(pizzaSize));
    else if (pizzaName == "margarita")
        return std::make_shared<MargaritaPizza>(stringToPizzaSize(pizzaSize));
    else if (pizzaName == "americana")
        return std::make_shared<AmericanaPizza>(stringToPizzaSize(pizzaSize));
    else
        return std::make_shared<FantasiaPizza>(stringToPizzaSize(pizzaSize));
}

std::vector<std::shared_ptr<IPizza>> Parser::setPizzas(std::vector<std::string> inputs)
{
    unsigned long i = 0;
    int nbPizzas = 0;
    std::vector<std::shared_ptr<IPizza>> pizzas;
    std::shared_ptr<IPizza> pizza;

    if (inputs.empty())
        return {};
    while (i < inputs.size()) {
        pizza = setPizza(inputs[i], inputs[i + 1]);
        for (int j = 0; j < (int)inputs[i + 2].size(); j++) {
            if (isdigit(inputs[i + 2][j]))
                nbPizzas = std::stoi(inputs[i + 2].substr(j, inputs[i + 2].size()));
        }
        for (int j = 0; j < nbPizzas; j++)
            pizzas.push_back(pizza);
        i += 3;
    }
    return pizzas;
}

std::vector<std::shared_ptr<IPizza>> Parser::getInput()
{
    std::string input;
    std::string inputParam;
    std::vector<std::string> authorized_inputs;

    std::getline(std::cin, input);
    for (int i = 0; i < (int)input.size();) {
        inputParam = getInputString(input, &i);
        if (isAuthorized(inputParam))
            authorized_inputs.push_back(inputParam);
        else
            return {};
        while ((input[i] == ' ' || input[i] == ';') && i < (int)input.size())
            i++;
    }
    return setPizzas(authorized_inputs);
}
