/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** Kitchen
*/

#include "Kitchen.hpp"
#include "Cook/CookRoutine.hpp"
#include "Bodyguard/BodyguardRoutine.hpp"

/**
 * @brief Pantry routine
 * @details This function is the routine for the pantry thread (the thread that refill the pantry)
 * @param t_pantry the pantry
 * @param t_timeMilliseconds the time in milliseconds between each refill
 * @param t_mutex the mutex for the pantry
 */
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

/**
 * @brief Construct a new Kitchen object
 * @details This constructor create a kitchen with a number of cook, a time multiplier and a refill time
 * @param t_nbCook the number of cook
 * @param t_timeMultiplier the multiplier for the cooking time
 * @param t_refillTime the refill time for the pantry
*/
Kitchen::Kitchen(size_t t_nbCook, double t_timeMultiplier, unsigned int t_refillTime)
{
    m_nbCook = t_nbCook;
    m_timeMultiplier = t_timeMultiplier;
    m_nbPizzaMax = t_nbCook * 2;
    m_refillTime = t_refillTime;
    m_pantryMutex = std::make_shared<Mutex>();
    m_kitchenNeedExit = false;
    createPantry();
    createCooks();
    m_pantryThread = std::make_unique<Thread<decltype(PantryRoutine), decltype(m_pantry), decltype(m_refillTime), decltype(m_pantryMutex)>>(PantryRoutine, m_pantry, m_refillTime, m_pantryMutex);
    m_kitchenBodyguard = std::make_unique<Thread<decltype(BodyguardRoutine), decltype(m_cookPool), decltype(&m_kitchenNeedExit), decltype(&m_nbPizza), decltype(m_kitchenMutex)>>(BodyguardRoutine, m_cookPool, &m_kitchenNeedExit, &m_nbPizza, m_kitchenMutex);
}

/**
 * @brief Destroy the Kitchen:: Kitchen object
 * @details Destroy the Kitchen:: Kitchen object and join the thread of the cooks and the pantry
*/
Kitchen::~Kitchen()
{
    m_kitchenBodyguard->joinThread();
    m_pantryThread->stopThread();
}

/**
 * @brief Create a Cook object (thread that cook the pizza)
*/
void Kitchen::createCooks()
{
    for (size_t i = 0; i < m_nbCook; i++) {
        m_cookPool.push_back(std::make_shared<Thread<decltype(CookRoutine), double, decltype(m_pizzaPool), decltype(&m_nbPizza), decltype(m_kitchenMutex)>>(CookRoutine, m_timeMultiplier, m_pizzaPool, &m_nbPizza, m_kitchenMutex));
    }
}

/**
 * @brief Create a Pantry object (class that contain the ingredients)
*/
void Kitchen::createPantry()
{
    m_pantry = std::make_shared<Pantry>();
}

/**
 * @brief Check if the pantry contain the ingredients needed for the pizza
 * @param t_ingredientNeeded the ingredients needed for the pizza
 * @return true if the pantry contain the ingredients needed for the pizza
 * @return false if the pantry doesn't contain the ingredients needed for the pizza
*/
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

/**
 * @brief Check if the kitchen is filled (if the pool is full or not)
 * @return true if the kitchen is filled
*/
bool Kitchen::isKitchenFilled()
{
    size_t nbPizza = 0;

    m_kitchenMutex->lock();
    nbPizza = m_nbPizza;
    m_kitchenMutex->unlock();
    if (nbPizza == m_nbPizzaMax)
        return true;
    return false;
}

/**
 * @brief Add a pizza to the pool
 * @param t_pizza the pizza to add to the pool
 * @details this function add a pizza to the pool of the kitchen (the pool is a vector of pizza that the kitchen will cook)
*/
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

/**
 * @brief Check if the kitchen need to exit
 * @return true if the kitchen need to exit
 * @return false if the kitchen doesn't need to exit
*/
bool Kitchen::doesKitchenNeedExit()
{
    return m_kitchenNeedExit;
}
