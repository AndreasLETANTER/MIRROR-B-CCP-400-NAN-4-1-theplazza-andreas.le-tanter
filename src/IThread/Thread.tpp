/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** Thread
*/

#include "Thread.hpp"
#include <utility>

/**
 * @brief Construct a new Thread<_Fp, _Args...>::Thread object
 * @details Construct a new Thread<_Fp, _Args...>::Thread object and start the thread
 * @tparam _Fp function pointer
 * @tparam _Args arguments of the function
 * @param __f function pointer
 * @param __args arguments of the function
*/
template <class _Fp, class... _Args>
Thread<_Fp, _Args...>::Thread(_Fp&& __f, _Args... __args)
{
    m_thread = std::make_unique<std::thread>(std::forward<_Fp>(__f), std::forward<_Args>(__args)...);
    m_threadStatus = ThreadStatus::RUNNING;
}

/**
 * @brief Destroy the Thread<_Fp, _Args...>::Thread object
 * @details Destroy the Thread<_Fp, _Args...>::Thread object and stop the thread
 * @tparam _Fp function pointer
 * @tparam _Args arguments of the function
*/
template <class _Fp, class... _Args>
Thread<_Fp, _Args...>::~Thread()
{
    if (m_threadStatus == ThreadStatus::RUNNING)
        stopThread();
}

/**
 * @brief Get the Thread Status object
 * @tparam _Fp function pointer
 * @tparam _Args arguments of the function
 * @return ThreadStatus status of the thread
*/
template <class _Fp, class... _Args>
ThreadStatus Thread<_Fp, _Args...>::getThreadStatus()
{
    return m_threadStatus;
}

/**
 * @brief Stop the thread
 * @details Stop the thread and set the status to STOPPED
 * @tparam _Fp function pointer
 * @tparam _Args arguments of the function
*/
template <class _Fp, class... _Args>
void Thread<_Fp, _Args...>::stopThread()
{
    if (m_thread->joinable() == true)
        m_thread->detach();
    m_threadStatus = ThreadStatus::STOPPED;
}

/**
 * @brief Join the thread
 * @details Join the thread and set the status to STOPPED
 * @tparam _Fp function pointer
 * @tparam _Args arguments of the function
*/
template <class _Fp, class... _Args>
void Thread<_Fp, _Args...>::joinThread()
{
    m_thread->join();
    m_threadStatus = ThreadStatus::STOPPED;
}
    