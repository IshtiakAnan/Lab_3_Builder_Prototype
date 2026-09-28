# Builder Design Pattern Implementation

## Real-World Scenario: Custom Desktop Computer Assembly System

### Problem
Constructing a PC involves multiple components (Motherboard, CPU, RAM, Storage, GPU, Power Supply, Cooling, Wi-Fi). A traditional constructor leads to the **Telescoping Constructor Anti-Pattern** with 8+ arguments, difficult-to-track parameters, and forced empty/null arguments for budget or barebones systems.

### Solution
The **Builder Pattern** encapsulates the creation of each hardware subsystem in dedicated methods (`buildCPU()`, `buildGPU()`, `buildRAM()`, etc.) and allows a **Director** (`ComputerAssembler`) to assemble standard configurations or permits the client to assemble custom builds step-by-step.

### How to Compile & Run
```bash
g++ -std=c++17 -Wall -Wextra builder_pattern.cpp -o builder_pattern
./builder_pattern
```
