/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** IKitchen
*/

#pragma once
#include <vector>
#include "../Pizza/IPizza.hpp"

class IKitchen {
    public:
        virtual ~IKitchen() = 0;
        /**
         * @brief Create a Cook object (thread that cook the pizza)
        */
        virtual void createCook() = 0;
        /**
         * @brief Create a Pantry object (class that contain the ingredients)
        */
        virtual void createPantry() = 0;
        /**
         * @brief Check if the pantry contain the ingredients needed for the pizza
         * @param t_ingredientNeeded the ingredients needed for the pizza
         * @return true if the pantry contain the ingredients needed for the pizza
         * @return false if the pantry doesn't contain the ingredients needed for the pizza
        */
        virtual bool checkPantry(std::vector<PizzaIngredient> t_ingredientNeeded) = 0;
        /**
         * @brief Check if the kitchen is filled (if the pool is full or not)
        */
        virtual bool isKitchenFilled() = 0;
        /**
         * @brief Add a pizza to the pool
         * @param t_pizza the pizza to add to the pool
         * @details this function add a pizza to the pool of the kitchen (the pool is a vector of pizza that the kitchen will cook)
        */
        virtual void addKitchenToPool(std::unique_ptr<IPizza> t_pizza) = 0;

    protected:
    private:
};
