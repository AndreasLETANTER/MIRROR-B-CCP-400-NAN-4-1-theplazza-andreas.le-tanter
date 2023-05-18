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
    std::string getInputString(std::string input, int *i);
    bool isAuthorized(std::string inputParam);
private:
    std::vector<std::string> _input;
    std::vector<std::string> _args;
    std::vector<std::string> authorizedInputs =
        {"regina",
         "margarita",
         "americana",
         "fantasia",
         "S",
         "M",
         "L",
         "XL",
         "XXL"};
protected:
};
