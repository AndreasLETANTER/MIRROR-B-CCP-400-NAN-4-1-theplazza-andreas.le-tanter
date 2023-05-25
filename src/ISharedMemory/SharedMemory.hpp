/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** SharedMemory
*/

#pragma once
#include "ISharedMemory.hpp"
#include <string>

template<typename T>
class SharedMemory : public ISharedMemory<T> {
    public:
        SharedMemory() = default;
        SharedMemory(std::string t_memoryName, size_t t_memorySize);
        ~SharedMemory() override;
        void createSharedMemory(std::string t_memoryName, size_t t_memorySize) override;
        void constructSegment(std::string t_segmentName) override;
        void destroySegment(std::string t_segmentName) override;
        void destroySharedMemory(std::string t_memoryName) override;
        T *getSegment(std::string t_segmentName) override;

    protected:
    private:
        boost::interprocess::managed_shared_memory m_segment;
        std::string m_memoryName;
        size_t m_memorySize;
        std::string m_segmentName;
};

#include "SharedMemory.tpp"
