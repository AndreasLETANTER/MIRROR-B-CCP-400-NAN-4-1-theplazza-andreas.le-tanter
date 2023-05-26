/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** ISharedMemory
*/

#pragma once
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/vector.hpp>

/**
 * @brief Interface for SharedMemory
 * @tparam T  Type of the shared memory
*/
template<typename T>
class ISharedMemory {
    public:
        /**
         * @brief Destroy the ISharedMemory object
         * @details Destroy the ISharedMemory object and clean the memory
        */
        virtual ~ISharedMemory() = default;
        /**
         * @brief Create a Shared Memory object
         * @details Create a Shared Memory object and initialize it
         * @param t_memoryName The name of the memory
         * @param t_memorySize The size of the memory
        */
        virtual void createSharedMemory(std::string t_memoryName, size_t t_memorySize) = 0;
        /**
         * @brief Construct a Segment object
         * @details Construct a Segment object and initialize it
         * @param t_segmentName The name of the segment
        */
        virtual void constructSegment(std::string t_segmentName) = 0;
        /**
         * @brief Destroy a Segment object
         * @details Destroy a Segment object and clean the memory
         * @param t_segmentName The name of the segment
        */
        virtual void destroySegment(std::string t_segmentName) = 0;
        /**
         * @brief Destroy a Shared Memory object
         * @details Destroy a Shared Memory object and clean the memory
         * @param t_memoryName The name of the memory
        */
        virtual void destroySharedMemory(std::string t_memoryName) = 0;
        /**
         * @brief Get the Segment object
         * @details Get the Segment object
         * @param t_segmentName The name of the segment
         * @return T* The segment
        */
        virtual T *getSegment(std::string t_segmentName) = 0;

    protected:
    private:
};
