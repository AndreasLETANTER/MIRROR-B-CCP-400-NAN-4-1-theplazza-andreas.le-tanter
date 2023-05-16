/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** IPizza
*/

#pragma once
#include <vector>

/**
 * @brief Enum for the type of pizza
*/
enum PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

/**
 * @brief Enum for the size of pizza
*/
enum PizzaSize
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

/**
 * @brief Enum for the cooking time of pizza
*/
enum PizzaCookingTime
{
    One = 1,
    Two = 2,
    Four = 4
};

/**
 * @brief Enum for the ingredients of pizza
*/
enum PizzaIngredient
{
    Dough = 1,
    Tomato = 2,
    Gruyere = 3,
    Ham = 4,
    Mushrooms = 5,
    Steak = 6,
    Eggplant = 7,
    Goat = 8,
    ChiefLove = 9
};

/**
 * @brief Interface for the pizza class
*/
class IPizza {
    public:
        virtual ~IPizza() = 0;
        /**
         * @brief Get the Type of the pizza
         * @return PizzaType 
        */
        virtual PizzaType getType() const = 0;
        /**
         * @brief Get the Size of the pizza
         * @return PizzaSize 
        */
        virtual PizzaSize getSize() const = 0;
        /**
         * @brief Get the Cooking Time of the pizza
         * @return PizzaCookingTime 
        */
        virtual PizzaCookingTime getCookingTime() const = 0;
        /**
         * @brief Get the Ingredients of the pizza
         * @return std::vector<PizzaIngredient> 
        */
        virtual std::vector<PizzaIngredient> getIngredients() const = 0;

    protected:
    private:
};
