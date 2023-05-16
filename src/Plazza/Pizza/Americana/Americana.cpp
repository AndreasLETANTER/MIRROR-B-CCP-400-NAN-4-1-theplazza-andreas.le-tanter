/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** Americana
*/

#include "Americana.hpp"

Americana::Americana(PizzaSize t_size)
{
    m_type = PizzaType::Americana;
    m_size = t_size;
    m_cookingTime = PizzaCookingTime::Two;
    addIngredientToVector(PizzaIngredient::Dough);
    addIngredientToVector(PizzaIngredient::Tomato);
    addIngredientToVector(PizzaIngredient::Gruyere);
    addIngredientToVector(PizzaIngredient::Steak);
}
