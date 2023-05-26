/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** IReception
*/

#pragma once

#include <memory>

#include "../Pizza/IPizza.hpp"

/**
 * @brief Interface for the reception class
*/
class IReception {
    public:
        virtual ~IReception() = default;
        /**
         * @brief Wait for commands from the user
         * @details this function is the main loop that use the parser to get the pizza to cook in a vector
        */
        virtual void waitCommands() = 0;
        /**
         * @brief save the pizza into a log file
         * @param pizza the pizza to save
        */
        virtual void savePizzaToLog(std::shared_ptr<IPizza> pizza) = 0;
        /**
         * @brief Create a kitchen
         * @details this function create a kitchen with a cook and a pantry
        */
        virtual void createKitchen() = 0;
        /**
         * @brief send the pizza to be cooked in a kitchen
        */
       virtual void sendPizzaToKitchen(std::shared_ptr<IPizza> pizza) = 0;

    protected:
    private:
};
