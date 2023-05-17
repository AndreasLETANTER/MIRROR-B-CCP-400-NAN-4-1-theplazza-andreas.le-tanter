/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** Pantry
*/

#include "Pantry.hpp"

Pantry::Pantry()
{
    m_pantry[PizzaIngredient::Dough] = 5;
    m_pantry[PizzaIngredient::Tomato] = 5;
    m_pantry[PizzaIngredient::Gruyere] = 5;
    m_pantry[PizzaIngredient::Ham] = 5;
    m_pantry[PizzaIngredient::Mushrooms] = 5;
    m_pantry[PizzaIngredient::Steak] = 5;
    m_pantry[PizzaIngredient::Eggplant] = 5;
    m_pantry[PizzaIngredient::GoatCheese] = 5;
    m_pantry[PizzaIngredient::ChiefLove] = 5;
}

void Pantry::addIngredient(PizzaIngredient t_ingredient, int t_nb_ingredient)
{
    m_pantry[t_ingredient] += t_nb_ingredient;
}

void Pantry::removeIngredient(PizzaIngredient t_ingredient, int t_nb_ingredient)
{
    m_pantry[t_ingredient] -= t_nb_ingredient;

    if (m_pantry[t_ingredient] < 0)
        m_pantry[t_ingredient] = 0;
}

bool Pantry::checkIngredient(PizzaIngredient t_ingredient)
{
    if (m_pantry[t_ingredient] > 0)
        return true;
    return false;
}
