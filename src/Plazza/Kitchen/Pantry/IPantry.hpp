/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** IPantry
*/

#pragma once
#include "../../Pizza/IPizza.hpp"

/**
 * @brief Interface for the pantry class
*/
class IPantry {
    public:
        virtual ~IPantry() = default;
        /**
         * @brief Add N ingredient to the pantry
         * @param t_ingredient the ingredient to add
         * @param t_nb_ingredient the number of ingredient to add
        */
        virtual void addIngredient(PizzaIngredient t_ingredient, unsigned int t_nb_ingredient) = 0;
        /**
         * @brief Remove N ingredient to the pantry
         * @param t_ingredient the ingredient to remove
         * @param t_nb_ingredient the number of ingredient to remove
        */
        virtual void removeIngredient(PizzaIngredient t_ingredient, unsigned int t_nb_ingredient) = 0;
        /**
         * @brief Check if the pantry contain the ingredient
         * @param t_ingredient the ingredient to check
         * @return true if the pantry contain the ingredient
         * @return false if the pantry doesn't contain the ingredient
        */
        virtual bool checkIngredient(PizzaIngredient t_ingredient) = 0;

    protected:
    private:
};
