/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** IReception
*/

#include "Reception.hpp"
#include "../Parser/Parser.hpp"

#include <iostream>
#include <unistd.h>

Reception::Reception() : m_queue(std::make_shared<Mutex>())
{
    m_is_running = true;
}

Reception::~Reception()
{
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
    m_queue.push(pizza);
}

void Reception::createKitchen()
{
    try {
        pid_t pid = fork();
        if (pid == 0) {
            
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Reception::sendPizzaToKitchen()
{
}
