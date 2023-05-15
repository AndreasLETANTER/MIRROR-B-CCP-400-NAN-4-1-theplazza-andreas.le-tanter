/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** Mutex
*/

#include "Mutex.hpp"

/**
 * @brief Lock the mutex
*/
void Mutex::lock()
{
    _mutex.lock();
}

/**
 * @brief Unlock the mutex
*/
void Mutex::unlock()
{
    _mutex.unlock();
}

/**
 * @brief Try to lock the mutex
*/
void Mutex::trylock()
{
    _mutex.try_lock();
}
