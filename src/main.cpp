/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** main
*/

#include <iostream>
#include <string>

#define EXIT_SUCCESS 0
#define EXIT_ERROR 84

static void print_help_if_needed(const int ac)
{
    if (ac != 4) {
        std::cout << "USAGE: ./plazza [multiplier] [nb_cooks] [time]\n"
                    << "\tmultiplier\tmultiplier for the cooking time of the pizzas\n"
                    << "\tnb_cooks\tnumber of cooks per kitchen\n"
                    << "\ttime\ttime in milliseconds, used by the kitchen stock to replace ingredients"
                    << std::endl;
        exit(EXIT_SUCCESS);
    }
}

static bool is_number(const std::string &str)
{
    if (str.empty()) {
        return false;
    }
    for (const char &c : str) {
        if (!std::isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

int main(const int ac, const char **av)
{
    double multiplier = 0;
    int number_of_cooks = 0;
    int refilling_time = 0;

    print_help_if_needed(ac);
    if (!is_number(av[1]) || !is_number(av[2]) || !is_number(av[3])) {
        std::cerr << "Arguments must be numbers" << std::endl;
        return EXIT_ERROR;
    }
    multiplier = std::stod(av[1]);
    number_of_cooks = std::stoul(av[2]);
    refilling_time = std::stoul(av[3]);
    if (multiplier <= 0 || number_of_cooks <= 0 || refilling_time <= 0) {
        std::cerr << "Arguments must be positive" << std::endl;
        return EXIT_ERROR;
    }
    // Reception class
    return EXIT_SUCCESS;
}
