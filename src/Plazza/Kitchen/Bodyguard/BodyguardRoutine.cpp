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

void BodyguardRoutine(std::vector<std::shared_ptr<IThread>> m_cookPool, bool *t_kitchenNeedExit, size_t *t_nbPizzaMax, std::shared_ptr<IMutex> t_mutex)
{
    Timer timer;
    timer.StartTimer();
    size_t nbPizza = 0;

    while (true) {
        t_mutex->lock();
        nbPizza = *t_nbPizzaMax;
        t_mutex->unlock();
        if (nbPizza == 0) {
            if (timer.GetElapsedTime() >= 5) {
                exitALlCooks(m_cookPool);
                t_mutex->lock();
                *t_kitchenNeedExit = true;
                t_mutex->unlock();
                return;
            }
        } else if (nbPizza > 0) {
            timer.ResetTimer();
        }
    }
}