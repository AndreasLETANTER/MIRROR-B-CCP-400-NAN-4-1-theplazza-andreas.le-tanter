/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** IThread
*/

#pragma once
#include <thread>

enum ThreadStatus {
    RUNNING,
    STOPPED
};

class IThread {
    public:
        virtual ~IThread() = default;
        virtual ThreadStatus getThreadStatus() = 0;
        virtual void stopThread() = 0;
        virtual void joinThread() = 0;

    protected:
    private:
};
