#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <iostream>
#include <unistd.h>

using namespace boost::interprocess;

// Define a type for the vector to be shared
typedef allocator<int, managed_shared_memory::segment_manager> ShmemAllocator;
typedef vector<int, ShmemAllocator> MyVector;

int main()
{
    const std::string segmentName = "MySharedMemory";

    // Create a shared memory segment
    managed_shared_memory segment(open_or_create, segmentName.c_str(), 65536);

    // Create an allocator for the shared memory segment
    const ShmemAllocator alloc_inst(segment.get_segment_manager());

    // Construct the shared vector in the shared memory
    MyVector* sharedVector = segment.construct<MyVector>("SharedVector")(alloc_inst);

    // Fork the process
    pid_t pid = fork();

    if (pid == -1)
    {
        std::cerr << "Fork failed!" << std::endl;
        return 1;
    }
    else if (pid == 0)
    {
        // Child process

        // Access the shared vector
        MyVector* childVector = segment.find<MyVector>("SharedVector").first;

        // Print the values in the shared vector from the child process
        for (const auto& value : *childVector)
            std::cout << value << " ";
        std::cout << std::endl;
    }
    else
    {
        // Parent process

        // Add some values to the shared vector
        for (int i = 0; i < 10; ++i)
            sharedVector->push_back(i);

        // Wait for the child process to complete
        wait(nullptr);
    }

    // Destroy and deallocate the shared vector
    segment.destroy<MyVector>("SharedVector");

    // Remove the shared memory segment
    shared_memory_object::remove(segmentName.c_str());

    return 0;
}
