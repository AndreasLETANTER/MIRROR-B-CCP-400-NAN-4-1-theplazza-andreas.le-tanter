#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_KEY 1234
#define SHM_SIZE 10

int main() {
    int shm_id;
    key_t key = SHM_KEY;
    int* shm_ptr;
    int pid;

    // Create a shared memory segment
    shm_id = shmget(key, SHM_SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment
    shm_ptr = (int*)shmat(shm_id, NULL, 0);
    if (shm_ptr == (int*)-1) {
        perror("shmat");
        exit(1);
    }

    // Fork the process
    pid = fork();

    if (pid > 0) {
        // Parent process

        // Write data to the shared memory segment
        int data[5] = {1, 2, 3, 4, 5};
        for (int i = 0; i < 5; i++) {
            shm_ptr[i] = data[i];
        }

        // Wait for the child process to finish
        wait(NULL);

        // Read the modified data from the shared memory segment
        std::cout << "Modified data in parent: ";
        for (int i = 0; i < 5; i++) {
            std::cout << shm_ptr[i] << " ";
        }
        std::cout << std::endl;

    } else if (pid == 0) {
        // Child process

        // Wait for the parent process to write data to the shared memory segment
        wait(NULL);

        // Read the data from the shared memory segment
        std::cout << "Data in child: ";
        for (int i = 0; i < 5; i++) {
            std::cout << shm_ptr[i] << " ";
        }
        std::cout << std::endl;

        // Modify the data
        for (int i = 0; i < 3; i++) {
            shm_ptr[i] += 10;
        }

        // Detach the shared memory segment
        if (shmdt(shm_ptr) == -1) {
            perror("shmdt");
            exit(1);
        }

        exit(0);
    } else {
        perror("fork");
        exit(1);
    }

    // Detach the shared memory segment
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Remove the shared memory segment
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}
