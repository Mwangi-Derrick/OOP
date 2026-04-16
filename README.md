# EEE 2216: Object-Oriented Programming (C++)

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![JKUAT](https://img.shields.io/badge/JKUAT-EEE-green?style=for-the-badge)
![Systems Engineering](https://img.shields.io/badge/Systems_Engineer-Go_|_Rust_|_Zig-orange?style=for-the-badge)

This repository serves as a comprehensive record of my transition from structured programming in C to Object-Oriented Programming (OOP) in C++, specifically for the **EEE 2216** unit at **Jomo Kenyatta University of Agriculture and Technology (JKUAT)**.

As a systems engineer primarily focused on **Go**, **Rust**, and **Zig**, this repository documents my deep dive into the C++ ecosystem—bridging the gap between the low-level control of C and the high-level abstractions of modern object-oriented design.

---

## 🚀 The Transition: C → C++

Having mastered structured programming in C during the first semester of my second year, this course (EEE 2216) focuses on the paradigm shift toward objects, classes, and generic programming.

### Core Paradigms Explored:
*   **Encapsulation:** Moving beyond structs to classes with private/protected data and public interfaces.
*   **Inheritance:** Building hierarchical structures to reuse logic and model real-world EEE entities.
*   **Polymorphism:** Leveraging `virtual` functions and pure virtual interfaces for dynamic dispatch.
*   **Memory Management:** Exploring the stack, the heap, and the C++ Standard Template Library (STL).

---

## 📂 Repository Structure

The codebase is organized by conceptual milestones:

```bash
cpp/
├── classes/                # The heart of OOP
│   ├── abstract/           # Pure virtual functions & interfaces (e.g., Shape)
│   ├── inheritance/        # Class hierarchies and access specifiers
│   ├── polymorphism/       # Dynamic binding and method overriding
│   └── student/            # Practical implementation of domain-specific objects
├── mem_management/         # Vectors, stacks, queues, and memory sizing
├── stl_cpp/                # Standard Template Library (Iterators, Containers)
├── calculator/             # Initial logic implementation in C++
├── functions/              # Transitioning procedural logic from C
└── password/               # String manipulation and logic
```

---

## 🛠️ Key Implementations

### 1. Abstract Interfaces & Polymorphism
In `cpp/classes/abstract/shape.cpp`, I implemented a "Drawing App" logic using pure virtual functions (`virtual void draw() = 0;`). This demonstrates how C++ handles interfaces, a concept familiar from Go's `interface` or Rust's `traits`, but with the unique C++ flavor of vtables.

### 2. Standard Template Library (STL)
Transitioning from manual memory management in C to STL containers like `std::vector`, `std::stack`, and `std::queue`. This section focuses on efficient data handling and the `algorithm` header.

### 3. Domain-Specific Modeling
The `student` and `calculator` modules apply OOP principles to solve specific engineering problems, focusing on data integrity and clean APIs.

---

## 💻 Personal Context

While my daily tools of choice are **Go** (for its concurrency and simplicity) and **Rust** (for its safety and zero-cost abstractions), learning C++ provides:
- A deeper understanding of the "Object-Oriented" roots that influenced modern languages.
- Direct experience with the manual and semi-automated memory management models (RAII).
- A solid foundation for embedded systems engineering and high-performance computing.

---

## ⚙️ How to Build

All modules can be compiled using `g++`. For example, to compile the abstract shape implementation:

```powershell
g++ cpp/classes/abstract/shape.cpp -o shape.exe
./shape.exe
```

---

*“The transition from C to C++ is not just about changing syntax; it's about changing how you think about the relationship between data and the logic that operates on it.”*
