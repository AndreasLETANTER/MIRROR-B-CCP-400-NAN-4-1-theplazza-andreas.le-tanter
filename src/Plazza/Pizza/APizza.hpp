/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** APizza
*/

#pragma once
#include "IPizza.hpp"

class APizza : public IPizza {
    public:
        ~APizza() = default;
        /**
         * @brief Get the type of pizza
         * @return the type of pizza
        */
       PizzaType getType() const override;
         /**
          * @brief Get the size of pizza
          * @return the size of pizza
         */
        PizzaSize getSize() const override;
        /**
         * @brief Get the cooking time of pizza
         * @return the cooking time of pizza
        */
        PizzaCookingTime getCookingTime() const override;
        /**
         * @brief Get the ingredients of pizza
         * @return the ingredients of pizza
        */
        std::vector<PizzaIngredient> getIngredients() const override;

    protected:
        PizzaType m_type;
        PizzaSize m_size;
        PizzaCookingTime m_cookingTime;
        std::vector<PizzaIngredient> m_ingredients;
    private:
};
