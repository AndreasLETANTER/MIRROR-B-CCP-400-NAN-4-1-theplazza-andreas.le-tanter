/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** Pantry
*/

#pragma once
#include "IPantry.hpp"
#include <map>

class Pantry : public IPantry {
    public:
        /**
         * @brief Construct a new Pantry:: Pantry object
         * @details set all the ingredient to 5
        */
        Pantry();
        /**
         * @brief Destroy the Pantry:: Pantry object
        */
        ~Pantry() override = default;
        /**
         * @brief Add N ingredient to the pantry
         * @param t_ingredient the ingredient to add
         * @param t_nb_ingredient the number of ingredient to add
        */
        void addIngredient(PizzaIngredient t_ingredient, unsigned int t_nb_ingredient) override;
        /**
         * @brief Remove N ingredient from the pantry
         * @param t_ingredient the ingredient to remove
         * @param t_nb_ingredient the number of ingredient to remove
        */
        void removeIngredient(PizzaIngredient t_ingredient, unsigned int t_nb_ingredient) override;
        /**
         * @brief Check if the pantry contain the ingredient
         * @param t_ingredient the ingredient to check
         * @return true if the pantry contain the ingredient
         * @return false if the pantry doesn't contain the ingredient
        */
        bool checkIngredient(PizzaIngredient t_ingredient) override;

    protected:
    private:
        /**
         * @brief The pantry of the kitchen
         * @details The pantry is a map of ingredient and the number of ingredient
        */
        std::map<PizzaIngredient, unsigned int> m_pantry;
};
