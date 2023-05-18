/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** Kitchen
*/

#include "Kitchen.hpp"
#include "Cook/CookRoutine.hpp"

Kitchen::Kitchen(int t_nbCook, double t_timeMultiplier)
{
    m_nbCook = t_nbCook;
    m_timeMultiplier = t_timeMultiplier;
    m_nbPizzaMax = t_nbCook * 2;
    m_nbCurrentPizza = 0;
}

Kitchen::~Kitchen()
{
    for (auto &cook : m_cookPool) {
        cook->joinThread();
    }
}

void Kitchen::createCooks()
{
    for (int i = 0; i < m_nbCook; i++) {
        m_cookPool.push_back(std::make_unique<Thread<decltype(CookRoutine), double, decltype(m_pizzaPool)>>(CookRoutine, m_timeMultiplier, m_pizzaPool));
    }
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
    if (m_nbCurrentPizza == m_nbPizzaMax)
        return true;
    return false;
}

void Kitchen::addPizzaToPool(std::shared_ptr<IPizza> t_pizza)
{
    m_pizzaPool->push(t_pizza);
    m_nbCurrentPizza++;
    for (auto &ingredient : t_pizza->getIngredients()) {
        m_pantry->removeIngredient(ingredient, 1);
    }
}
