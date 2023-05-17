/*
** EPITECH PROJECT, 2023
** plazza
** File description:
**
*/
#include "Parser.hpp"
#include <iostream>
#include <string>

Parser::Parser(int ac, const char **av)
{
    for (int i = 1; i < ac; i++)
        _args.push_back(av[i]);
}

std::string Parser::getInputString(std::string input, int *i)
{
    std::string str;
    int start = *i;

    for (; input[*i] != ' ' && input[*i] != ';' && *i < (int)input.size(); (*i)++);
    str = input.substr(start, *i - start);
    return str;
}

bool Parser::isAuthorized(std::string inputParam)
{
    std::regex pattern("x[0-9]");

    for (int i = 0; i < (int)authorizedInputs.size(); i++) {
        if (inputParam == authorizedInputs[i])
            return true;
    }
    if (std::regex_match(inputParam, pattern))
        return true;
    return false;
}

std::vector<std::shared_ptr<IPizza>> Parser::getInput()
{
    std::string input;
    std::string inputParam;
    bool isInputAuthorized = false;
    std::vector<std::shared_ptr<IPizza>> pizzas;

    std::getline(std::cin, input);
    for (int i = 0; i < (int)input.size(); i++) {
        while (input[i] != ';' && input[i] != ' ' && i < (int)input.size()) {
            inputParam = getInputString(input, &i);
            isInputAuthorized = isAuthorized(inputParam);
            std::cout << "inputParam :" << inputParam << ", isInputAuthorized :" << isInputAuthorized << std::endl;
            i++;
        }
    }
    return pizzas;
}
