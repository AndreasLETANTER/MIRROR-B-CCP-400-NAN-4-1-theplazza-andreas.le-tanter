/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** SharedMemory
*/

#include "SharedMemory.hpp"

/**
 * @brief Construct a new Shared Memory< T>:: Shared Memory object
 * @details Construct a new Shared Memory< T>:: Shared Memory object and initialize it
 * @tparam T Type of the shared memory
 * @param t_memoryName The name of the memory
 * @param t_memorySize The size of the memory
*/
template<typename T>
SharedMemory<T>::SharedMemory(std::string t_memoryName, size_t t_memorySize)
{
    createSharedMemory(t_memoryName, t_memorySize);
}

/**
 * @brief Destroy the ISharedMemory object
 * @details Destroy the ISharedMemory object and clean the memory
*/
template<typename T>
SharedMemory<T>::~SharedMemory()
{
    destroySegment("segment");
    destroySharedMemory("memory");
}

/**
 * @brief Create a Shared Memory object
 * @details Create a Shared Memory object and initialize it
 * @param t_memoryName The name of the memory
 * @param t_memorySize The size of the memory
*/
template<typename T>
void SharedMemory<T>::createSharedMemory(std::string t_memoryName, size_t t_memorySize)
{
    m_memoryName = t_memoryName;
    m_memorySize = t_memorySize;
    m_segment = boost::interprocess::managed_shared_memory(boost::interprocess::create_only, t_memoryName.c_str(), t_memorySize);
}

/**
 * @brief Construct a Segment object
 * @details Construct a Segment object and initialize it
 * @param t_segmentName The name of the segment
*/
template<typename T>
void SharedMemory<T>::constructSegment(std::string t_segmentName)
{
    m_segmentName = t_segmentName;
    m_segment.construct<T>(t_segmentName.c_str())(nullptr);
}

/**
 * @brief Destroy a Segment object
 * @details Destroy a Segment object and clean the memory
 * @param t_segmentName The name of the segment
*/
template<typename T>
void SharedMemory<T>::destroySegment(std::string t_segmentName)
{
    m_segment.destroy<T>(t_segmentName.c_str());
}

/**
 * @brief Destroy a Shared Memory object
 * @details Destroy a Shared Memory object and clean the memory
 * @param t_memoryName The name of the memory
*/
template<typename T>
void SharedMemory<T>::destroySharedMemory(std::string t_memoryName)
{
    boost::interprocess::shared_memory_object::remove(t_memoryName.c_str());
}

/**
 * @brief Get the Segment object
 * @details Get the Segment object
 * @param t_segmentName The name of the segment
 * @return T* The segment
*/
template<typename T>
T *SharedMemory<T>::getSegment(std::string t_segmentName)
{
    return (m_segment.find<T>(t_segmentName.c_str()).first);
}
