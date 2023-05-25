/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** SharedMemory
*/

#include "SharedMemory.hpp"

template<typename T>
SharedMemory<T>::SharedMemory(std::string t_memoryName, size_t t_memorySize)
{
    createSharedMemory(t_memoryName, t_memorySize);
}

template<typename T>
SharedMemory<T>::~SharedMemory()
{
    destroySegment("segment");
    destroySharedMemory("memory");
}

template<typename T>
void SharedMemory<T>::createSharedMemory(std::string t_memoryName, size_t t_memorySize)
{
    m_memoryName = t_memoryName;
    m_memorySize = t_memorySize;
    m_segment = boost::interprocess::managed_shared_memory(boost::interprocess::create_only, t_memoryName.c_str(), t_memorySize);
}

template<typename T>
void SharedMemory<T>::constructSegment(std::string t_segmentName)
{
    m_segmentName = t_segmentName;
    m_segment.construct<T>(t_segmentName.c_str())(nullptr);
}

template<typename T>
void SharedMemory<T>::destroySegment(std::string t_segmentName)
{
    m_segment.destroy<T>(t_segmentName.c_str());
}

template<typename T>
void SharedMemory<T>::destroySharedMemory(std::string t_memoryName)
{
    boost::interprocess::shared_memory_object::remove(t_memoryName.c_str());
}

template<typename T>
T *SharedMemory<T>::getSegment(std::string t_segmentName)
{
    return (m_segment.find<T>(t_segmentName.c_str()).first);
}
