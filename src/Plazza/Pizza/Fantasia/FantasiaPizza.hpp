/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** FantasiaPizza
*/

#pragma once
#include "../APizza.hpp"

class FantasiaPizza : public APizza {
    public:
        FantasiaPizza() = default;
        /**
         * @brief Construct a new Fantasia Pizza object
         * @details This constructor initialize the type, size, cooking time and ingredients of the pizza
         * @param t_size The size of the pizza
         * @return An instance of FantasiaPizza
        */
        FantasiaPizza(PizzaSize t_size);
        ~FantasiaPizza() = default;

    protected:
    private:
};
