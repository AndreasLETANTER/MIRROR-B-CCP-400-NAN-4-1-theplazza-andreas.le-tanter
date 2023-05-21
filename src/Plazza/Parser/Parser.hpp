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
    std::vector<std::shared_ptr<IPizza>> setPizzas(std::vector<std::string> inputs);
    std::shared_ptr<IPizza> setPizza(const std::string& pizzaName, const std::string& pizzaSize);
    std::string getInputString(std::string input, int *i);
    bool isAuthorized(const std::string& inputParam);
    bool isInVector(std::vector<std::string> t_vector, const std::string& str_to_find);
    PizzaSize stringToPizzaSize(const std::string& str);
private:
    std::vector<std::string> authorizedPizzas =
        {"regina",
         "margarita",
         "americana",
         "fantasia"};
    std::vector<std::string> authorizedSizes =
        {"S",
         "M",
         "L",
         "XL",
         "XXL"};
protected:
};
