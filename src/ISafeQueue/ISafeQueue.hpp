/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** ISafeQueue
*/

#pragma once

/**
 * @brief ISafeQueue class
 * @details Interface for a thread safe queue
*/
template <typename T>
class ISafeQueue {
    public:
        /**
         * @brief Destroy the Safe Queue< T>:: Safe Queue object
         * @details Destroy the Safe Queue< T>:: Safe Queue object and clear the queue
         * @tparam T type of the queue
        */
        virtual ~ISafeQueue() = default;
        /**
         * @brief push a value in the queue
         * @tparam T type of the queue
         * @param value value to push
        */
        virtual void push(T value) = 0;
        /**
         * @brief try to pop a value from the queue
         * @tparam T type of the queue
         * @param value value to pop
         * @return true if the queue is not empty
         * @return false if the queue is empty
        */
        virtual bool tryPop(T &value) = 0;
        /**
         * @brief pop a value from the queue
         * @details pop a value from the queue and wait if the queue is empty until a value is pushed
         * @tparam T type of the queue
         * @return T value
        */
        virtual T pop() = 0;
        /**
         * @brief get the size of the queue
         * @tparam T type of the queue
         * @return size_t size of the queue
        */
        virtual size_t size() = 0;

    protected:
    private:
};
