#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>  // for sleep and usleep
#include "process.h"
#include "resource.h"

#define NUM_PROCESSES 5  // You can increase this if you want

// This function will run in a thread
void* process(void* arg) {
    int id = *(int*)arg;
    free(arg);  // Free allocated memory

    printf("🟡 Process %d requesting resource...\n", id);

    // Try to acquire resource with timeout of 3 seconds
    if (request_resource_with_timeout(id, 3)) {
        printf("✅ Process %d acquired the resource.\n", id);

        sleep(2);  // Simulate resource usage

        release_resource(id);
    } else {
        printf("⏳ Process %d timed out waiting for the resource.\n", id);
    }

    return NULL;
}

// Starts all the processes (threads)
void start_process_simulation() {
    pthread_t threads[NUM_PROCESSES];

    for (int i = 0; i < NUM_PROCESSES; i++) {
        int* id = malloc(sizeof(int));
        *id = i + 1;

        pthread_create(&threads[i], NULL, process, id);
        usleep(300000);  // Stagger process creation slightly (300ms)
    }

    for (int i = 0; i < NUM_PROCESSES; i++) {
        pthread_join(threads[i], NULL);
    }
}