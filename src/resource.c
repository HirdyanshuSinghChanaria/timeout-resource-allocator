#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include "resource.h"

// Mutex representing the shared resource
static pthread_mutex_t resource_lock = PTHREAD_MUTEX_INITIALIZER;

int request_resource_with_timeout(int id, int timeout_sec) {
    time_t start_time = time(NULL);

    while (1) {
        // Try to acquire the lock
        if (pthread_mutex_trylock(&resource_lock) == 0) {
            return 1;  // Successfully acquired
        }

        // Check if timeout exceeded
        if (time(NULL) - start_time >= timeout_sec) {
            return 0;  // Timed out
        }

        usleep(100000);  // Wait 100ms before retrying
    }
}

void release_resource(int id) {
    printf("🔓 Process %d released the resource.\n", id);
    pthread_mutex_unlock(&resource_lock);
}
