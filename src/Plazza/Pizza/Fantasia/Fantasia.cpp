/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** Fantasia
*/

#include "Fantasia.hpp"

Fantasia::Fantasia(PizzaSize t_size)
{
    m_type = PizzaType::Fantasia;
    m_size = t_size;
    m_cookingTime = PizzaCookingTime::Four;
    addIngredientToVector(PizzaIngredient::Dough);
    addIngredientToVector(PizzaIngredient::Tomato);
    addIngredientToVector(PizzaIngredient::Eggplant);
    addIngredientToVector(PizzaIngredient::GoatCheese);
    addIngredientToVector(PizzaIngredient::ChiefLove);
}
