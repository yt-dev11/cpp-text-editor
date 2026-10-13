# C++ Text Editor Core (`cpp-text-editor`)

A custom, CLI-based text editor engine built from scratch in C++. 

The primary objective of this project is deep, practical mastery of **Data Structures and Algorithms (DSA)**, dynamic memory management, and pointer manipulation without relying on pre-built high-level abstractions or GUI libraries.

---

## 🎯 Project Goals

- **Hands-on DSA:** Implement low-level data structures (Doubly Linked Lists, custom stacks, buffers) from scratch.
- **Memory Management:** Master explicit heap allocation (`new` / `delete`), pointer tracking, and memory safety.
- **Line-based Text Buffer:** Model text documents as dynamic nodes allowing constant-time insertion, traversal, and deletion.
- **Deep Learning Journey:** Document every architectural challenge, bug faced, and conceptual insight discovered along the way.

---

## 🏗️ Architecture & Core Concepts

- **Text Buffer Representation:** Doubly Linked List
  - Each `Node` represents a line of text (`std::string`).
  - Contains bidirectional pointers (`prev` and `next`) allowing efficient navigation up and down the document.
- **List Controller:**
  - Tracks `head`, `tail`, and document `size`.
  - Appends new lines in $O(1)$ time by maintaining the `tail` pointer.

---

## 📂 Repository Structure

- `editor.c++` — The core text editor source code.
- `DEVLOG.md` — Detailed engineering log of bugs encountered, conceptual breakdowns, and solutions.
- `README.md` — Project overview and architecture.

---

## 🚀 Building & Running

Compile with any modern C++ compiler (such as `g++`):

```bash
g++ -std=c++17 -Wall editor.c++ -o editor
./editor
```
