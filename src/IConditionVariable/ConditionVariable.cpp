/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** ConditionVariable
*/

#include "ConditionVariable.hpp"

void ConditionVariable::wait(std::unique_lock<std::mutex> &t_lock)
{
    m_cond.wait(t_lock);
}

void ConditionVariable::notify_one()
{
    m_cond.notify_one();
}

void ConditionVariable::notify_all()
{
    m_cond.notify_all();
}

