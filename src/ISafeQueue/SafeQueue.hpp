/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** SafeQueue
*/

#pragma once
#include "ISafeQueue.hpp"
#include "../IMutex/ScopedLock/ScopedLock.hpp"
#include "../IConditionVariable/ConditionVariable.hpp"
#include "../IMutex/IMutex.hpp"
#include "../IMutex/Mutex.hpp"
#include <queue>
#include <memory>
#include <condition_variable>

/**
 * @brief SafeQueue class
 * @details Thread safe queue implementation inheriting from ISafeQueue
 * @tparam T 
*/
template <typename T>
class SafeQueue : public ISafeQueue<T> {
    public:
        /**
         * @brief Construct a new Safe Queue< T>:: Safe Queue object
         * @details Construct a new Safe Queue< T>:: Safe Queue object and initialize the mutex
         * @tparam T type of the queue
         * @param t_mutex mutex to use
        */
        SafeQueue(std::shared_ptr<IMutex> t_mutex);
        /**
         * @brief Destroy the Safe Queue< T>:: Safe Queue object
         * @details Destroy the Safe Queue< T>:: Safe Queue object and clear the queue
         * @tparam T type of the queue
        */
        ~SafeQueue();
        /**
         * @brief push a value in the queue
         * @tparam T type of the queue
         * @param value value to push
        */
        void push(T value) override;
        /**
         * @brief try to pop a value from the queue
         * @tparam T type of the queue
         * @param value value to pop
         * @return true if the queue is not empty
         * @return false if the queue is empty
        */
        bool tryPop(T &value) override;
        /**
         * @brief get the size of the queue
         * @tparam T type of the queue
         * @return size_t size of the queue
        */
        size_t size() override;
        /**
         * @brief pop a value from the queue
         * @details pop a value from the queue and wait if the queue is empty until a value is pushed
         * @tparam T type of the queue
         * @return T value
        */
        T pop() override;

    protected:
    private:
        std::queue<T> m_queue;
        std::shared_ptr<IMutex> m_mutex;
        ConditionVariable m_cond;
};

#include "SafeQueue.tpp"
