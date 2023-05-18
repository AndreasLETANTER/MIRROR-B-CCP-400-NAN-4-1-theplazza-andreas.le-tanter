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
        Kitchen(int t_nbCook, double t_timeMultiplier);
        ~Kitchen() override;;
        void createCooks() override;
        void createPantry() override;
        bool checkPantry(std::vector<PizzaIngredient> t_ingredientNeeded) override;
        bool isKitchenFilled() override;
        void addPizzaToPool(std::shared_ptr<IPizza> t_pizza) override;

    protected:
    private:
        std::unique_ptr<IPantry> m_pantry;
        std::shared_ptr<IMutex> _mutex = std::make_shared<Mutex>();
        std::shared_ptr<ISafeQueue<std::shared_ptr<IPizza>>> m_pizzaPool = std::make_shared<SafeQueue<std::shared_ptr<IPizza>>>(_mutex);
        std::vector<std::unique_ptr<IThread>> m_cookPool;
        double m_timeMultiplier;
        int m_nbCook;
        int m_nbPizzaMax;
        int m_nbCurrentPizza;
};
