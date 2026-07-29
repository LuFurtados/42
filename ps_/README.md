_This project has been created as part of the 42 curriculum by mariafer and lucsanto._

# Push_swap

## Description

`push_swap` is an algorithmic sorting project developed in C.

The program receives a sequence of unique integers and generates a valid sequence of
Push_swap instructions capable of sorting stack `a` in ascending order while using
stack `b` as auxiliary storage.

The project uses only the operations allowed by the subject:

- `sa`, `sb`, `ss`
- `pa`, `pb`
- `ra`, `rb`, `rr`
- `rra`, `rrb`, `rrr`

The input values are stored in singly linked stacks. Before sorting, each value receives
an index from `0` to `n - 1`, representing its final position in ascending order. This
normalization allows the algorithms to compare compact indexes instead of depending on
the original integer values.

Four execution modes are available:

- a simple quadratic strategy;
- a medium strategy based on approximately `sqrt(n)` logical buckets;
- a complex divide-and-conquer strategy;
- an adaptive mode that selects a strategy according to the measured disorder of the
  input.

The project also includes an optional benchmark mode that reports the initial disorder,
the selected strategy, the total number of generated operations, and the usage count of
each Push_swap instruction.

## Instructions

### Compile the project

```bash
make
```

Other available Makefile rules:

```bash
make clean
make fclean
make re
```

### Run the program

```bash
./push_swap 2 1 3 6 5 8
```

The generated instructions are written to standard output.

### Available flags

| Flag | Description |
|---|---|
| `--simple` | Forces the simple `O(n²)` strategy |
| `--medium` | Forces the medium `O(n√n)` strategy |
| `--complex` | Forces the complex `O(n log n)` strategy |
| `--adaptive` | Selects a strategy according to the measured disorder |
| `--bench` | Prints benchmark information to standard error |

Place the desired strategy flag before the numbers:

```bash
./push_swap --simple 2 1 3 6 5 8
```

Benchmark mode can be combined with a strategy:

```bash
./push_swap --bench --adaptive 2 1 3 6 5 8
```

## Team Contributions and Responsibilities

### Lucas (`lucsanto`)

- Implementing the Simple, Medium, and Complex sorting strategies.
- Developing the adaptive sorting flow used to select the appropriate algorithm.
- Implementing auxiliary sorting functions and small-stack cases.
- Analysing the complexity of each strategy based on the number of Push_swap
  operations.

### Mariana (`mariafer`)

- Implementing the parsing and validation of command-line arguments.
- Handling invalid inputs, duplicated values, integer overflows, and empty arguments.
- Building and indexing stack elements after parsing.
- Implementing the benchmark system.
- Calculating and displaying the disorder metric.
- Counting the total number of operations and the usage of each Push_swap instruction.
- Testing parsing errors and benchmark output.

### Shared responsibilities

- Defining the project architecture and data structures.
- Debugging and testing the complete program.
- Reviewing the code for compliance with the 42 Norm.

## Algorithms and Data Structure Explanation

### Data structure and index normalization

The stacks are implemented as singly linked lists. Each node stores the original integer,
its normalized index, and a pointer to the next node.

After parsing, the program assigns each value an index from `0` to `n - 1`. The smallest
value receives index `0`, the next value receives index `1`, and so on.

For example:

```text
Original values:  40  -3  12  90
Indexes:           2   0   1   3
```

The sorting algorithms operate mainly on these indexes. This avoids complications caused
by negative values, large integer gaps, or the full `int` range.

---

### Simple strategy — Selection Sort by Minimum Extraction

The simple strategy is a two-stack adaptation of **Selection Sort**.

At each iteration, the algorithm searches stack `a` for its minimum indexed element.
It then determines the element's position and chooses the shortest direction to bring it
to the top:

- `ra` when the element is closer to the top;
- `rra` when the element is closer to the bottom.

After reaching the top, the element is moved to stack `b` with `pb`. The process repeats
until the required elements have been extracted. Finally, `pa` moves the elements back
to stack `a` in ascending order.

Finding and positioning one minimum may require `O(n)` Push_swap operations. Repeating
the process for approximately `n` elements gives an upper bound of:

