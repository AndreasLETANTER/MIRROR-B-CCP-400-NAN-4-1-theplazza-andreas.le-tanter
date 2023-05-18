/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** AmericanaPizza
*/

#pragma once
#include "../APizza.hpp"

class AmericanaPizza : public APizza {
    public:
        AmericanaPizza() = default;
        /***
         * @brief Construct a new Americana Pizza object
         * @details This constructor initialize the type, size, cooking time and ingredients of the pizza
         * @param t_size The size of the pizza
         * @return An instance of AmericanaPizza
        */
        AmericanaPizza(PizzaSize t_size);
        ~AmericanaPizza() = default;

    protected:
    private:
};
