/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** IConditionVariable
*/

#pragma once
#include <mutex>

class IConditionVariable {
    public:
        virtual ~IConditionVariable() = default;
        virtual void wait(std::unique_lock<std::mutex> &t_lock) = 0;
        virtual void notify_one() = 0;
        virtual void notify_all() = 0;

    protected:
    private:
};
