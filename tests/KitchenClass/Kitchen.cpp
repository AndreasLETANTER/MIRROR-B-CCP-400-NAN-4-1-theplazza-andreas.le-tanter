/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** Kitchen
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../src/Plazza/Kitchen/Kitchen.hpp"

Test(Kitchen, Basic_Check_Ingredient)
{
    std::shared_ptr<IKitchen> kitchen = std::make_shared<Kitchen>();
    std::vector<PizzaIngredient> ingredientNeeded = {PizzaIngredient::Dough, PizzaIngredient::Tomato, PizzaIngredient::Gruyere, PizzaIngredient::Ham, PizzaIngredient::Mushrooms, PizzaIngredient::Steak, PizzaIngredient::Eggplant, PizzaIngredient::GoatCheese, PizzaIngredient::ChiefLove};

    kitchen->createPantry();
    cr_assert_eq(kitchen->checkPantry(ingredientNeeded), true);
}
