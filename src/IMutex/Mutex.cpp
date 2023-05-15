/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** Mutex
*/

#include "Mutex.hpp"

Mutex::Mutex()
{
}

Mutex::~Mutex()
{
}

void Mutex::lock()
{
    _mutex.lock();
}

void Mutex::unlock()
{
    _mutex.unlock();
}

void Mutex::trylock()
{
    _mutex.try_lock();
}
