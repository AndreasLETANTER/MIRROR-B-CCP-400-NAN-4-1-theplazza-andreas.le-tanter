/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** ScopedLock
*/

#include "ScopedLock.hpp"

ScopedLock::ScopedLock(std::shared_ptr<IMutex> t_mutex)
{
    m_mutex = t_mutex;
    m_mutex->lock();
}

ScopedLock::~ScopedLock()
{
    m_mutex->unlock();
}
