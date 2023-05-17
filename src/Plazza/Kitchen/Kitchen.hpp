/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** Kitchen
*/

#pragma once
#include "IKitchen.hpp"
#include "Pantry/Pantry.hpp"

class Kitchen : public IKitchen {
    public:
        Kitchen() = default;
        ~Kitchen() override = default;
        void createCook() override;
        void createPantry() override;
        bool checkPantry(std::vector<PizzaIngredient> t_ingredientNeeded) override;
        bool isKitchenFilled() override;
        void addPizzaToPool(std::shared_ptr<IPizza> t_pizza) override;

    protected:
    private:
        std::unique_ptr<IPantry> m_pantry;
        std::vector<std::shared_ptr<IPizza>> m_pizzaPool;
};
