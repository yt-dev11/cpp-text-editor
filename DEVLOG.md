# Engineering DevLog: `cpp-text-editor`

A technical journal tracking challenges, architectural decisions, bugs encountered, and conceptual lessons learned during development.

---

## Log #001: Core Line Storage & Input Processing

### 1. Goal
Initialize the core editor structure to accept user input line-by-line and store each line in a custom **Doubly Linked List** buffer, exiting cleanly when `"exit"` is entered.

---

### 2. Challenges & Bugs Encountered

#### Challenge A: New Node Overwriting Previous Nodes
- **Observation:** When creating nodes inside a loop, each new line appeared to overwrite the previous line instead of creating a fresh, independent node.
- **Initial Hypothesis:** The loop used the same pointer variable name (`Node* n`), suspecting variable naming collision.
- **Root Cause & Concept:**
  - Variable names only exist at compile time; runtime memory is determined by memory address.
  - Creating a node as a local stack variable inside a factory function (e.g., `Node temp; return &temp;`) returns a dangling pointer to stack memory that gets reused across iterations.
  - In C++, to create an object whose lifetime outlives the function call, it must be explicitly allocated on the **heap** using dynamic allocation (`new Node`).
- **Resolution:**
  - Used `new Node` in dynamic memory so each node has a unique heap address.
  - Verified proper linking in `push()` by connecting `n->prev = a.tail` and `a.tail->next = n`.

---

#### Challenge B: Single-Word Capture with Stream Extraction
- **Observation:** Typing lines with spaces only captured the very first word.
- **Root Cause & Concept:**
  - The standard stream extraction operator `cin >> T` treats whitespace (spaces, tabs, newlines) as delimiters. It stops reading at the first space and leaves the remainder in the `std::cin` input buffer.
  - To read full sentences and lines of text, line-oriented input is required.
- **Resolution:**
  - Replaced `cin >> T` with `std::getline(cin, T)` to consume the full line up to the newline character.

---

#### Challenge C: Loop Control Flow
- **Observation:** Stopping the input loop on `"exit"` by manually setting the counter to its limit (`i = 40`).
- **Concept:**
  - In idiomatic C++, manual counter manipulation inside the loop body can introduce off-by-one errors and obscure intent.
  - `break` provides an immediate, explicit exit from the loop scope without relying on arbitrary counter limits.

---

### 3. Current State & Next Milestones
- [x] Doubly linked list node and list definitions.
- [x] Dynamic allocation factory (`Nodemaker`) and initial list setup (`listmaker`).
- [x] Tail-appending push operation ($O(1)$ complexity).
- [x] Multi-word line input loop.
- [ ] Navigation / line traversal (moving cursor up and down through `prev` and `next`).
- [ ] Line deletion and insertion at arbitrary positions.
- [ ] Document memory deallocation / cleanup (`delete` on exit).
