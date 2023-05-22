/*
** EPITECH PROJECT, 2023
** MIRROR-B-OOP-400-NAN-4-1-arcade-andreas.le-tanter [WSL: Ubuntu]
** File description:
** Timer
*/

#include "Timer.hpp"

/**
 * @brief Start the timer
 * @details Start the timer and set the _is_started boolean to true
*/
void Timer::StartTimer()
{
    if (m_is_started)
        return;
    m_start = std::chrono::system_clock::now();
    m_is_started = true;
}

/**
 * @brief Get the Elapsed Time object
 * @details Get the elapsed time in seconds
 * @return double
*/
double Timer::GetElapsedTime()
{
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::seconds>(end - m_start).count();
}

/**
 * @brief Get the Elapsed Time In Milli Seconds object
 * @details Get the elapsed time in milliseconds
 * @return double
*/
double Timer::GetElapsedTimeInMilliSeconds()
{
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - m_start).count();
}

/**
 * @brief Get the Elapsed Time In Micro Seconds object
 * @details Get the elapsed time in microseconds
 * @return double
*/
double Timer::GetElapsedTimeInMicroSeconds()
{
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - m_start).count();
}

/**
 * @brief Reset the timer
 * @details Reset the timer and set the _is_started boolean to false
*/
void Timer::ResetTimer()
{
    m_start = std::chrono::system_clock::now();
    m_is_started = false;
}
