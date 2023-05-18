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
#include "Plazza/Pizza/Americana/AmericanaPizza.hpp"
#include "Plazza/Pizza/Fantasia/FantasiaPizza.hpp"
#include "Plazza/Pizza/Margarita/MargaritaPizza.hpp"
#include "Plazza/Pizza/Regina/ReginaPizza.hpp"

int main(int argc, char **argv)
{
    (void)argc;
    std::unique_ptr<IKitchen> kitchen = std::make_unique<Kitchen>(atoi(argv[1]), (double) atof(argv[2]));

    kitchen->createPantry();
    for (int i = 0; i < 10; i++) {
        if (kitchen->isKitchenFilled() == false && kitchen->checkPantry(std::make_shared<ReginaPizza>(PizzaSize::M)->getIngredients()))
            kitchen->addPizzaToPool(std::make_shared<ReginaPizza>(PizzaSize::M));
    }
    kitchen->createCooks();
    return 0;
}
