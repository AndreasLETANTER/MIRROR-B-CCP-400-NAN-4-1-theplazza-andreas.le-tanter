/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** BodyguardRoutine
*/

#pragma once
#include "../Kitchen.hpp"

void BodyguardRoutine(std::vector<std::shared_ptr<IThread>> m_cookPool, bool *t_kitchenNeedExit, size_t *t_nbPizzaMax, std::shared_ptr<IMutex> t_mutex);
