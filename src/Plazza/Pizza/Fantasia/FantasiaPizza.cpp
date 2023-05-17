/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** FantasiaPizza
*/

#include "FantasiaPizza.hpp"

/**
 * @brief Construct a new Fantasia Pizza object
 * @details This constructor initialize the type, size, cooking time and ingredients of the pizza
 * @param t_size The size of the pizza
 * @return An instance of FantasiaPizza
*/
FantasiaPizza::FantasiaPizza(PizzaSize t_size)
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
