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
        /**
         * @brief Start the timer
         * @details Start the timer and set the _is_started boolean to true
        */
        void StartTimer();
        /**
         * @brief Get the Elapsed Time object
         * @details Get the elapsed time in seconds
         * @return double
        */
        double GetElapsedTime();
        /**
         * @brief Get the Elapsed Time In Milli Seconds object
         * @details Get the elapsed time in milliseconds
         * @return double
        */
        double GetElapsedTimeInMilliSeconds();
        /**
         * @brief Get the Elapsed Time In Micro Seconds object
         * @details Get the elapsed time in microseconds
         * @return double
        */
        double GetElapsedTimeInMicroSeconds();
        /**
         * @brief Reset the timer
         * @details Reset the timer and set the _is_started boolean to false
        */
        void ResetTimer();
        /**
         * @brief Check if the timer is started
         * @return true if the timer is started
         * @return false if the timer is not started 
         */
        bool IsStarted() { return m_is_started; };

    protected:
    private:
        std::chrono::time_point<std::chrono::system_clock> m_start;
        bool m_is_started = false;
};
