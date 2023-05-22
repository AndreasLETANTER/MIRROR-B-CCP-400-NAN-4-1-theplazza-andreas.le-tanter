/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** BodyguardRoutine
*/

#include "BodyguardRoutine.hpp"
#include "../../../Timer/Timer.hpp"

/**
 * @brief Exit all the cooks thread
 * @details This function exit all the cooks
 * @param m_cookPool the pool of cooks
*/
static void exitALlCooks(std::vector<std::shared_ptr<IThread>> t_cookPool)
{
    for (auto &cook : t_cookPool) {
        cook->stopThread();
    }
}

/**
 * @brief Routine for the bodyguard thread
 * @details This function is the routine for the bodyguard thread (the thread that check if the kitchen need to exit)
 * @param m_cookPool the pool of cooks
 * @param t_kitchenNeedExit the boolean that tell if the kitchen need to exit
 * @param t_nbPizzaMax the number of pizza max that the kitchen can cook
 * @param t_mutex the mutex for the number of pizza max
*/
void BodyguardRoutine(std::vector<std::shared_ptr<IThread>> t_cookPool, bool *t_kitchenNeedExit, size_t *t_nbPizzaMax, std::shared_ptr<IMutex> t_mutex)
{
    Timer timer;
    timer.StartTimer();
    size_t nbPizza = 0;
    bool kitchenNeedExit = false;

    while (kitchenNeedExit == false) {
        t_mutex->lock();
        nbPizza = *t_nbPizzaMax;
        t_mutex->unlock();
        if (nbPizza == 0) {
            if (timer.GetElapsedTime() >= 5) {
                exitALlCooks(t_cookPool);
                t_mutex->lock();
                *t_kitchenNeedExit = true;
                kitchenNeedExit = true;
                t_mutex->unlock();
                continue;
            }
        } else if (nbPizza > 0) {
            timer.ResetTimer();
        }
    }
}