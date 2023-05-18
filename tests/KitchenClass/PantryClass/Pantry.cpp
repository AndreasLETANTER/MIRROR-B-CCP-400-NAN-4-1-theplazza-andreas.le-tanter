/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** Pantry
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../../src/Plazza/Kitchen/Pantry/Pantry.hpp"

void checkIngredientTest(std::shared_ptr<IPantry> pantry, bool expected)
{
    cr_assert_eq(pantry->checkIngredient(PizzaIngredient::Dough), expected);
    cr_assert_eq(pantry->checkIngredient(PizzaIngredient::Tomato), expected);
    cr_assert_eq(pantry->checkIngredient(PizzaIngredient::Gruyere), expected);
    cr_assert_eq(pantry->checkIngredient(PizzaIngredient::Ham), expected);
    cr_assert_eq(pantry->checkIngredient(PizzaIngredient::Mushrooms), expected);
    cr_assert_eq(pantry->checkIngredient(PizzaIngredient::Steak), expected);
    cr_assert_eq(pantry->checkIngredient(PizzaIngredient::Eggplant), expected);
    cr_assert_eq(pantry->checkIngredient(PizzaIngredient::GoatCheese), expected);
    cr_assert_eq(pantry->checkIngredient(PizzaIngredient::ChiefLove), expected);
}

void removeMassiveIngredient(std::shared_ptr<IPantry> pantry, int nb_ingredients)
{
    pantry->removeIngredient(PizzaIngredient::Dough, nb_ingredients);
    pantry->removeIngredient(PizzaIngredient::Tomato, nb_ingredients);
    pantry->removeIngredient(PizzaIngredient::Gruyere, nb_ingredients);
    pantry->removeIngredient(PizzaIngredient::Ham, nb_ingredients);
    pantry->removeIngredient(PizzaIngredient::Mushrooms, nb_ingredients);
    pantry->removeIngredient(PizzaIngredient::Steak, nb_ingredients);
    pantry->removeIngredient(PizzaIngredient::Eggplant, nb_ingredients);
    pantry->removeIngredient(PizzaIngredient::GoatCheese, nb_ingredients);
    pantry->removeIngredient(PizzaIngredient::ChiefLove, nb_ingredients);
}

void addMassiveIngredient(std::shared_ptr<IPantry> pantry, int nb_ingredients)
{
    pantry->addIngredient(PizzaIngredient::Dough, nb_ingredients);
    pantry->addIngredient(PizzaIngredient::Tomato, nb_ingredients);
    pantry->addIngredient(PizzaIngredient::Gruyere, nb_ingredients);
    pantry->addIngredient(PizzaIngredient::Ham, nb_ingredients);
    pantry->addIngredient(PizzaIngredient::Mushrooms, nb_ingredients);
    pantry->addIngredient(PizzaIngredient::Steak, nb_ingredients);
    pantry->addIngredient(PizzaIngredient::Eggplant, nb_ingredients);
    pantry->addIngredient(PizzaIngredient::GoatCheese, nb_ingredients);
    pantry->addIngredient(PizzaIngredient::ChiefLove, nb_ingredients);
}

Test(Pantry, Basic_Create)
{
    std::shared_ptr<IPantry> pantry = std::make_shared<Pantry>();

    checkIngredientTest(pantry, true);
}

Test(Pantry, Create_then_remove_ingredient)
{
    std::shared_ptr<IPantry> pantry = std::make_shared<Pantry>();

    removeMassiveIngredient(pantry, 4);
    checkIngredientTest(pantry, true);
}

Test(Pantry, RemoveEverything)
{
    std::shared_ptr<IPantry> pantry = std::make_shared<Pantry>();

    removeMassiveIngredient(pantry, 5);
    checkIngredientTest(pantry, false);
}


Test(Pantry, RemoveEverythingThenAdd)
{
    std::shared_ptr<IPantry> pantry = std::make_shared<Pantry>();

    removeMassiveIngredient(pantry, 5);
    addMassiveIngredient(pantry, 1);
    checkIngredientTest(pantry, true);
}

Test(Pantry, AddMassiveIngredient)
{
    std::shared_ptr<IPantry> pantry = std::make_shared<Pantry>();

    removeMassiveIngredient(pantry, 500);
    checkIngredientTest(pantry, false);
}


Test(Pantry, RemoveTooMAny)
{
    std::shared_ptr<IPantry> pantry = std::make_shared<Pantry>();

    removeMassiveIngredient(pantry, 50);
    checkIngredientTest(pantry, false);
}
