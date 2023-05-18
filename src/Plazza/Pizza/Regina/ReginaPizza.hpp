/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** ReginaPizza
*/

#pragma once
#include "../APizza.hpp"

class ReginaPizza : public APizza {
    public:
        ReginaPizza() = default;
        /**
         * @brief Construct a new Regina Pizza object
         * @details This constructor initialize the type, size, cooking time and ingredients of the pizza
         * @param t_size The size of the pizza
         * @return An instance of ReginaPizza
        */
        ReginaPizza(PizzaSize t_size);
        ~ReginaPizza() = default;

    protected:
    private:
};
