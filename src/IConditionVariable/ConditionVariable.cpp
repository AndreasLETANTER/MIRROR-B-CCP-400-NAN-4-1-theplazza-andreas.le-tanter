/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** ConditionVariable
*/

#include "ConditionVariable.hpp"

/**
 * @brief Wait for a condition to be true
 * @details Wait for a condition to be true and lock the mutex passed as parameter
 * @param t_lock 
*/
void ConditionVariable::wait(std::unique_lock<std::mutex> &t_lock)
{
    m_cond.wait(t_lock);
}

/**
 * @brief Notify one thread
*/
void ConditionVariable::notify_one()
{
    m_cond.notify_one();
}

/**
 * @brief Notify all threads
*/
void ConditionVariable::notify_all()
{
    m_cond.notify_all();
}

