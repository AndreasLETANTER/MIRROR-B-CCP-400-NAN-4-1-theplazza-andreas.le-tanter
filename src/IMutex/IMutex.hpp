/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** IMutex
*/

#pragma once
#include <mutex>

class IMutex {
    public :
        virtual ~IMutex() = default;
        virtual void lock() = 0;
        virtual void unlock() = 0;
        virtual void trylock() = 0;
        virtual std::mutex &getMutex() = 0;

    protected:
    private:
};
