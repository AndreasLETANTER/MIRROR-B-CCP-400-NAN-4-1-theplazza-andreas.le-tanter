/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** SafeQueue
*/

#pragma once
#include "ISafeQueue.hpp"
#include "../IMutex/ScopedLock/ScopedLock.hpp"
#include "../IMutex/IMutex.hpp"
#include "../IMutex/Mutex.hpp"
#include <queue>
#include <memory>
#include <condition_variable>

template <typename T>
class SafeQueue : public ISafeQueue<T> {
    public:
        SafeQueue(std::shared_ptr<IMutex> t_mutex);
        ~SafeQueue();
        void push(T value) override;
        bool tryPop(T &value) override;
        T pop() override;

    protected:
    private:
        std::queue<T> m_queue;
        std::shared_ptr<IMutex> m_mutex;
        std::condition_variable m_cond;
};

#include "SafeQueue.tpp"
