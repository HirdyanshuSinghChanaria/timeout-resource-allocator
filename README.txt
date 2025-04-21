
Timeout-Based Resource Allocation (C Project)
============================================

This project simulates timeout-based resource allocation in an operating system.
It models how processes request resources and wait for allocation within a specific timeout period.
If the timeout expires, the request is denied.

Project Structure
-----------------
timeout-resource-allocator/
│
├── include/                # Header files
│   ├── process.h
│   ├── resource.h
│   └── timeout.h
│
├── src/                    # Source files
│   ├── main.c
│   ├── process.c
│   ├── resource.c
│   └── timeout.c
│
├── Makefile
└── README.txt              # Project documentation

Description
-----------
- Simulates processes requesting system resources.
- Allocates resources if available, otherwise waits.
- If timeout is reached, the request is denied.
- Written in modular C code using header and source files.
- Makefile is used for compiling the project.


Future Work
-----------
* Build a GUI visualizing resource allocation in real time.
* Implement priority-based allocation.
* Add deadlock detection and recovery.
* Add config files to set number of processes, timeouts, resources, etc.
