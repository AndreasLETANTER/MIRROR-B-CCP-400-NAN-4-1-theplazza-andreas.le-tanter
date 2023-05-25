/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** IReception
*/

#pragma once

#include "IReception.hpp"
#include "../../ISafeQueue/SafeQueue.hpp"
#include "../Kitchen/Kitchen.hpp"

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <fstream>

/**
 * @brief Interface for the reception class
*/
class Reception : public IReception {
    public:
        /**
         * @brief Constructor of the reception class
         * @details this function create a reception with a parser and a safe queue
        */
        Reception(double multiplier, unsigned int nbCooks, unsigned int refillTime);
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
        void savePizzaToLog(std::shared_ptr<IPizza> pizza) override;
        /**
         * @brief Create a kitchen
         * @details this function create a kitchen with a cook and a pantry
        */
        void createKitchen() override;
        /**
         * @brief send the pizza to be cooked in a kitchen
        */
        void sendPizzaToKitchen(std::shared_ptr<IPizza> pizza) override;

    protected:
    private:
        std::shared_ptr<IPizza> *m_sharedPizza;
        boost::interprocess::managed_shared_memory m_Segment;
        boost::interprocess::interprocess_mutex m_mutex =  boost::interprocess::interprocess_mutex();
        bool m_is_running;
        std::string m_command;
        std::fstream m_file;
        double m_multiplier;
        unsigned int m_nbCooks;
        unsigned int m_refillTime;
};