- **Push_swap operation complexity:** `O(n²)`
- **Additional C memory:** `O(1)`
- **Auxiliary stack usage:** `O(n)`

References:

- [NIST — Selection Sort](https://xlinux.nist.gov/dads/HTML/selectionSort.html)
- [OpenDSA — Selection Sort](https://opendsa-server.cs.vt.edu/ODSA/Books/Everything/html/SelectionSort.html)

---

### Medium strategy — Two-Phase Square-Root Bucket Distribution

The medium strategy is a custom two-stack adaptation of **Bucket Sort**.

The algorithm calculates a base close to:

```text
base = ceil(sqrt(n))
```

Each normalized index is classified twice:

```text
low bucket  = index % base
high bucket = index / base
```

The sorting process has two phases.

#### Phase 1: stack `a` to stack `b`

The program processes the remainder buckets. Elements belonging to the current bucket
are pushed to `b` with `pb`, while the other elements are rotated in `a` with `ra`.

#### Phase 2: stack `b` to stack `a`

The program processes the quotient buckets in descending order. Matching elements return
to `a` with `pa`, while the remaining elements are rotated in `b` with `rb`.

The remainder separates nearby indexes inside a group, while the quotient identifies the
larger range to which each index belongs. Processing both components reconstructs the
indexes in ascending order.

There are approximately `sqrt(n)` logical buckets, and each pass may examine up to `n`
elements:

- **Push_swap operation complexity:** `O(n√n)`
- **Additional C memory:** `O(1)`
- **Auxiliary stack usage:** `O(n)`

This implementation uses logical buckets instead of separate arrays because Push_swap
provides only two stacks.

References:

- [NIST — Bucket Sort](https://xlinux.nist.gov/dads/HTML/bucketsort.html)
- [OpenDSA — Binsort and Bucket Sort](https://opendsaserver.cs.vt.edu/ODSA/Books/Everything/html/BinSort.html)

---

### Complex strategy — Balanced Quicksort with Two-Stack Partitioning

The complex strategy is an adaptation of **Quicksort** using recursive partitioning
between stacks `a` and `b`.

For each group, the pivot is calculated from the middle of its normalized index range:

```text
lower_size = size / 2
pivot = minimum_index + lower_size
```

When partitioning stack `a`:

- indexes lower than the pivot are pushed to `b` with `pb`;
- indexes greater than or equal to the pivot remain in `a` and are rotated with `ra`.

After partitioning, the necessary rotations are restored. The algorithm recursively sorts
the upper partition in `a` and the lower partition in `b`.

The equivalent function for stack `b` performs the mirrored operation:

- indexes greater than or equal to its pivot return to `a` with `pa`;
- smaller indexes remain in `b` and are rotated with `rb`.

Small partitions are handled by dedicated small-stack functions, which form the recursion
base case.

Because the pivot is based on the middle of a known index range, the partitions are kept
approximately balanced:

- **Push_swap operation complexity:** `O(n log n)`
- **Recursive C call stack:** `O(log n)`
- **Auxiliary stack usage:** `O(n)`

References:

- [NIST — Quicksort](https://xlinux.nist.gov/dads/HTML/quicksort.html)
- [Princeton Algorithms — Quicksort](https://algs4.cs.princeton.edu/23quicksort/)

---

### Adaptive strategy — Disorder-Aware Hybrid Selection

The adaptive mode is a strategy selector rather than a separate sorting algorithm.

Before generating sorting operations, the program measures the initial disorder of stack
`a`. Every pair of elements is inspected. A pair counts as an inversion when a larger
value appears before a smaller value.

```text
disorder = number_of_inversions / total_number_of_pairs
```

The total number of pairs is:

```text
n * (n - 1) / 2
```

The result is normalized between `0` and `1`:

- `0` means that the input is already sorted;
- `1` means that the input is reverse sorted;
- intermediate values represent partially sorted inputs.

The adaptive strategy uses the thresholds required by the project:

```text
disorder < 0.2
    -> Simple strategy

0.2 <= disorder < 0.5
    -> Medium strategy

disorder >= 0.5
    -> Complex strategy
```

The disorder calculation performs `O(n²)` comparisons in C, but it generates no
Push_swap instructions. The operation complexity of the sorting phase is determined by
the selected strategy.

References:

- [ACM — A Survey of Adaptive Sorting Algorithms](https://dl.acm.org/doi/10.1145/146370.146381)
- [SciPy — Kendall's Tau](https://docs.scipy.org/doc/scipy/reference/generated/scipy.stats.kendalltau.html)

---

### Operation buffering and combined instructions

Operations modify the stacks immediately, but their textual output may be temporarily
buffered.

Before printing a pending operation, the program checks whether it can be combined with
the next one:

```text
sa  + sb  -> ss
ra  + rb  -> rr
rra + rrb -> rrr
```

This allows the program to emit one combined instruction instead of two independent
instructions without changing the resulting stack state.

## Resources

### Sorting algorithms

- [NIST — Selection Sort](https://xlinux.nist.gov/dads/HTML/selectionSort.html)
- [OpenDSA — Selection Sort](https://opendsa-server.cs.vt.edu/ODSA/Books/Everything/html/SelectionSort.html)
- [NIST — Bucket Sort](https://xlinux.nist.gov/dads/HTML/bucketsort.html)
- [OpenDSA — Binsort and Bucket Sort](https://opendsa-server.cs.vt.edu/ODSA/Books/Everything/html/BinSort.html)
- [NIST — Quicksort](https://xlinux.nist.gov/dads/HTML/quicksort.html)
- [Princeton Algorithms — Quicksort](https://algs4.cs.princeton.edu/23quicksort/)
- [ACM — A Survey of Adaptive Sorting Algorithms](https://dl.acm.org/doi/10.1145/146370.146381)
- [SciPy — Kendall's Tau](https://docs.scipy.org/doc/scipy/reference/generated/scipy.stats.kendalltau.html)

### Push_swap and small-stack techniques

- [K-distribution Sort Applied to Push_swap](https://medium.com/%40brakebein42/k-distribution-sort-applied-to-the-push-swap-problem-ae2d96d68376)
- [Push_swap: The Least Amount of Moves with Two Stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- Project subject
- Peer discussion and testing during the 42 learning process

## AI Usage

AI was used as a study and review assistant during the development of this project.

It helped with:

- understanding specific C concepts;
- reviewing edge cases;
- improving the README structure;
- creating additional test scenarios;
- reviewing technical explanations for the project defence.

All generated suggestions were reviewed, tested, and adapted by the team. Both members
remain responsible for understanding and explaining every part of the submitted project.

## Usage Examples

### Prepare the checker

Place `checker_linux` in the project root and make it executable:

```bash
chmod +x checker_linux
```

### Run the adaptive strategy and count operations

```bash
ARG="4 67 3 87 23"
./push_swap --adaptive $ARG | wc -l
```

The exact operation count depends on the implemented strategy and optimizations.

### Force the simple strategy

```bash
./push_swap --simple 5 4 3 2 1
```

### Force the medium strategy

```bash
./push_swap --medium 9 1 8 2 7 3 6 4 5 0
```

### Force the complex strategy and verify it with the checker

```bash
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG
```

Expected checker output:

```text
OK
```

### Test a large input

```bash
shuf -i 0-9999 -n 500 > args.txt
./push_swap $(cat args.txt) | wc -l
```

### Run the benchmark and send the operations to the checker

```bash
shuf -i 0-9999 -n 500 > args.txt
./push_swap --bench $(cat args.txt) 2> bench.txt \
    | ./checker_linux $(cat args.txt)
cat bench.txt
```

The Push_swap operations remain in standard output, while the benchmark is written to
standard error.

### Force adaptive mode while saving the benchmark

```bash
ARG="4 67 3 87 23"
./push_swap --bench --adaptive $ARG 2> bench.txt \
    | ./checker_linux $ARG
cat bench.txt
```

### Error-management examples

Invalid non-numeric value:

```bash
./push_swap --adaptive 0 one 2 3
```

Duplicated value:

```bash
./push_swap --simple 3 2 3
```

Both commands must print:

```text
Error
```

to standard error.

### Test the `int` limits

```bash
ARG="-2147483648 2147483647 0 -1 1 42 -42"
./push_swap $ARG | ./checker_linux $ARG
```

Expected checker output:

```text
OK
```
