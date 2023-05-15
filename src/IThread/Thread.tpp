/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** Thread
*/

#include "Thread.hpp"
#include <utility>

template <class _Fp, class... _Args>
Thread<_Fp, _Args...>::Thread(_Fp&& __f, _Args... __args)
{
    m_thread = std::make_unique<std::thread>(std::forward<_Fp>(__f), std::forward<_Args>(__args)...);
    m_threadStatus = ThreadStatus::RUNNING;
}

template <class _Fp, class... _Args>
Thread<_Fp, _Args...>::~Thread()
{
    if (m_threadStatus == ThreadStatus::RUNNING)
        stopThread();
}

template <class _Fp, class... _Args>
ThreadStatus Thread<_Fp, _Args...>::getThreadStatus()
{
    return m_threadStatus;
}

template <class _Fp, class... _Args>
void Thread<_Fp, _Args...>::stopThread()
{
    if (m_thread->joinable() == true)
        m_thread->detach();
    m_threadStatus = ThreadStatus::STOPPED;
}

template <class _Fp, class... _Args>
void Thread<_Fp, _Args...>::joinThread()
{
    m_thread->join();
    m_threadStatus = ThreadStatus::STOPPED;
}
    