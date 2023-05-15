/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** ScopedLock
*/

#pragma once
#include "../IMutex.hpp"
#include <memory>

/**
 * @brief ScopedLock class
 * @details Lock and unlock a mutex at creation and destruction of the object
*/
class ScopedLock {
    public:
        ScopedLock(std::shared_ptr<IMutex> t_mutex);
        ~ScopedLock();

    protected:
    private:
        std::shared_ptr<IMutex> m_mutex;
};
