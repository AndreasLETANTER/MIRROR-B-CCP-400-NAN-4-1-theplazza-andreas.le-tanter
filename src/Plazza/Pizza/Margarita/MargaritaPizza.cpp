/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** MargaritaPizza
*/

#include "MargaritaPizza.hpp"

/**
 * @brief Construct a new Margarita Pizza object
 * @details This constructor initialize the type, size, cooking time and ingredients of the pizza
 * @param t_size The size of the pizza
 * @return An instance of MargaritaPizza
*/
MargaritaPizza::MargaritaPizza(PizzaSize t_size)
{
    m_type = PizzaType::Margarita;
    m_size = t_size;
    m_cookingTime = PizzaCookingTime::One;
    addIngredientToVector(PizzaIngredient::Dough);
    addIngredientToVector(PizzaIngredient::Tomato);
    addIngredientToVector(PizzaIngredient::Gruyere);
}
