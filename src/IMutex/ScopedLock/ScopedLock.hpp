/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** ScopedLock
*/

#pragma once
#include "../IMutex.hpp"
#include <memory>

class ScopedLock {
    public:
        ScopedLock(std::shared_ptr<IMutex> t_mutex);
        ~ScopedLock();

    protected:
    private:
        std::shared_ptr<IMutex> m_mutex;
};
