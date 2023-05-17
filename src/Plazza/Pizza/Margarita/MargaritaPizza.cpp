/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** MargaritaPizza
*/

#include "MargaritaPizza.hpp"

MargaritaPizza::MargaritaPizza(PizzaSize t_size)
{
    m_type = PizzaType::Margarita;
    m_size = t_size;
    m_cookingTime = PizzaCookingTime::One;
    addIngredientToVector(PizzaIngredient::Dough);
    addIngredientToVector(PizzaIngredient::Tomato);
    addIngredientToVector(PizzaIngredient::Gruyere);
}
