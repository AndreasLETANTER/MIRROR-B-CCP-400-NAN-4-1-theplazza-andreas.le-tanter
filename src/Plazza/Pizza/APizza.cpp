/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** APizza
*/

#include "APizza.hpp"

PizzaType APizza::getType() const
{
    return m_type;
}

PizzaSize APizza::getSize() const
{
    return m_size;
}

PizzaCookingTime APizza::getCookingTime() const
{
    return m_cookingTime;
}

std::vector<PizzaIngredient> APizza::getIngredients() const
{
    return m_ingredients;
}
