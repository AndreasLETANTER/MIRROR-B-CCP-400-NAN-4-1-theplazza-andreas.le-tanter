/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

void Kitchen::createCook()
{
}

void Kitchen::createPantry()
{
    m_pantry = std::make_unique<Pantry>();
}

bool Kitchen::checkPantry(std::vector<PizzaIngredient> t_ingredientNeeded)
{
    for (auto ingredient : t_ingredientNeeded) {
        if (!m_pantry->checkIngredient(ingredient))
            return false;
    }
    return true;
}

bool Kitchen::isKitchenFilled()
{
    return false;
}

void Kitchen::addPizzaToPool(std::shared_ptr<IPizza> t_pizza)
{
    (void)t_pizza;
}
