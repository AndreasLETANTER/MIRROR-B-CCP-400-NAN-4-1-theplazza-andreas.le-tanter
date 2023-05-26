/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** ConditionVariable
*/

#pragma once
#include "IConditionVariable.hpp"

/**
 * @brief Class for condition variable
 * @details Used to wait for a condition to be true
*/
class ConditionVariable : public IConditionVariable {
    public:
        /**
         * @brief Construct a new Condition Variable object
        */
        ConditionVariable() = default;
        /**
         * @brief Destroy the Condition Variable object
        */
        ~ConditionVariable() override = default;
        /**
         * @brief Wait for a condition to be true
         * @details Wait for a condition to be true and lock the mutex passed as parameter
         * @param t_lock 
        */
        void wait(std::unique_lock<std::mutex> &t_lock) override;
        /**
         * @brief Notify one thread
        */
        void notify_one() override;
        /**
         * @brief Notify all threads
        */
        void notify_all() override;

    protected:
    private:
        std::condition_variable m_cond;
};
