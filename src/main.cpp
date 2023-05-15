/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** main
*/

#include <vector>
#include <thread>
#include <iostream>
#include <memory>
#include "IThread/Thread.hpp"
#include "IMutex/Mutex.hpp"
#include "IMutex/ScopedLock/ScopedLock.hpp"
#include "ISafeQueue/SafeQueue.hpp"
#include <random>


void producerRoutine(std::shared_ptr<ISafeQueue<int>> queue)
{
    int value;

    while (1) {
        value = rand() % 100;
        queue->push(value);
    }
}

void consumerRoutine(std::shared_ptr<ISafeQueue<int>> queue)
{
    int value;

    while ((value = queue->pop()) != -1) {
        std::cout << value << std::endl;
    }
}

int main(int argc, char **argv)
{
    int nb_producers = std::stoi(argv[1]);
    int nb_consumers = std::stoi(argv[2]);
    std::vector<std::unique_ptr<IThread>> threads;
    std::shared_ptr<IMutex> _mutex = std::make_shared<Mutex>();
    std::shared_ptr<ISafeQueue<int>> queue = std::make_shared<SafeQueue<int>>(_mutex);

    if (argc != 3)
        return (84);
    for (int i = 0; i < nb_producers; i++)
        threads.push_back(std::make_unique<Thread<decltype(producerRoutine), decltype(queue)>>(producerRoutine, queue));
    for (int i = 0; i < nb_consumers; i++)
        threads.push_back(std::make_unique<Thread<decltype(consumerRoutine), decltype(queue)>>(consumerRoutine, queue));
    for (auto &thread : threads)
        thread->joinThread();
    return 0;
}
