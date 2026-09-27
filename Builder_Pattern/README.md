# Prototype Design Pattern Implementation

## Real-World Scenario: Game Unit & Character Spawning Engine (RTS/RPG)

### Problem
Instantiating game units (`Swordsman`, `Archer`, `Mage`) from scratch requires loading 3D meshes, textures, sound effects, skill trees, and baseline statistics. In real-time combat, instantiating dozens of units from scratch causes massive frame drops and CPU spikes. Furthermore, spawning via `new ConcreteClass()` tightly couples client spawner code to concrete classes.

### Solution
The **Prototype Pattern** pre-loads prototypical unit instances into a **`UnitRegistry`** at game launch. When units are spawned, the registry calls their virtual `clone()` method, providing lightning-fast deep copying via the copy constructor. Dynamic per-unit attributes (e.g., spawn coordinates, nickname) are configured after cloning.

### How to Compile & Run
```bash
g++ -std=c++17 -Wall -Wextra prototype_pattern.cpp -o prototype_pattern
./prototype_pattern
```
