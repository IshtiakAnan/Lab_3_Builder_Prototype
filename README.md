# CSE 3206: Software Engineering Sessional
## Lab 3: Design Pattern Analysis, Implementation and Code Review
**Department of Computer Science & Engineering, Rajshahi University of Engineering & Technology (RUET)**

---

### Group Information
* **Presentation Group:** Group 2
* **Assigned Design Patterns:** **Builder Pattern** & **Prototype Pattern** (Creational Design Patterns)
* **Total Marks:** 08 Marks

---

### Repository Structure

```text
.
├── 1_Builder_Pattern/
│   ├── builder_pattern.cpp       # C++17 implementation (PC Assembly scenario)
│   ├── builder_pattern           # Compiled binary
│   └── README.md                 # Pattern details & explanation
├── 2_Prototype_Pattern/
│   ├── prototype_pattern.cpp     # C++17 implementation (Game Unit Spawning scenario)
│   ├── prototype_pattern         # Compiled binary
│   └── README.md                 # Pattern details & explanation
├── docs/
│   ├── Lab_3_Group_2_Documentation.pdf   # Complete 15-section Lab Lecture Documentation
│   ├── Lab_3_Group_2_Documentation.md    # Markdown source of documentation
│   ├── Code_Review_Report_Template.md    # 10-point peer code review sheet
│   └── diagrams/
│       ├── builder_pattern_uml.svg       # High-res SVG UML Class Diagram
│       └── prototype_pattern_uml.svg     # High-res SVG UML Class Diagram
├── Makefile                              # Build automation
└── README.md                             # Project overview
```

---

### Quick Start: Compilation & Execution

To compile and run both design patterns at once:
```bash
make run
```

To run individual patterns:
```bash
# Builder Pattern
make run-builder

# Prototype Pattern
make run-prototype
```

---

### Pattern Summary

#### 1. Builder Pattern
* **Category:** Creational
* **Scenario:** Custom Desktop Computer Assembly System (High-End Gaming PC vs. Office PC vs. Barebones Server)
* **Intent:** Separates complex object construction from representation.
* **Key Components:**
  * **Product:** `Computer`
  * **Builder Interface:** `ComputerBuilder`
  * **Concrete Builders:** `GamingComputerBuilder`, `OfficeComputerBuilder`
  * **Director:** `ComputerAssembler`
  * **Client:** `main()`

#### 2. Prototype Pattern
* **Category:** Creational
* **Scenario:** RTS/RPG Game Unit Spawner (Swordsman, Archer, Mage)
* **Intent:** Creates duplicates of pre-configured objects via `clone()` method without expensive re-initialization.
* **Key Components:**
  * **Prototype Interface:** `GameUnit`
  * **Concrete Prototypes:** `Swordsman`, `Archer`, `Mage`
  * **Prototype Registry:** `UnitRegistry`
  * **Client:** `main()`

---

### Deliverables Checklist

- [x] **1. Lab Lecture Documentation (PDF):** [`docs/Lab_3_Group_2_Documentation.pdf`](docs/Lab_3_Group_2_Documentation.pdf)
- [x] **2. Source Code:** C++17 source files in folders `1_Builder_Pattern/` and `2_Prototype_Pattern/`
- [x] **3. UML / Class Diagrams:** Standalone SVG files in [`docs/diagrams/`](docs/diagrams/)
- [x] **4. GitHub Repository:** Complete structured layout with build scripts
- [x] **5. Code Review Report:** Ready-to-fill evaluation sheet in [`docs/Code_Review_Report_Template.md`](docs/Code_Review_Report_Template.md)
