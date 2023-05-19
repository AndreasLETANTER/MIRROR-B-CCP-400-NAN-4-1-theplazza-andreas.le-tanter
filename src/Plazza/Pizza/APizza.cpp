/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** APizza
*/

#include "APizza.hpp"

/**
 * @brief Get the type of pizza
 * @return the type of pizza
*/
PizzaType APizza::getType() const
{
    return m_type;
}

/**
 * @brief Get the size of pizza
 * @return the size of pizza
*/
PizzaSize APizza::getSize() const
{
    return m_size;
}

/**
 * @brief Get the cooking time of pizza
 * @return the cooking time of pizza
*/
PizzaCookingTime APizza::getCookingTime() const
{
    return m_cookingTime;
}

/**
 * @brief Get the ingredients of pizza
 * @return the ingredients of pizza
*/
std::vector<PizzaIngredient> APizza::getIngredients() const
{
    return m_ingredients;
}

/**
 * @brief Add an ingredient to the vector of ingredients
 * @param t_ingredient ingredient to add
*/
void APizza::addIngredientToVector(PizzaIngredient t_ingredient)
{
    m_ingredients.push_back(t_ingredient);
}
