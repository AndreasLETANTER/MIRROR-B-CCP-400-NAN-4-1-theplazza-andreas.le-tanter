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

std::string Parser::getInputString(std::string t_input, size_t *t_i)
{
    std::string str;
    int start = *t_i;

    for (; t_input[*t_i] != ' ' && t_input[*t_i] != ';' && *t_i < t_input.size(); (*t_i)++);
    str = t_input.substr(start, *t_i - start);
    return str;
}

bool Parser::isAuthorized(const std::string& t_inputParam)
{
    std::regex pattern("x[0-9]");

    for (size_t i = 0; i < m_authorizedPizzas.size(); i++) {
        if (t_inputParam == m_authorizedPizzas[i])
            return true;
    }
    for (size_t i = 0; i < m_authorizedSizes.size(); i++) {
        if (t_inputParam == m_authorizedSizes[i])
            return true;
    }
    if (std::regex_match(t_inputParam, pattern))
        return true;
    return false;
}

bool Parser::isInVector(std::vector<std::string> t_vector, const std::string& t_str_to_find)
{
    for (size_t i = 0; i < t_vector.size(); i++) {
        if (t_vector[i] == t_str_to_find)
            return true;
    }
    return false;
}

PizzaSize Parser::stringToPizzaSize(const std::string& t_str)
{
    if (t_str == "S")
        return PizzaSize::S;
    if (t_str == "M")
        return PizzaSize::M;
    if (t_str == "L")
        return PizzaSize::L;
    if (t_str == "XL")
        return PizzaSize::XL;
    else
        return PizzaSize::XXL;
}

std::shared_ptr<IPizza> Parser::setPizza(const std::string &t_pizzaName, const std::string &t_pizzaSize)
{
    if (t_pizzaName == "regina")
        return std::make_shared<ReginaPizza>(stringToPizzaSize(t_pizzaSize));
    else if (t_pizzaName == "margarita")
        return std::make_shared<MargaritaPizza>(stringToPizzaSize(t_pizzaSize));
    else if (t_pizzaName == "americana")
        return std::make_shared<AmericanaPizza>(stringToPizzaSize(t_pizzaSize));
    else
        return std::make_shared<FantasiaPizza>(stringToPizzaSize(t_pizzaSize));
}

std::vector<std::shared_ptr<IPizza>> Parser::setPizzas(std::vector<std::string> t_inputs)
{
    unsigned long i = 0;
    int nbPizzas = 0;
    std::vector<std::shared_ptr<IPizza>> pizzas;
    std::shared_ptr<IPizza> pizza;

    if (t_inputs.empty())
        return {};
    while (i < t_inputs.size()) {
        pizza = setPizza(t_inputs[i], t_inputs[i + 1]);
        for (size_t j = 0; j < t_inputs[i + 2].size(); j++) {
            if (isdigit(t_inputs[i + 2][j]))
                nbPizzas = std::stoi(t_inputs[i + 2].substr(j, t_inputs[i + 2].size()));
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
    for (size_t i = 0; i < input.size();) {
        inputParam = getInputString(input, &i);
        if (isAuthorized(inputParam))
            authorized_inputs.push_back(inputParam);
        else
            return std::vector<std::shared_ptr<IPizza>>();
        while ((input[i] == ' ' || input[i] == ';') && i < input.size())
            i++;
    }
    return setPizzas(authorized_inputs);
}
