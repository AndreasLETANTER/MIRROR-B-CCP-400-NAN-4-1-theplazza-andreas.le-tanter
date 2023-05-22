/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** IReception
*/

#include "Reception.hpp"
#include "../Parser/Parser.hpp"
#include "../Kitchen/Kitchen.hpp"

#include <iostream>
#include <unistd.h>

/**
 * @brief Construct a new Reception:: Reception object
 * @details this function create the mutex, the queue and open the file 
 * @param multiplier the multiplier for the cooking time
 * @param nbCooks the number of cooks
 * @param refillTime the time to refill the ingredients
*/
Reception::Reception(double multiplier, unsigned int nbCooks, unsigned int refillTime)
{
    m_is_running = true;
    m_multiplier = multiplier;
    m_nbCooks = nbCooks;
    m_refillTime = refillTime;
    m_mutex = std::make_shared<Mutex>();
    m_queue = std::make_shared<SafeQueue<std::shared_ptr<IPizza>>>(m_mutex);
    m_file.open("Pizza.log", std::ios::out);
    waitCommands();
}

/**
 * @brief Destroy the Reception:: Reception object
 * @details this function close the file
*/
Reception::~Reception()
{
    m_file.close();
}

/**
 * @brief Wait for commands from the user
 * @details this function is the main loop that use the parser to get the pizza to cook in a vector
*/
void Reception::waitCommands()
{
    Parser parser;
    std::vector<std::shared_ptr<IPizza>> pizzas;

    while (m_is_running) {
        pizzas = parser.getInput();
        for (auto &i : pizzas) {
            sendPizzaToQueue(i);
            sendPizzaToKitchen();
        }
    }
}

/**
 * @brief Send the pizza to the queue
 * @details this function send the pizza to safe queue for the kitchen
 * @details this function check if the pizza is not null
 * @param pizza the pizza to send
*/
void Reception::sendPizzaToQueue(std::shared_ptr<IPizza> pizza)
{
    if (pizza == nullptr) {
        return;
    }
    try {
        m_file << "Pizza type : " << pizza->getType() << " size : " << pizza->getSize() << std::endl;
        std::cout << "Going to cook Pizza type : " << pizza->getType() << " in size : " << pizza->getSize() << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    m_queue->push(pizza);
}

void Reception::createKitchen()
{
    pid_t pid = fork();

    if (pid == 0) {
        m_kitchens.push_back(std::make_shared<Kitchen>(m_nbCooks, m_multiplier, m_refillTime));
        exit(0);
    } else if (pid == -1) {
        std::cerr << "Error while creating kitchen" << std::endl;
    }
}

void Reception::sendPizzaToKitchen()
{
    std::shared_ptr<IPizza> pizza = m_queue->pop();

    for (auto &kitchen : m_kitchens) {
        if (kitchen->isKitchenFilled() == false && kitchen->checkPantry(pizza->getIngredients()) == true) {
            kitchen->addPizzaToPool(pizza);
            return;
        }
    }
    createKitchen();
    sendPizzaToKitchen();
}
