/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** ITimer
*/

#pragma once

class ITimer {
    public:
        virtual ~ITimer() = default;
        /**
         * @brief Start the timer
         * @details Start the timer and set the _is_started boolean to true
        */
        virtual void startTimer() = 0;
        /**
         * @brief Get the Elapsed Time object
         * @details Get the elapsed time in seconds
         * @return double
        */
        virtual double getElapsedTime() = 0;
        /**
         * @brief Get the Elapsed Time In Milli Seconds object
         * @details Get the elapsed time in milliseconds
         * @return double
        */
        virtual double getElapsedTimeInMilliSeconds() = 0;
        /**
         * @brief Get the Elapsed Time In Micro Seconds object
         * @details Get the elapsed time in microseconds
         * @return double
        */
        virtual double getElapsedTimeInMicroSeconds() = 0;
        /**
         * @brief Reset the timer
         * @details Reset the timer and set the _is_started boolean to false
        */
        virtual void resetTimer() = 0;
        /**
         * @brief Check if the timer is started
         * @return true if the timer is started
         * @return false if the timer is not started 
         */
        virtual bool isStarted() = 0;

    protected:
    private:
};
