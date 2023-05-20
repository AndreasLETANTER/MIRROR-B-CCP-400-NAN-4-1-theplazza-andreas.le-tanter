/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL: Ubuntu]
** File description:
** Timer
*/

#pragma once
#include <chrono>

/**
 * @brief Timer class
*/
class Timer {
    public:
        Timer() = default;
        ~Timer() = default;
        void StartTimer();
        double GetElapsedTime();
        double GetElapsedTimeInMilliSeconds();
        double GetElapsedTimeInMicroSeconds();
        void ResetTimer();
        bool IsStarted() { return m_is_started; };

    protected:
    private:
        std::chrono::time_point<std::chrono::system_clock> m_start;
        bool m_is_started = false;
};
