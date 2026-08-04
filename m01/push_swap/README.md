*This project has been created as part of the 42 curriculum by dlandi, lfurtado.*

## Description

Push_swap is a highly efficient algorithmic project that challenges you to sort a stack of integers using a restricted set of instructions with the minimum possible number of operations. The program receives a randomly ordered stack (stack A) and utilizes an auxiliary empty stack (stack B) to sort the data in ascending order via operations including swaps (`sa`, `sb`, `ss`), pushes (`pa`, `pb`), and rotations (`ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).

Beyond the core subject requirements, this implementation features:

* Four Selectable Strategies: Simple, Medium, Complex, and Adaptive.


* Disorder Metrics: Computes the exact ratio of inverted pairs prior to execution.


* Benchmark Mode (`--bench`): Provides live telemetry tracking strategy selection, disorder scores, and operation breakdowns.



## Instructions

### Compilation

Compile the project using the root `Makefile`:

* `make` — Compiles the executable with `-Wall -Wextra -Werror`, building `libft` automatically.


* `make clean` — Removes object files.


* `make fclean` — Removes object files and binaries (`push_swap` and `libft.a`).


* `make re` — Performs a full clean rebuild.



### Execution

Run the program with your desired strategy flags and integer arguments:

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <numbers...>

```

**Examples:**

```bash
./push_swap 4 67 3 87 23
./push_swap --simple 5 4 3 2 1
./push_swap --bench --adaptive 2 1 3 6 5 8

```

Error handling complies strictly with the project standard: non-integers, out-of-range values, overflows, and duplicates output `Error` to `stderr` and exit cleanly with zero memory leaks.

## Algorithms Selected and Justification

Before executing any sorting routine, `update_index` normalizes element values. If `--bench` is active, `calculate_disorder` measures initial structural disorder (inverted pairs relative to total pairs).

### Strategy Routing & Dispatch

* **Default:** Intelligent routing based on stack size and structure.


* **`--simple` / `--medium` / `--complex`:** Forces a specific architectural approach regardless of input size.


* **`--adaptive`:** Analyzes the computed disorder metric to dynamically pick the optimal path (low disorder $\rightarrow$ Simple; medium disorder $\rightarrow$ Medium; high disorder/randomized $\rightarrow$ Complex).



### 1. Simple Strategy (Selection Sort Adaptation — $O(n^2)$)

* **Justification:** Ideal for tiny inputs or benchmarking baselines. Repeatedly shifts the minimum element of stack A to the top, pushes it to B until 3 elements remain, solves the remaining triad with `sort_three`, and pushes elements back.



### 2. Medium Strategy (Chunk/Range-Based Sort — $O(n\sqrt{n})$)

* **Justification:** Splits elements into optimized index chunks pushed across to stack B. Reconstruction back to stack A uses directional shortest-path evaluation to minimize rotation overhead.



### 3. Complex Strategy (The "Turkish Algorithm" — Cost-Based $O(n \log n)$)

* **Justification:** The gold standard for large datasets ($n=500$). Roughly half of stack A is systematically evacuated to B while maintaining partial order. For remaining elements, `update_metadata` and cost engines compute the absolute cheapest combined rotation cost to position elements correctly in A (`move_cheapest`), achieving optimal operation counts.



## Resources

**Classic References:**

* Official 42 *Push_swap* Subject Guidelines.


* *Introduction to Algorithms* (Cormen, Leiserson, Rivest, Stein) — Complexity analysis.



**AI Usage Disclosure:**
In accordance with 42 policy, AI tools (Claude/Gemini) were utilized during this project strictly for:

* Reviewing edge-case handling logic for parsing malformed input strings and whitespace boundaries.


* Discussing structural designs for modularizing files to strictly respect Norminette limits (max 5 functions per file, max 25 lines per function).


* Drafting clear documentation and code formatting structures.
All core algorithmic logic, implementation choices, and bug-fixing were hand-crafted and verified.



## Contributions

* **dlandi:** Architecture design, adaptive sorting dispatcher, benchmark telemetry (`--bench`), disorder calculations, medium-chunk performance tuning, and integration testing.


* **lfurtado:** Core stack primitives, memory management modules, initial cost-engine scaffolding, and base sorting functions.