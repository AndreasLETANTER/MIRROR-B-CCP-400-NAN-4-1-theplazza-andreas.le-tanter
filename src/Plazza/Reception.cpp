/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** IReception
*/

#include "Reception.hpp"
#include "Parser.hpp"

#include <iostream>

Reception::Reception()
{
}

Reception::~Reception()
{
}

void Reception::waitCommands()
{
    Parser parser;

    while (m_is_running) {
        std::vector<std::shared_ptr<IPizza>> pizza = parser.getInput();
        for (auto &i : pizza) {
            sendPizzaToQueue(i);
        }
    }
}

void Reception::sendPizzaToQueue(std::shared_ptr<IPizza> pizza)
{
    if (pizza == nullptr)
        return;
    m_queue.push(pizza);
}

void Reception::createKitchen()
{
}

void Reception::sendPizzaToKitchen()
{
}
