/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** ReginaPizza
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <memory>
#include "../../src/Plazza/Pizza/Regina/ReginaPizza.hpp"

Test(ReginaPizza, SizeS)
{
    std::unique_ptr<APizza> pizza = std::make_unique<ReginaPizza>(PizzaSize::S);
    std::vector<PizzaIngredient> ingredients = pizza->getIngredients();

    cr_assert_eq(pizza->getType(), PizzaType::Regina);
    cr_assert_eq(pizza->getSize(), PizzaSize::S);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::Two);
    cr_assert_eq(ingredients.size(), 5);
    cr_assert_eq(ingredients[0], PizzaIngredient::Dough);
    cr_assert_eq(ingredients[1], PizzaIngredient::Tomato);
    cr_assert_eq(ingredients[2], PizzaIngredient::Gruyere);
    cr_assert_eq(ingredients[3], PizzaIngredient::Ham);
    cr_assert_eq(ingredients[4], PizzaIngredient::Mushrooms);
}

Test(ReginaPizza, SizeM)
{
    std::unique_ptr<APizza> pizza = std::make_unique<ReginaPizza>(PizzaSize::M);
    std::vector<PizzaIngredient> ingredients = pizza->getIngredients();

    cr_assert_eq(pizza->getType(), PizzaType::Regina);
    cr_assert_eq(pizza->getSize(), PizzaSize::M);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::Two);
    cr_assert_eq(ingredients.size(), 5);
    cr_assert_eq(ingredients[0], PizzaIngredient::Dough);
    cr_assert_eq(ingredients[1], PizzaIngredient::Tomato);
    cr_assert_eq(ingredients[2], PizzaIngredient::Gruyere);
    cr_assert_eq(ingredients[3], PizzaIngredient::Ham);
    cr_assert_eq(ingredients[4], PizzaIngredient::Mushrooms);
}

Test(ReginaPizza, SizeL)
{
    std::unique_ptr<APizza> pizza = std::make_unique<ReginaPizza>(PizzaSize::L);
    std::vector<PizzaIngredient> ingredients = pizza->getIngredients();

    cr_assert_eq(pizza->getType(), PizzaType::Regina);
    cr_assert_eq(pizza->getSize(), PizzaSize::L);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::Two);
    cr_assert_eq(ingredients.size(), 5);
    cr_assert_eq(ingredients[0], PizzaIngredient::Dough);
    cr_assert_eq(ingredients[1], PizzaIngredient::Tomato);
    cr_assert_eq(ingredients[2], PizzaIngredient::Gruyere);
    cr_assert_eq(ingredients[3], PizzaIngredient::Ham);
    cr_assert_eq(ingredients[4], PizzaIngredient::Mushrooms);
}

Test(ReginaPizza, SizeXL)
{
    std::unique_ptr<APizza> pizza = std::make_unique<ReginaPizza>(PizzaSize::XL);
    std::vector<PizzaIngredient> ingredients = pizza->getIngredients();

    cr_assert_eq(pizza->getType(), PizzaType::Regina);
    cr_assert_eq(pizza->getSize(), PizzaSize::XL);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::Two);
    cr_assert_eq(ingredients.size(), 5);
    cr_assert_eq(ingredients[0], PizzaIngredient::Dough);
    cr_assert_eq(ingredients[1], PizzaIngredient::Tomato);
    cr_assert_eq(ingredients[2], PizzaIngredient::Gruyere);
    cr_assert_eq(ingredients[3], PizzaIngredient::Ham);
    cr_assert_eq(ingredients[4], PizzaIngredient::Mushrooms);
}

Test(ReginaPizza, SizeXXL)
{
    std::unique_ptr<APizza> pizza = std::make_unique<ReginaPizza>(PizzaSize::XXL);
    std::vector<PizzaIngredient> ingredients = pizza->getIngredients();

    cr_assert_eq(pizza->getType(), PizzaType::Regina);
    cr_assert_eq(pizza->getSize(), PizzaSize::XXL);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::Two);
    cr_assert_eq(ingredients.size(), 5);
    cr_assert_eq(ingredients[0], PizzaIngredient::Dough);
    cr_assert_eq(ingredients[1], PizzaIngredient::Tomato);
    cr_assert_eq(ingredients[2], PizzaIngredient::Gruyere);
    cr_assert_eq(ingredients[3], PizzaIngredient::Ham);
    cr_assert_eq(ingredients[4], PizzaIngredient::Mushrooms);
}
