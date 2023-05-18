/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** Cook
*/

#include "../Kitchen.hpp"
#include <iostream>

void CookRoutine(double t_timeMultiplier, std::shared_ptr<ISafeQueue<std::shared_ptr<IPizza>>> t_pizzaPool)
{
    while (true) {
        auto pizza = t_pizzaPool->pop();
        double cookingTime = pizza->getCookingTime();
        int timeMilliseconds = (cookingTime * t_timeMultiplier) * 1000;
        std::this_thread::sleep_for(std::chrono::milliseconds(timeMilliseconds));
        printf("Pizza %d is ready\n", pizza->getType());
    }
}
