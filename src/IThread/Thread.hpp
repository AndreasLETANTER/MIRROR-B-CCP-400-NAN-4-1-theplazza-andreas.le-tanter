/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** Thread
*/

#pragma once
#include "IThread.hpp"
#include <memory>

/**
 * @brief Thread class
 * @details Thread class inheriting from IThread
 * @tparam _Fp function pointer
 * @tparam _Args arguments of the function
*/
template <class _Fp, class... _Args>
class Thread : public IThread {
    public:
        Thread(_Fp&& __f, _Args... __args);
        ~Thread();
        ThreadStatus getThreadStatus();
        void stopThread();
        void joinThread();

    protected:
    private:
        ThreadStatus m_threadStatus = ThreadStatus::STOPPED;
        std::unique_ptr<std::thread> m_thread;
};

#include "Thread.tpp"
