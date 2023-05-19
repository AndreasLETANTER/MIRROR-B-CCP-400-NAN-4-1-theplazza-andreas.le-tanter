/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** AmericanaPizza
*/

#include "AmericanaPizza.hpp"

/***
 * @brief Construct a new Americana Pizza object
 * @details This constructor initialize the type, size, cooking time and ingredients of the pizza
 * @param t_size The size of the pizza
 * @return An instance of AmericanaPizza
*/
AmericanaPizza::AmericanaPizza(PizzaSize t_size)
{
    m_type = PizzaType::Americana;
    m_size = t_size;
    m_cookingTime = PizzaCookingTime::Two;
    addIngredientToVector(PizzaIngredient::Dough);
    addIngredientToVector(PizzaIngredient::Tomato);
    addIngredientToVector(PizzaIngredient::Gruyere);
    addIngredientToVector(PizzaIngredient::Steak);
}
