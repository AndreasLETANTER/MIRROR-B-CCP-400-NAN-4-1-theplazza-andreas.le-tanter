/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** CookRoutine
*/

#pragma once
#include "../Kitchen.hpp"

void CookRoutine(double t_timeMultiplier, std::shared_ptr<ISafeQueue<std::shared_ptr<IPizza>>> t_pizzaPool);
