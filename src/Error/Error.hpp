/*
** EPITECH PROJECT, 2023
** MIRROR--B-OOP-400-NAN-4-1-tekspice-andreas.le-tanter [WSL : Ubuntu]
** File description:
** Error
*/

#pragma once
#include <string>

/**
 * @brief Error class
 * @details Used to throw errors with a message
*/
class Error : public std::exception
{
    public:
        /**
         * @brief Construct a new Error object
         * @param message The message to throw
        */
        Error(std::string message) { this->_message = message; };
        /**
         * @brief Destroy the Error object
        */
        const char *what() const noexcept;

    protected:
        std::string _message;
    private:
};
