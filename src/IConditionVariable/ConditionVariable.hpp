/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** ConditionVariable
*/

#pragma once
#include "IConditionVariable.hpp"

class ConditionVariable : public IConditionVariable {
    public:
        ConditionVariable() = default;
        ~ConditionVariable() override = default;
        void wait(std::unique_lock<std::mutex> &t_lock) override;
        void notify_one() override;
        void notify_all() override;

    protected:
    private:
        std::condition_variable m_cond;
};
