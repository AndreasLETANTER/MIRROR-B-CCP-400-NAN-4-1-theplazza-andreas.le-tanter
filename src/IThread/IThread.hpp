/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** IThread
*/

#pragma once
#include <thread>

/**
 * @brief ThreadStatus enum
 * @details Enum for the status of a thread (running or stopped)
*/
enum ThreadStatus {
    RUNNING,
    STOPPED
};

/**
 * @brief IThread class interface for threads
 * @details Interface for threads encapsulating a std::thread
*/
class IThread {
    public:
        virtual ~IThread() = default;
        virtual ThreadStatus getThreadStatus() = 0;
        virtual void stopThread() = 0;
        virtual void joinThread() = 0;

    protected:
    private:
};
