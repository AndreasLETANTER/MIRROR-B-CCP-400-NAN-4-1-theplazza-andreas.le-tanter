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

/**
 * @brief Add N ingredient to the pantry
 * @param t_ingredient the ingredient to add
 * @param t_nb_ingredient the number of ingredient to add
*/
void Pantry::addIngredient(PizzaIngredient t_ingredient, int t_nb_ingredient)
{
    m_pantry[t_ingredient] += t_nb_ingredient;
}

/**
 * @brief Remove N ingredient from the pantry
 * @param t_ingredient the ingredient to remove
 * @param t_nb_ingredient the number of ingredient to remove
*/
void Pantry::removeIngredient(PizzaIngredient t_ingredient, int t_nb_ingredient)
{
    m_pantry[t_ingredient] -= t_nb_ingredient;

    if (m_pantry[t_ingredient] < 0)
        m_pantry[t_ingredient] = 0;
}

/**
 * @brief Check if the pantry contain the ingredient
 * @param t_ingredient the ingredient to check
 * @return true if the pantry contain the ingredient
 * @return false if the pantry doesn't contain the ingredient
*/
bool Pantry::checkIngredient(PizzaIngredient t_ingredient)
{
    if (m_pantry[t_ingredient] > 0)
        return true;
    return false;
}
