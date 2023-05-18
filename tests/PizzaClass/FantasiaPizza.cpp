/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** FantasiaPizza
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <memory>
#include "../../src/Plazza/Pizza/Fantasia/FantasiaPizza.hpp"

Test(FantasiaPizza, SizeS)
{
    std::unique_ptr<APizza> pizza = std::make_unique<FantasiaPizza>(PizzaSize::S);
    std::vector<PizzaIngredient> ingredients = pizza->getIngredients();

    cr_assert_eq(pizza->getType(), PizzaType::Fantasia);
    cr_assert_eq(pizza->getSize(), PizzaSize::S);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::Four);
    cr_assert_eq(ingredients.size(), 5);
    cr_assert_eq(ingredients[0], PizzaIngredient::Dough);
    cr_assert_eq(ingredients[1], PizzaIngredient::Tomato);
    cr_assert_eq(ingredients[2], PizzaIngredient::Eggplant);
    cr_assert_eq(ingredients[3], PizzaIngredient::GoatCheese);
    cr_assert_eq(ingredients[4], PizzaIngredient::ChiefLove);
}

Test(FantasiaPizza, SizeM)
{
    std::unique_ptr<APizza> pizza = std::make_unique<FantasiaPizza>(PizzaSize::M);
    std::vector<PizzaIngredient> ingredients = pizza->getIngredients();

    cr_assert_eq(pizza->getType(), PizzaType::Fantasia);
    cr_assert_eq(pizza->getSize(), PizzaSize::M);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::Four);
    cr_assert_eq(ingredients.size(), 5);
    cr_assert_eq(ingredients[0], PizzaIngredient::Dough);
    cr_assert_eq(ingredients[1], PizzaIngredient::Tomato);
    cr_assert_eq(ingredients[2], PizzaIngredient::Eggplant);
    cr_assert_eq(ingredients[3], PizzaIngredient::GoatCheese);
    cr_assert_eq(ingredients[4], PizzaIngredient::ChiefLove);
}

Test(FantasiaPizza, SizeL)
{
    std::unique_ptr<APizza> pizza = std::make_unique<FantasiaPizza>(PizzaSize::L);
    std::vector<PizzaIngredient> ingredients = pizza->getIngredients();

    cr_assert_eq(pizza->getType(), PizzaType::Fantasia);
    cr_assert_eq(pizza->getSize(), PizzaSize::L);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::Four);
    cr_assert_eq(ingredients.size(), 5);
    cr_assert_eq(ingredients[0], PizzaIngredient::Dough);
    cr_assert_eq(ingredients[1], PizzaIngredient::Tomato);
    cr_assert_eq(ingredients[2], PizzaIngredient::Eggplant);
    cr_assert_eq(ingredients[3], PizzaIngredient::GoatCheese);
    cr_assert_eq(ingredients[4], PizzaIngredient::ChiefLove);
}

Test(FantasiaPizza, SizeXL)
{
    std::unique_ptr<APizza> pizza = std::make_unique<FantasiaPizza>(PizzaSize::XL);
    std::vector<PizzaIngredient> ingredients = pizza->getIngredients();

    cr_assert_eq(pizza->getType(), PizzaType::Fantasia);
    cr_assert_eq(pizza->getSize(), PizzaSize::XL);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::Four);
    cr_assert_eq(ingredients.size(), 5);
    cr_assert_eq(ingredients[0], PizzaIngredient::Dough);
    cr_assert_eq(ingredients[1], PizzaIngredient::Tomato);
    cr_assert_eq(ingredients[2], PizzaIngredient::Eggplant);
    cr_assert_eq(ingredients[3], PizzaIngredient::GoatCheese);
    cr_assert_eq(ingredients[4], PizzaIngredient::ChiefLove);
}

Test(FantasiaPizza, SizeXXL)
{
    std::unique_ptr<APizza> pizza = std::make_unique<FantasiaPizza>(PizzaSize::XXL);
    std::vector<PizzaIngredient> ingredients = pizza->getIngredients();

    cr_assert_eq(pizza->getType(), PizzaType::Fantasia);
    cr_assert_eq(pizza->getSize(), PizzaSize::XXL);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::Four);
    cr_assert_eq(ingredients.size(), 5);
    cr_assert_eq(ingredients[0], PizzaIngredient::Dough);
    cr_assert_eq(ingredients[1], PizzaIngredient::Tomato);
    cr_assert_eq(ingredients[2], PizzaIngredient::Eggplant);
    cr_assert_eq(ingredients[3], PizzaIngredient::GoatCheese);
    cr_assert_eq(ingredients[4], PizzaIngredient::ChiefLove);
}
