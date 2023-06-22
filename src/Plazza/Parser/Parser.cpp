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

/**
 * @brief get a string from the input
 * @details get string from input, starting from index and terminating at delimiter or input end
 * @param t_input input from user
 * @param t_i input index
 * @return a string containing an input param
 */
std::string Parser::getInputString(std::string t_input, size_t *t_i)
{
    std::string str;
    int start = *t_i;

    for (; t_input[*t_i] != ' ' && t_input[*t_i] != ';' && *t_i < t_input.size(); (*t_i)++);
    str = t_input.substr(start, *t_i - start);
    return str;
}

/**
 * @brief check if a string is authorized
 * @details check if string passed as parameter match entries in different string vectors
 * @param t_inputParam parsed input parameter
 * @return a boolean
 */
bool Parser::isAuthorized(const std::string& t_inputParam)
{
    std::regex pattern("x([1-9]{1}|[1-9][0-9])");

    for (size_t i = 0; i < m_authorizedPizzas.size(); i++) {
        if (t_inputParam == m_authorizedPizzas[i])
            return true;
    }
    for (size_t i = 0; i < m_authorizedSizes.size(); i++) {
        if (t_inputParam == m_authorizedSizes[i])
            return true;
    }
    if (std::regex_match(t_inputParam, pattern)) {
        return true;
    }
    return false;
}

/**
 * @brief check if a string is in a vector
 * @param t_vector reference vector
 * @param t_str_to_find string to find
 * @return a boolean
 */
bool Parser::isInVector(std::vector<std::string> t_vector, const std::string& t_str_to_find)
{
    for (size_t i = 0; i < t_vector.size(); i++) {
        if (t_vector[i] == t_str_to_find)
            return true;
    }
    return false;
}

/**
 * @brief convert a string into a PizzaSize type
 * @param t_str pizza size as a string
 * @return a PizzaSize type
 */
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

/**
 * @brief set a Pizza, with a name and a size, and return it
 * @param t_pizzaName name of the pizza
 * @param t_pizzaSize size of the pizza
 * @return shared pointer of IPizza type
 */
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

/**
 * @brief set all pizzas contained in t_inputs
 * @param t_inputs string vector containing all inputs to set pizzas
 * @return vector of shared pointers of IPizza type
 */
std::vector<std::shared_ptr<IPizza>> Parser::setPizzas(std::vector<std::string> t_inputs)
{
    unsigned int nbPizzas = 0;
    std::vector<std::shared_ptr<IPizza>> pizzas;
    std::shared_ptr<IPizza> pizza;

    if (t_inputs.empty())
        return {};
    for (size_t i = 0; i < t_inputs.size(); i+=3) {
        pizza = setPizza(t_inputs[i], t_inputs[i + 1]);
        for (size_t j = 0; j < t_inputs[i + 2].size(); j++) {
            if (isdigit(t_inputs[i + 2][j]))
                nbPizzas = strtoul(t_inputs[i + 2].substr(j, t_inputs[i + 2].size()).c_str(), NULL, 0);
        }
        for (size_t j = 0; j < nbPizzas; j++)
            pizzas.push_back(pizza);
    }
    return pizzas;
}

/**
 * @brief get input from user
 * @details get input from user, parse it, handle errors and create a vector of shared pointers of IPizza type
 * @return result of setPizza() : vector of shared pointers of IPizza type
 */
std::pair<std::vector<std::shared_ptr<IPizza>>, std::string> Parser::getInput()
{
    std::string input;
    std::string inputParam;
    std::vector<std::string> authorized_inputs;

    std::getline(std::cin, input);
    for (size_t i = 0; i < input.size() - 1;) {
        inputParam = getInputString(input, &i);
        if (inputParam == "status") {
            return std::make_pair(std::vector<std::shared_ptr<IPizza>>(), "status");
        }
        if (isAuthorized(inputParam))
            authorized_inputs.push_back(inputParam);
        else
            return std::make_pair(std::vector<std::shared_ptr<IPizza>>(), "error");
        while ((input[i] == ' ' || input[i] == ';') && i < input.size())
            i++;
    }
    return std::make_pair(setPizzas(authorized_inputs), "OK");
}
