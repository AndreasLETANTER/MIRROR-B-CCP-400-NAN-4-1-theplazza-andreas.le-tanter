/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** BodyguardRoutine
*/

#include "BodyguardRoutine.hpp"
#include "../../../Timer/Timer.hpp"

static void exitALlCooks(std::vector<std::shared_ptr<IThread>> m_cookPool)
{
    for (auto &cook : m_cookPool) {
        cook->stopThread();
    }
}
#include <iostream>
void BodyguardRoutine(std::shared_ptr<ISafeQueue<std::shared_ptr<IPizza>>> t_pizzaPool, std::vector<std::shared_ptr<IThread>> m_cookPool, std::shared_ptr<bool> t_kitchenNeedExit)
{
    Timer timer;
    timer.StartTimer();

    while (true) {
        if (t_pizzaPool->size() == 0) {
            if (timer.GetElapsedTimeInMilliSeconds() >= 5000) {
                exitALlCooks(m_cookPool);
                *t_kitchenNeedExit = true;
                return;
            }
        } else if (t_pizzaPool->size() > 0) {
            timer.ResetTimer();
        }
    }
}