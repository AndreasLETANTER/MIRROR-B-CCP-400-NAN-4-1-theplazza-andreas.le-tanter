/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** Kitchen
*/

#include "Kitchen.hpp"
#include "Cook/CookRoutine.hpp"
#include "Bodyguard/BodyguardRoutine.hpp"

static void PantryRoutine(std::shared_ptr<IPantry> t_pantry, int t_timeMilliseconds, std::shared_ptr<IMutex> t_mutex)
{
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(t_timeMilliseconds));
        t_mutex->lock();
        t_pantry->addIngredient(PizzaIngredient::Dough, 1);
        t_pantry->addIngredient(PizzaIngredient::Tomato, 1);
        t_pantry->addIngredient(PizzaIngredient::Gruyere, 1);
        t_pantry->addIngredient(PizzaIngredient::Ham, 1);
        t_pantry->addIngredient(PizzaIngredient::Mushrooms, 1);
        t_pantry->addIngredient(PizzaIngredient::Steak, 1);
        t_pantry->addIngredient(PizzaIngredient::Eggplant, 1);
        t_pantry->addIngredient(PizzaIngredient::GoatCheese, 1);
        t_pantry->addIngredient(PizzaIngredient::ChiefLove, 1);
        t_mutex->unlock();
    }
}

Kitchen::Kitchen(int t_nbCook, double t_timeMultiplier, int t_refillTime)
{
    m_nbCook = t_nbCook;
    m_timeMultiplier = t_timeMultiplier;
    m_nbPizzaMax = t_nbCook * 2;
    m_refillTime = t_refillTime;
    m_pantryMutex = std::make_shared<Mutex>();
    m_kitchenNeedExit = std::make_shared<bool>(false);
    createPantry();
    createCooks();
    m_pantryThread = std::make_unique<Thread<decltype(PantryRoutine), decltype(m_pantry), decltype(m_refillTime), decltype(m_pantryMutex)>>(PantryRoutine, m_pantry, m_refillTime, m_pantryMutex);
    m_kitchenBodyguard = std::make_unique<Thread<decltype(BodyguardRoutine), decltype(m_cookPool), decltype(m_kitchenNeedExit), decltype(&m_nbPizza), decltype(m_kitchenMutex)>>(BodyguardRoutine, m_cookPool, m_kitchenNeedExit, &m_nbPizza, m_kitchenMutex);
}

Kitchen::~Kitchen()
{
    m_kitchenBodyguard->joinThread();
    m_pantryThread->stopThread();
}

void Kitchen::createCooks()
{
    for (size_t i = 0; i < m_nbCook; i++) {
        m_cookPool.push_back(std::make_shared<Thread<decltype(CookRoutine), double, decltype(m_pizzaPool), decltype(&m_nbPizza), decltype(m_kitchenMutex)>>(CookRoutine, m_timeMultiplier, m_pizzaPool, &m_nbPizza, m_kitchenMutex));
    }
}

void Kitchen::createPantry()
{
    m_pantry = std::make_shared<Pantry>();
}

bool Kitchen::checkPantry(std::vector<PizzaIngredient> t_ingredientNeeded)
{
    m_pantryMutex->lock();
    for (auto ingredient : t_ingredientNeeded) {
        if (!m_pantry->checkIngredient(ingredient)) {
            m_pantryMutex->unlock();
            return false;
        }
    }
    m_pantryMutex->unlock();
    return true;
}

bool Kitchen::isKitchenFilled()
{
    if (m_pizzaPool->size() == m_nbPizzaMax)
        return true;
    return false;
}

void Kitchen::addPizzaToPool(std::shared_ptr<IPizza> t_pizza)
{
    m_pizzaPool->push(t_pizza);
    m_kitchenMutex->lock();
    m_nbPizza++;
    m_kitchenMutex->unlock();
    m_pantryMutex->lock();
    for (auto &ingredient : t_pizza->getIngredients()) {
        m_pantry->removeIngredient(ingredient, 1);
    }
    m_pantryMutex->unlock();
}

bool Kitchen::doesKitchenNeedExit()
{
    return *m_kitchenNeedExit;
}
