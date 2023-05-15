/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** SafeQueueClass
*/

#include <criterion/criterion.h>
#include <iostream>
#include <memory>
#include <unistd.h>
#include "../src/IThread/Thread.hpp"
#include "../src/ISafeQueue/SafeQueue.hpp"
#include "../src/IMutex/Mutex.hpp"
#include "../src/IMutex/ScopedLock/ScopedLock.hpp"

static void incrementCounter(std::shared_ptr<ISafeQueue<int>> queue, int n)
{
    int value = 0;

    if (queue->tryPop(value) == false)
        return;

    for (int i = 0; i < n; i++) {
        value++;
    }
    queue->push(value);
}

Test(SafeQueue, Basic_Test)
{
    std::shared_ptr<IMutex> _mutex = std::make_shared<Mutex>();
    std::unique_ptr<ISafeQueue<int>> queue = std::make_unique<SafeQueue<int>>(_mutex);
    int value = 0;

    queue->push(1);
    queue->tryPop(value);

    cr_assert_eq(value, 1);
    cr_assert_eq(queue->tryPop(value), false);
}


Test(SafeQueue, Basic_Test_with_Thread)
{
    int n = 5;
    int t = 5;
    int value = 0;
    std::vector<std::unique_ptr<IThread>> threads;
    std::shared_ptr<IMutex> _mutex = std::make_shared<Mutex>();
    std::shared_ptr<ISafeQueue<int>> queue = std::make_shared<SafeQueue<int>>(_mutex);

    queue->push(value);
    for (int i = 0; i < t; i++)
        threads.push_back(std::make_unique<Thread<decltype(incrementCounter), decltype(queue), decltype(n)>>(incrementCounter, queue, n));
    for (auto &thread : threads)
        thread->joinThread();
    queue->tryPop(value);
    cr_assert_eq(value, 25);
    cr_assert_eq(queue->tryPop(value), false);
}

Test(SafeQueue, Basic_Test_with_Thread_and_sleep)
{
    int n = 5;
    int t = 5;
    int value = 0;
    std::vector<std::unique_ptr<IThread>> threads;
    std::shared_ptr<IMutex> _mutex = std::make_shared<Mutex>();
    std::shared_ptr<ISafeQueue<int>> queue = std::make_shared<SafeQueue<int>>(_mutex);

    queue->push(value);
    for (int i = 0; i < t; i++) {
        threads.push_back(std::make_unique<Thread<decltype(incrementCounter), decltype(queue), decltype(n)>>(incrementCounter, queue, n));
    }
    for (auto &thread : threads)
        thread->joinThread();
    queue->tryPop(value);
    cr_assert_eq(value, 25);
    cr_assert_eq(queue->tryPop(value), false);
}

Test(SafeQueue, Massive_value)
{
    int n = 100;
    int t = 100;
    int value = 0;
    std::vector<std::unique_ptr<IThread>> threads;
    std::shared_ptr<IMutex> _mutex = std::make_shared<Mutex>();
    std::shared_ptr<ISafeQueue<int>> queue = std::make_shared<SafeQueue<int>>(_mutex);

    queue->push(value);
    for (int i = 0; i < t; i++) {
        threads.push_back(std::make_unique<Thread<decltype(incrementCounter), decltype(queue), decltype(n)>>(incrementCounter, queue, n));
    }
    for (auto &thread : threads)
        thread->joinThread();
    queue->tryPop(value);
    cr_assert_eq(value, 10000);
    cr_assert_eq(queue->tryPop(value), false);
}
