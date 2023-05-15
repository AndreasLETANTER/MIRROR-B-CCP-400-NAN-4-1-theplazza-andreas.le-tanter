/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** ISafeQueue
*/

#pragma once

/**
 * @brief ISafeQueue class
 * @details Interface for a thread safe queue
*/
template <typename T>
class ISafeQueue {
    public:
        virtual ~ISafeQueue() = default;
        virtual void push(T value) = 0;
        virtual bool tryPop(T &value) = 0;
        virtual T pop() = 0;

    protected:
    private:
};
