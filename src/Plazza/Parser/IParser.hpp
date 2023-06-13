/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** IParser
*/

#pragma once
#include <vector>
#include <memory>
#include "../Pizza/IPizza.hpp"

/**
 * @brief Interface for the parser class
*/
class IParser {
    public:
        virtual ~IParser() = default;
        /**
         * @brief Get the input from the user
         * @details this function get the input from the user and parse it to get the pizza to cook then return a vector of those pizza
        */
        virtual std::pair<std::vector<std::shared_ptr<IPizza>>, std::string> getInput() = 0;
    protected:
    private:
};
