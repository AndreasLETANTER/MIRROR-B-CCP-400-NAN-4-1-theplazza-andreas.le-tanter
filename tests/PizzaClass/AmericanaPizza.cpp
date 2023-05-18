/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** AmericanaPizza
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <memory>
#include "../../src/Plazza/Pizza/Americana/AmericanaPizza.hpp"

Test(Americana, SizeL)
{
    std::shared_ptr<IPizza> pizza = std::make_shared<AmericanaPizza>(PizzaSize::L);

    cr_assert_eq(pizza->getType(), PizzaType::Americana);
    cr_assert_eq(pizza->getSize(), PizzaSize::L);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::Two);
    cr_assert_eq(pizza->getIngredients().size(), 4);
    cr_assert_eq(pizza->getIngredients()[0], PizzaIngredient::Dough);
    cr_assert_eq(pizza->getIngredients()[1], PizzaIngredient::Tomato);
    cr_assert_eq(pizza->getIngredients()[2], PizzaIngredient::Gruyere);
    cr_assert_eq(pizza->getIngredients()[3], PizzaIngredient::Steak);
}

Test(Americana, SizeM)
{
    std::shared_ptr<IPizza> pizza = std::make_shared<AmericanaPizza>(PizzaSize::M);

    cr_assert_eq(pizza->getType(), PizzaType::Americana);
    cr_assert_eq(pizza->getSize(), PizzaSize::M);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::Two);
    cr_assert_eq(pizza->getIngredients().size(), 4);
    cr_assert_eq(pizza->getIngredients()[0], PizzaIngredient::Dough);
    cr_assert_eq(pizza->getIngredients()[1], PizzaIngredient::Tomato);
    cr_assert_eq(pizza->getIngredients()[2], PizzaIngredient::Gruyere);
    cr_assert_eq(pizza->getIngredients()[3], PizzaIngredient::Steak);
}

Test(Americana, SizeS)
{
    std::shared_ptr<IPizza> pizza = std::make_shared<AmericanaPizza>(PizzaSize::S);

    cr_assert_eq(pizza->getType(), PizzaType::Americana);
    cr_assert_eq(pizza->getSize(), PizzaSize::S);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::Two);
    cr_assert_eq(pizza->getIngredients().size(), 4);
    cr_assert_eq(pizza->getIngredients()[0], PizzaIngredient::Dough);
    cr_assert_eq(pizza->getIngredients()[1], PizzaIngredient::Tomato);
    cr_assert_eq(pizza->getIngredients()[2], PizzaIngredient::Gruyere);
    cr_assert_eq(pizza->getIngredients()[3], PizzaIngredient::Steak);
}

Test(Americana, SizeXL)
{
    std::shared_ptr<IPizza> pizza = std::make_shared<AmericanaPizza>(PizzaSize::XL);

    cr_assert_eq(pizza->getType(), PizzaType::Americana);
    cr_assert_eq(pizza->getSize(), PizzaSize::XL);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::Two);
    cr_assert_eq(pizza->getIngredients().size(), 4);
    cr_assert_eq(pizza->getIngredients()[0], PizzaIngredient::Dough);
    cr_assert_eq(pizza->getIngredients()[1], PizzaIngredient::Tomato);
    cr_assert_eq(pizza->getIngredients()[2], PizzaIngredient::Gruyere);
    cr_assert_eq(pizza->getIngredients()[3], PizzaIngredient::Steak);
}

Test(Americana, SizeXXL)
{
    std::shared_ptr<IPizza> pizza = std::make_shared<AmericanaPizza>(PizzaSize::XXL);

    cr_assert_eq(pizza->getType(), PizzaType::Americana);
    cr_assert_eq(pizza->getSize(), PizzaSize::XXL);
    cr_assert_eq(pizza->getCookingTime(), PizzaCookingTime::Two);
    cr_assert_eq(pizza->getIngredients().size(), 4);
    cr_assert_eq(pizza->getIngredients()[0], PizzaIngredient::Dough);
    cr_assert_eq(pizza->getIngredients()[1], PizzaIngredient::Tomato);
    cr_assert_eq(pizza->getIngredients()[2], PizzaIngredient::Gruyere);
    cr_assert_eq(pizza->getIngredients()[3], PizzaIngredient::Steak);
}
