/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** SharedMemory
*/

#pragma once
#include "ISharedMemory.hpp"
#include <string>

/**
 * @brief Shared memory class
 * @details Used to create and destroy shared memory
 * @tparam T Type of the shared memory
*/
template<typename T>
class SharedMemory : public ISharedMemory<T> {
    public:
        /**
         * @brief Construct a new Shared Memory< T>:: Shared Memory object
         * @details Construct a new Shared Memory< T>:: Shared Memory object
        */
        SharedMemory() = default;
        /**
         * @brief Construct a new Shared Memory< T>:: Shared Memory object
         * @details Construct a new Shared Memory< T>:: Shared Memory object and initialize it
         * @tparam T Type of the shared memory
         * @param t_memoryName The name of the memory
         * @param t_memorySize The size of the memory
        */
        SharedMemory(std::string t_memoryName, size_t t_memorySize);
        /**
         * @brief Destroy the ISharedMemory object
         * @details Destroy the ISharedMemory object and clean the memory
        */
        ~SharedMemory() override;
        /**
         * @brief Create a Shared Memory object
         * @details Create a Shared Memory object and initialize it
         * @param t_memoryName The name of the memory
         * @param t_memorySize The size of the memory
        */
        void createSharedMemory(std::string t_memoryName, size_t t_memorySize) override;
        /**
         * @brief Construct a Segment object
         * @details Construct a Segment object and initialize it
         * @param t_segmentName The name of the segment
        */
        void constructSegment(std::string t_segmentName) override;
        /**
         * @brief Destroy a Segment object
         * @details Destroy a Segment object and clean the memory
         * @param t_segmentName The name of the segment
        */
        void destroySegment(std::string t_segmentName) override;
        /**
         * @brief Destroy a Shared Memory object
         * @details Destroy a Shared Memory object and clean the memory
         * @param t_memoryName The name of the memory
        */
        void destroySharedMemory(std::string t_memoryName) override;
        /**
         * @brief Get the Segment object
         * @details Get the Segment object
         * @param t_segmentName The name of the segment
         * @return T* The segment
        */
        T *getSegment(std::string t_segmentName) override;

    protected:
    private:
        boost::interprocess::managed_shared_memory m_segment;
        std::string m_memoryName;
        size_t m_memorySize;
        std::string m_segmentName;
};

#include "SharedMemory.tpp"
