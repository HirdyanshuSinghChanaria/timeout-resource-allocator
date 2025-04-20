#ifndef RESOURCE_H
#define RESOURCE_H

// Tries to lock the resource with timeout (in seconds)
int request_resource_with_timeout(int id, int timeout_sec);

// Unlocks the resource
void release_resource(int id);

#endif
