/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** IReception
*/

#pragma once

#include "IReception.hpp"
#include "SafeQueue.hpp"

/**
 * @brief Interface for the reception class
*/
class Reception : public IReception {
    public:
        /**
         * @brief Constructor of the reception class
         * @details this function create a reception with a parser and a safe queue
        */
        Reception();
        /**
         * @brief Destructor of the reception class
         * @details this function destroy the reception
        */
        ~Reception();
        /**
         * @brief Wait for commands from the user
         * @details this function is the main loop that use the parser to get the pizza to cook in a vector
        */
        void waitCommands() override;
        /**
         * @brief Send the pizza to the queue
         * @details this function send the pizza to safe queue for the kitchen
        */
        void sendPizzaToQueue(std::shared_ptr<IPizza> pizza) override;
        /**
         * @brief Create a kitchen
         * @details this function create a kitchen with a cook and a pantry
        */
        void createKitchen() override;
        /**
         * @brief send the pizza to be cooked in a kitchen
        */
        void sendPizzaToKitchen() override;

    protected:
    private:
        bool m_is_running;
        std::string m_command;
        SafeQueue<std::shared_ptr<IPizza>> m_queue;
};
