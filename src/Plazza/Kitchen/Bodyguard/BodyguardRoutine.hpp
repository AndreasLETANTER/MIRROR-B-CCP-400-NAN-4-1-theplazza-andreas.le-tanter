/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** BodyguardRoutine
*/

#pragma once
#include "../Kitchen.hpp"

void BodyguardRoutine(std::shared_ptr<ISafeQueue<std::shared_ptr<IPizza>>> t_pizzaPool, std::vector<std::shared_ptr<IThread>> m_cookPool, std::shared_ptr<bool> t_kitchenNeedExit);
