/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** BodyguardRoutine
*/

#pragma once
#include "../Kitchen.hpp"

/**
 * @brief Routine for the bodyguard thread
 * @details This function is the routine for the bodyguard thread (the thread that check if the kitchen need to exit)
 * @param m_cookPool the pool of cooks
 * @param t_kitchenNeedExit the boolean that tell if the kitchen need to exit
 * @param t_nbPizzaMax the number of pizza max that the kitchen can cook
 * @param t_mutex the mutex for the number of pizza max
*/
void BodyguardRoutine(std::vector<std::shared_ptr<IThread>> m_cookPool, bool *t_kitchenNeedExit, size_t *t_nbPizzaMax, std::shared_ptr<IMutex> t_mutex);
