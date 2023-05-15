/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** ScopedLock
*/

#include "ScopedLock.hpp"

/**
 * @brief Construct a new Scoped Lock:: Scoped Lock object
 * @param t_mutex Mutex to lock and unlock
*/
ScopedLock::ScopedLock(std::shared_ptr<IMutex> t_mutex)
{
    m_mutex = t_mutex;
    m_mutex->lock();
}

/**
 * @brief Destroy the Scoped Lock:: Scoped Lock object
 * @details Unlock the mutex
*/
ScopedLock::~ScopedLock()
{
    m_mutex->unlock();
}
