/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** main
*/

#include <vector>
#include <thread>
#include <iostream>
#include <memory>
#include "IThread/Thread.hpp"
#include "IMutex/Mutex.hpp"
#include "IMutex/ScopedLock/ScopedLock.hpp"
#include "ISafeQueue/SafeQueue.hpp"
#include "Plazza/Kitchen/Kitchen.hpp"
#include <random>

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    std::unique_ptr<IKitchen> kitchen = std::make_unique<Kitchen>(2, 1);
    std::vector<std::shared_ptr<IPizza>> pizzaList;

    kitchen->createCooks();
    kitchen->createPantry();
    return 0;
}
