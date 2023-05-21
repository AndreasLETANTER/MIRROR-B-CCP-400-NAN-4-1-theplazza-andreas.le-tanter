/*
** EPITECH PROJECT, 2023
** plazza
** File description:
**
*/

#pragma once
#include "IParser.hpp"
#include <regex>

class Parser : public IParser {
public:
    Parser() = default;
    ~Parser() override = default;
    std::vector<std::shared_ptr<IPizza>> getInput() override;
    std::vector<std::shared_ptr<IPizza>> setPizzas(std::vector<std::string> t_inputs);
    std::shared_ptr<IPizza> setPizza(const std::string& t_pizzaName, const std::string& t_pizzaSize);
    std::string getInputString(std::string t_input, size_t *t_i);
    bool isAuthorized(const std::string& t_inputParam);
    bool isInVector(std::vector<std::string> t_vector, const std::string& t_str_to_find);
    PizzaSize stringToPizzaSize(const std::string& t_str);
private:
    std::vector<std::string> m_authorizedPizzas =
        {"regina",
         "margarita",
         "americana",
         "fantasia"};
    std::vector<std::string> m_authorizedSizes =
        {"S",
         "M",
         "L",
         "XL",
         "XXL"};
protected:
};
