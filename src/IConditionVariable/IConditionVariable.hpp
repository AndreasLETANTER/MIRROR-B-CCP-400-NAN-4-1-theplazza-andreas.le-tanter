/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** IConditionVariable
*/

#pragma once
#include <mutex>
#include <condition_variable>

/**
 * @brief Interface for condition variable
 * @details Used to wait for a condition to be true
*/
class IConditionVariable {
    public:
        /**
         * @brief Destroy the IConditionVariable object
        */
        virtual ~IConditionVariable() = default;
        /**
         * @brief Wait for a condition to be true
         * @details Wait for a condition to be true and lock the mutex passed as parameter
         * @param t_lock 
        */
        virtual void wait(std::unique_lock<std::mutex> &t_lock) = 0;
        /**
         * @brief Notify one thread
        */
        virtual void notify_one() = 0;
        /**
         * @brief Notify all threads
        */
        virtual void notify_all() = 0;

    protected:
    private:
};
