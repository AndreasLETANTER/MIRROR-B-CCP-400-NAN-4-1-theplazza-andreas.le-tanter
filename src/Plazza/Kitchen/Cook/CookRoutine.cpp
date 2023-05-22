/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** Cook
*/

#include "../Kitchen.hpp"
#include <iostream>

/**
 * @brief Routine for the cook thread
 * @details This function is the routine for the cook thread (the thread that cook the pizza)
 * @param t_timeMultiplier the multiplier for the cooking time
 * @param t_pizzaPool the pool of pizza
 * @param t_nbPizzaMax the number of pizza max that the kitchen can cook
 * @param t_mutex the mutex for the number of pizza max
*/
void cookRoutine(double t_timeMultiplier, std::shared_ptr<ISafeQueue<std::shared_ptr<IPizza>>> t_pizzaPool, size_t *t_nbPizzaMax, std::shared_ptr<IMutex> t_mutex)
{
    bool cookWorking = true;

    while (cookWorking) {
        auto pizza = t_pizzaPool->pop();
        double cookingTime = pizza->getCookingTime();
        unsigned int timeMilliseconds = (cookingTime * t_timeMultiplier) * 1000;
        std::this_thread::sleep_for(std::chrono::milliseconds(timeMilliseconds));
        t_mutex->lock();
        (*t_nbPizzaMax) -= 1;
        t_mutex->unlock();
        printf("Pizza %d is ready\n", pizza->getType());
    }
}
