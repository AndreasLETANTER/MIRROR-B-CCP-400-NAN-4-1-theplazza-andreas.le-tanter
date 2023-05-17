/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** MargaritaPizza
*/

#pragma once
#include "../APizza.hpp"

class MargaritaPizza : public APizza {
    public:
        MargaritaPizza() = default;
        /**
         * @brief Construct a new Margarita Pizza object
         * @details This constructor initialize the type, size, cooking time and ingredients of the pizza
         * @param t_size The size of the pizza
         * @return An instance of MargaritaPizza
        */
        MargaritaPizza(PizzaSize t_size);
        ~MargaritaPizza() = default;

    protected:
    private:
};
