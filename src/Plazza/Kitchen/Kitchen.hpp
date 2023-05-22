/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** Kitchen
*/

#pragma once
#include "IKitchen.hpp"
#include "Pantry/Pantry.hpp"
#include "../../ISafeQueue/SafeQueue.hpp"
#include "../../IThread/Thread.hpp"

class Kitchen : public IKitchen {
    public:
        Kitchen() = default;
        /**
         * @brief Construct a new Kitchen object
         * @details This constructor create a kitchen with a number of cook, a time multiplier and a refill time
         * @param t_nbCook the number of cook
         * @param t_timeMultiplier the multiplier for the cooking time
         * @param t_refillTime the refill time for the pantry
         */
        Kitchen(size_t t_nbCook, double t_timeMultiplier, unsigned int t_refillTime);
        /**
         * @brief Destroy the Kitchen:: Kitchen object
         * @details Destroy the Kitchen:: Kitchen object and join the thread of the cooks and the pantry
        */
        ~Kitchen() override;
        /**
         * @brief Create a Cook object (thread that cook the pizza)
        */
        void createCooks() override;
        /**
         * @brief Create a Pantry object (class that contain the ingredients)
        */
        void createPantry() override;
        /**
         * @brief Check if the pantry contain the ingredients needed for the pizza
         * @param t_ingredientNeeded the ingredients needed for the pizza
         * @return true if the pantry contain the ingredients needed for the pizza
         * @return false if the pantry doesn't contain the ingredients needed for the pizza
        */
        bool checkPantry(std::vector<PizzaIngredient> t_ingredientNeeded) override;
        /**
         * @brief Check if the kitchen is filled (if the pool is full or not)
         * @return true if the kitchen is filled
        */
        bool isKitchenFilled() override;
        /**
         * @brief Check if the kitchen need to exit
         * @return true if the kitchen need to exit
         * @return false if the kitchen doesn't need to exit
        */
        bool doesKitchenNeedExit() override;
        /**
         * @brief Add a pizza to the pool
         * @param t_pizza the pizza to add to the pool
         * @details this function add a pizza to the pool of the kitchen (the pool is a vector of pizza that the kitchen will cook)
        */
        void addPizzaToPool(std::shared_ptr<IPizza> t_pizza) override;

    protected:
    private:
        int m_refillTime;
        std::shared_ptr<IPantry> m_pantry;
        std::shared_ptr<IMutex> _mutex = std::make_shared<Mutex>();
        std::shared_ptr<ISafeQueue<std::shared_ptr<IPizza>>> m_pizzaPool = std::make_shared<SafeQueue<std::shared_ptr<IPizza>>>(_mutex);
        std::vector<std::shared_ptr<IThread>> m_cookPool;
        std::unique_ptr<IThread> m_pantryThread;
        std::shared_ptr<IMutex> m_pantryMutex = std::make_shared<Mutex>();
        std::unique_ptr<IThread> m_kitchenBodyguard;
        std::shared_ptr<IMutex> m_kitchenMutex = std::make_shared<Mutex>();
        bool m_kitchenNeedExit;
        double m_timeMultiplier;
        size_t m_nbCook;
        size_t m_nbPizzaMax;
        size_t m_nbPizza;
};
