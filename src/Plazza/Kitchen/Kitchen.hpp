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
        Kitchen(int t_nbCook, double t_timeMultiplier, int t_refillTime);
        ~Kitchen() override;;
        void createCooks() override;
        void createPantry() override;
        bool checkPantry(std::vector<PizzaIngredient> t_ingredientNeeded) override;
        bool isKitchenFilled() override;
        bool doesKitchenNeedExit() override;
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
