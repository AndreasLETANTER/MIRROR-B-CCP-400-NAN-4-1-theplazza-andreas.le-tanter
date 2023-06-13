/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** Kitchen
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../src/Plazza/Kitchen/Kitchen.hpp"
#include "../../src/Plazza/Pizza/Regina/ReginaPizza.hpp"
#include <memory>
#include <unistd.h>

static void redirect_all_stdout()
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Kitchen, Basic_Check_Ingredient, .init = redirect_all_stdout)
{
    std::shared_ptr<IKitchen> kitchen = std::make_shared<Kitchen>(5, 5, 5);
    std::vector<PizzaIngredient> ingredientNeeded = {PizzaIngredient::Dough, PizzaIngredient::Tomato, PizzaIngredient::Gruyere, PizzaIngredient::Ham, PizzaIngredient::Mushrooms, PizzaIngredient::Steak, PizzaIngredient::Eggplant, PizzaIngredient::GoatCheese, PizzaIngredient::ChiefLove};

    cr_assert_eq(kitchen->checkPantry(ingredientNeeded), true);
}

Test(Kitchen, Basic_isKitchenFilled, .init = redirect_all_stdout)
{
    std::shared_ptr<IKitchen> kitchen = std::make_shared<Kitchen>(5, 5, 5);

    kitchen->createPantry();
    cr_assert_eq(kitchen->isKitchenFilled(), false);
}

Test(Kitchen, KitchenFilled, .init = redirect_all_stdout)
{
    std::shared_ptr<IKitchen> kitchen = std::make_shared<Kitchen>(0, 0, 5);

    kitchen->createPantry();
    cr_assert_eq(kitchen->isKitchenFilled(), true);
}

Test(Kitchen, Basic_addPizza, .init = cr_redirect_stdout)
{
    std::shared_ptr<IKitchen> kitchen = std::make_shared<Kitchen>(1, 1, 1000);
    std::shared_ptr<IPizza> pizza = std::make_shared<ReginaPizza>(PizzaSize::S);

    kitchen->addPizzaToPool(pizza);
    kitchen->addPizzaToPool(pizza);
    cr_assert_eq(kitchen->isKitchenFilled(), true);
    cr_assert_eq(kitchen->isExitNeeded(), false);
    cr_assert_eq(kitchen->checkPantry(pizza->getIngredients()), true);
    sleep(3);
    cr_assert_eq(kitchen->isKitchenFilled(), false);
    sleep(7);
    cr_assert_eq(kitchen->isExitNeeded(), true);
}

Test(Kitchen, Nothing, .init = cr_redirect_stdout)
{
    std::shared_ptr<IKitchen> kitchen = std::make_shared<Kitchen>(1, 1, 1000);

    sleep(6);
    cr_assert_eq(kitchen->isExitNeeded(), true);
}

Test(Kitchen, emptyPantry, .init = cr_redirect_stdout)
{
    std::shared_ptr<IKitchen> kitchen = std::make_shared<Kitchen>(3, 1, 1000);
    std::shared_ptr<IPizza> pizza = std::make_shared<ReginaPizza>(PizzaSize::S);

    kitchen->addPizzaToPool(pizza);
    kitchen->addPizzaToPool(pizza);
    kitchen->addPizzaToPool(pizza);
    kitchen->addPizzaToPool(pizza);
    kitchen->addPizzaToPool(pizza);
    cr_assert_eq(kitchen->isKitchenFilled(), false);
    cr_assert_eq(kitchen->isExitNeeded(), false);
    cr_assert_eq(kitchen->checkPantry(pizza->getIngredients()), false);
    sleep(2);
    cr_assert_eq(kitchen->isKitchenFilled(), false);
    cr_assert_eq(kitchen->checkPantry(pizza->getIngredients()), true);
    sleep(8);
    cr_assert_eq(kitchen->isExitNeeded(), true);
}
