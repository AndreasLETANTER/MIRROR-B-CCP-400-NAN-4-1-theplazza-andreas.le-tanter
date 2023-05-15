/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** SafeQueue
*/

#include "SafeQueue.hpp"

/**
 * @brief SafeQueue class
 * @tparam T 
*/
template <typename T>
class SafeQueue;

/**
 * @brief Construct a new Safe Queue< T>:: Safe Queue object
 * @details Construct a new Safe Queue< T>:: Safe Queue object and initialize the mutex
 * @tparam T type of the queue
 * @param t_mutex mutex to use
*/
template <typename T>
SafeQueue<T>::SafeQueue(std::shared_ptr<IMutex> t_mutex)
{
    m_mutex = t_mutex;
}

/**
 * @brief Destroy the Safe Queue< T>:: Safe Queue object
 * @details Destroy the Safe Queue< T>:: Safe Queue object and clear the queue
 * @tparam T type of the queue
*/
template <typename T>
SafeQueue<T>::~SafeQueue()
{
    while (!m_queue.empty())
        m_queue.pop();
}

/**
 * @brief push a value in the queue
 * @tparam T type of the queue
 * @param value value to push
*/
template <typename T>
void SafeQueue<T>::push(T value)
{
    ScopedLock lock(m_mutex);

    m_queue.push(value);
}

/**
 * @brief try to pop a value from the queue
 * @tparam T type of the queue
 * @param value value to pop
 * @return true if the queue is not empty
 * @return false if the queue is empty
*/
template <typename T>
bool SafeQueue<T>::tryPop(T &value)
{
    ScopedLock lock(m_mutex);

    if (m_queue.empty())
        return false;
    value = m_queue.front();
    m_queue.pop();
    return true;
}

/**
 * @brief pop a value from the queue
 * @details pop a value from the queue and wait if the queue is empty until a value is pushed
 * @tparam T type of the queue
 * @return T value
*/
template <typename T>
T SafeQueue<T>::pop()
{
    ScopedLock _scopedLock(m_mutex);
    std::mutex _mutex;
    std::unique_lock<std::mutex> _lock(_mutex);
    T value;

    while (m_queue.empty())
        m_cond.wait(_lock);
    value = m_queue.front();
    m_queue.pop();
    return value;
}
