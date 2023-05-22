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

Reception::~Reception()
{
    m_file.close();
}

void Reception::waitCommands()
{
    Parser parser;
    std::vector<std::shared_ptr<IPizza>> pizza;

    while (m_is_running) {
        pizza = parser.getInput();
        for (auto &i : pizza) {
            sendPizzaToQueue(i);
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
    if (pizza == nullptr)
        return;
    try {
        m_file << "Pizza type : " << pizza->getType() << " size : " << pizza->getSize() << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    m_queue->push(pizza);
}

void Reception::createKitchen()
{
    pid_t pid;

    try {
        pid = fork();
        if (pid == 0) {
            Kitchen kitchen(m_nbCooks, m_multiplier, m_refillTime);
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Reception::sendPizzaToKitchen()
{
    addPizzaToPool()
}
