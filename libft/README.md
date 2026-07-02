*This project has been created as part of the 42 curriculum by **lfurtado**.*

# Libft - My Very First Own Library

## 💡 Description
**Libft** is a project at school 42 that challenges students to re-code a selection of standard C library (libc) functions, as well as additional utility functions for string and memory manipulation, file descriptor outputs, and dynamic data structures (linked lists).

The goal of this project is to deeply understand how these fundamental data mechanisms operate under the hood, to master pointer arithmetic, memory management, and to strictly follow the standard architecture enforced by **The Norm**.

---

## 🛠️ Project Structure & Functions

### 1. Libc Functions (Part 1)
Re-implementation of core functions from the standard `<ctype.h>`, `<string.h>`, and `<stdlib.h>` headers:

* **Memory Operations:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`.
* **String Checking & Conversion:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`, `ft_atoi`.
* **String Manipulation:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`.

### 2. Additional Functions (Part 2)
Custom utility functions targeting complex string handling, dynamic allocation boundaries, and array parsing:

* `ft_substr`: Extracts a substring from a specified index up to a certain length.
* `ft_strjoin`: Concatenates two individual strings sequentially into a fresh memory allocation.
* `ft_strtrim`: Trims a specific set of boundary characters from both the start and end of a string.
* `ft_split`: Splits a string into an array of substrings using a designated delimiter character.
* `ft_itoa`: Converts an integer database value into a null-terminated string representation.
* `ft_strmapi`: Applies a custom function to each character of a string to yield a new string.
* `ft_striteri`: Iterates over a string, applying a function directly to its character memory addresses.

### 3. Linked Lists (Part 3)
An extension implementing a dynamic single linked list data structure utilizing the `t_list` layout:

| Function | Signature | Description |
| :--- | :--- | :--- |
| **ft_lstnew** | `t_list *ft_lstnew(void *content);` | Allocates and initializes a single isolated node structure. |
| **ft_lstadd_front** | `void ft_lstadd_front(t_list **lst, t_list *new);` | Shifting an active node to the front layer of the list stack. |
| **ft_lstsize** | `int ft_lstsize(t_list *lst);` | Evaluates total node length composition within the current list. |
| **ft_lstlast** | `t_list *ft_lstlast(t_list *lst);` | Parses internal chains to extract the final active node pointer. |
| **ft_lstadd_back** | `void ft_lstadd_back(t_list **lst, t_list *new);` | Appends a node directly onto the tail boundary of the list. |
| **ft_lstdelone** | `void ft_lstdelone(t_list *lst, void (*del)(void *));` | Wipes a node content via a function reference and frees the structure. |
| **ft_lstclear** | `void ft_lstclear(t_list **lst, void (*del)(void *));` | Deletes and clears an entire dynamic chain layout, resetting the head. |
| **ft_lstiter** | `void ft_lstiter(t_list *lst, void (*f)(void *));` | Iterates a customized procedure sequentially over all node values. |
| **ft_lstmap** | `t_list *ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *));` | Generates a fully transformed mapped list stack from an existing chain. |

---

## 📜 Compliance with The Norm (Version 4.1)

This implementation strictly complies with the **42 Norm Specification**. The code layout adheres to the following constraints:
* **Control Flow Restrictions:** Traditional loops like `for` or `do-while`, as well as ternary shorthand operators (`? :`), are entirely prohibited. All operations leverage standard structural `while` iterations.
* **Structural Scope Rules:** No file contains more than 5 distinct functional blocks.
* **Functional Limits:** Individual helper procedures are atomic and cannot exceed a strict 25-line limit.
* **Variable Scope Limits:** A maximum allocation threshold of 5 variables can be declared grouped exclusively at the top of any given function block.

---

## ⚙️ Compilation & Usage

The project includes a robust, automated compilation pipeline configured via a native system `Makefile` that supports clean incremental rebuild workflows without relinking artifacts unnecessarily.

### Makefile Rules:
* `make` / `make all` : Compiles the mandatory core library and generates the static archive file `libft.a`.
* `make clean` : Clears temporary intermediate object files (`.o`) generated during compilation.
* `make fclean` : Performs a deep systemic sweep, removing all object files and the static library binary file `libft.a`.
* `make re` : Forces a complete rebuild from scratch by chaining `fclean` and `all`.


### Include the header in the project:
* `#include "libft.h"`

### Compile the program with the library:

* `cc main.c libft.a`

* Example:

	`char *str;`

	`str = ft_strdup("Hello, 42!");`

	`printf("%s\n", str);`

	`free(str);`

---

## 🎓 Learnig Objectives

### Through this project I learned:

* Pointer arithmetic
* Memory management
* String manipulation
* Static libraries
* Defensive programming
* Understanding the behavior of standard C library functions
* Debugging low-level code
* Writing code according to the 42 Norm

### Resources / Documentation

* The C Programming Language — Brian W. Kernighan & Dennis M. Ritchie
* The Linux Manual Pages (man)
* cppreference C documentation
* GNU C Library Documentation
* Useful References
* Pointer arithmetic and memory layout
* ASCII character table
* Linked list data structures
* Static libraries in C

### AI Usage Disclosure

Artificial Intelligence tools were used as a learning aid during the development of this project. AI assistance was used for:

* Clarifying C language concepts
* Understanding pointer arithmetic
* Understanding memory-related functions
* Reviewing function behavior against the original libc specifications
* Practicing project defense and technical explanations

All implementations, debugging, testing, and final code decisions were completed and validated by the project author.

Luciano Furtado

Cadete at 42 School.