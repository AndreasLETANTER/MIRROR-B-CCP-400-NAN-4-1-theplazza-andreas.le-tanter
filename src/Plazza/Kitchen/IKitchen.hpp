/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** IKitchen
*/

#pragma once
#include <vector>
#include <memory>
#include "../Pizza/IPizza.hpp"

/**
 * @brief Interface for the kitchen class
*/
class IKitchen {
    public:
        /**
         * @brief Destroy the Kitchen:: Kitchen object
         * @details Destroy the Kitchen:: Kitchen object and join the thread of the cooks and the pantry
        */
        virtual ~IKitchen() = default;
        /**
         * @brief Create a Cook object (thread that cook the pizza)
        */
        virtual void createCooks() = 0;
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
         * @return true if the kitchen is filled
        */
        virtual bool isKitchenFilled() = 0;
        /**
         * @brief Add a pizza to the pool
         * @param t_pizza the pizza to add to the pool
         * @details this function add a pizza to the pool of the kitchen (the pool is a vector of pizza that the kitchen will cook)
        */
        virtual void addPizzaToPool(std::shared_ptr<IPizza> t_pizza) = 0;
        /**
         * @brief Check if the kitchen need to exit
         * @return true if the kitchen need to exit
         * @return false if the kitchen doesn't need to exit
        */
        virtual bool isExitNeeded() = 0;

    protected:
    private:
};
