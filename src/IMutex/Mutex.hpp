/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** Mutex
*/

#pragma once
#include "IMutex.hpp"
#include <mutex>

class Mutex : public IMutex {
    public:
        Mutex();
        ~Mutex();
        void lock() override;
        void unlock() override;
        void trylock() override;
        std::mutex &getMutex() override { return _mutex; }

    protected:
    private:
        std::mutex _mutex;
};
