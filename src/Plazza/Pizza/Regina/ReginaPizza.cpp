/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** ReginaPizza
*/

#include "ReginaPizza.hpp"

/**
 * @brief Construct a new Regina Pizza object
 * @details This constructor initialize the type, size, cooking time and ingredients of the pizza
 * @param t_size The size of the pizza
 * @return An instance of ReginaPizza
*/
ReginaPizza::ReginaPizza(PizzaSize t_size)
{
    m_type = PizzaType::Regina;
    m_size = t_size;
    m_cookingTime = PizzaCookingTime::Two;
    addIngredientToVector(PizzaIngredient::Dough);
    addIngredientToVector(PizzaIngredient::Tomato);
    addIngredientToVector(PizzaIngredient::Gruyere);
    addIngredientToVector(PizzaIngredient::Ham);
    addIngredientToVector(PizzaIngredient::Mushrooms);
}
