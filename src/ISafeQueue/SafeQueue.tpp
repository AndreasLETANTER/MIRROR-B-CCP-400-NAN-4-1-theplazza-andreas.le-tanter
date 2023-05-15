/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** SafeQueue
*/

#include "SafeQueue.hpp"

template <typename T>
class SafeQueue;

template <typename T>
SafeQueue<T>::SafeQueue(std::shared_ptr<IMutex> t_mutex)
{
    m_mutex = t_mutex;
}

template <typename T>
SafeQueue<T>::~SafeQueue()
{
    while (!m_queue.empty())
        m_queue.pop();
}

template <typename T>
void SafeQueue<T>::push(T value)
{
    ScopedLock lock(m_mutex);

    m_queue.push(value);
}

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