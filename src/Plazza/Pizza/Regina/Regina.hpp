/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** Regina
*/

#pragma once
#include "../APizza.hpp"

class Regina : public APizza {
    public:
        Regina() = default;
        Regina(PizzaSize t_size);
        ~Regina() = default;

    protected:
    private:
        void addIngredientToVector(PizzaIngredient t_ingredient);
};
