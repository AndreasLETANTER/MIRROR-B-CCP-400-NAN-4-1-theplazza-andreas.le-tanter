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

template<typename T>
class ISharedMemory {
    public:
        virtual ~ISharedMemory() = default;
        virtual void createSharedMemory(std::string t_memoryName, size_t t_memorySize) = 0;
        virtual void constructSegment(std::string t_segmentName) = 0;
        virtual void destroySegment(std::string t_segmentName) = 0;
        virtual void destroySharedMemory(std::string t_memoryName) = 0;
        virtual T getSegment(std::string t_segmentName) = 0;

    protected:
    private:
};
