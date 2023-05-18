/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** MargaritaPizza
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <memory>
#include "../../src/Plazza/Pizza/Margarita/MargaritaPizza.hpp"

Test(MargaritaPizza, SizeS)
{
    std::unique_ptr<APizza> pizza = std::make_unique<MargaritaPizza>(PizzaSize::S);
    std::vector<PizzaIngredient> ingredients = pizza->getIngredients();

    cr_assert_eq(pizza->getType(), PizzaType::Margarita);
    cr_assert_eq(pizza->getSize(), PizzaSize::S);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::One);
    cr_assert_eq(ingredients.size(), 3);
    cr_assert_eq(ingredients[0], PizzaIngredient::Dough);
    cr_assert_eq(ingredients[1], PizzaIngredient::Tomato);
    cr_assert_eq(ingredients[2], PizzaIngredient::Gruyere);
}

Test(MargaritaPizza, SizeM)
{
    std::unique_ptr<APizza> pizza = std::make_unique<MargaritaPizza>(PizzaSize::M);
    std::vector<PizzaIngredient> ingredients = pizza->getIngredients();

    cr_assert_eq(pizza->getType(), PizzaType::Margarita);
    cr_assert_eq(pizza->getSize(), PizzaSize::M);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::One);
    cr_assert_eq(ingredients.size(), 3);
    cr_assert_eq(ingredients[0], PizzaIngredient::Dough);
    cr_assert_eq(ingredients[1], PizzaIngredient::Tomato);
    cr_assert_eq(ingredients[2], PizzaIngredient::Gruyere);
}

Test(MargaritaPizza, SizeL)
{
    std::unique_ptr<APizza> pizza = std::make_unique<MargaritaPizza>(PizzaSize::L);
    std::vector<PizzaIngredient> ingredients = pizza->getIngredients();

    cr_assert_eq(pizza->getType(), PizzaType::Margarita);
    cr_assert_eq(pizza->getSize(), PizzaSize::L);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::One);
    cr_assert_eq(ingredients.size(), 3);
    cr_assert_eq(ingredients[0], PizzaIngredient::Dough);
    cr_assert_eq(ingredients[1], PizzaIngredient::Tomato);
    cr_assert_eq(ingredients[2], PizzaIngredient::Gruyere);
}

Test(MargaritaPizza, SizeXL)
{
    std::unique_ptr<APizza> pizza = std::make_unique<MargaritaPizza>(PizzaSize::XL);
    std::vector<PizzaIngredient> ingredients = pizza->getIngredients();

    cr_assert_eq(pizza->getType(), PizzaType::Margarita);
    cr_assert_eq(pizza->getSize(), PizzaSize::XL);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::One);
    cr_assert_eq(ingredients.size(), 3);
    cr_assert_eq(ingredients[0], PizzaIngredient::Dough);
    cr_assert_eq(ingredients[1], PizzaIngredient::Tomato);
    cr_assert_eq(ingredients[2], PizzaIngredient::Gruyere);
}

Test(MargaritaPizza, SizeXXL)
{
    std::unique_ptr<APizza> pizza = std::make_unique<MargaritaPizza>(PizzaSize::XXL);
    std::vector<PizzaIngredient> ingredients = pizza->getIngredients();

    cr_assert_eq(pizza->getType(), PizzaType::Margarita);
    cr_assert_eq(pizza->getSize(), PizzaSize::XXL);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::One);
    cr_assert_eq(ingredients.size(), 3);
    cr_assert_eq(ingredients[0], PizzaIngredient::Dough);
    cr_assert_eq(ingredients[1], PizzaIngredient::Tomato);
    cr_assert_eq(ingredients[2], PizzaIngredient::Gruyere);
}
