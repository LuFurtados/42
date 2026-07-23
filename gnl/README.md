*This project has been created as part of the 42 curriculum by **lfurtado**.*

# get_next_line

> *A project developed as part of the 42 School curriculum. The objective is to implement a function capable of reading a file descriptor line by line while correctly managing dynamic memory and preserving unread data between calls.*

---

# Description

`get_next_line` is a C function that returns one line at a time from a file descriptor.

Unlike a simple call to `read()`, the function must remember any unread characters after a newline so that subsequent calls continue exactly where the previous one stopped. This is achieved using a static variable that stores the remaining data between function calls.

The implementation complies with the 42 project requirements and supports any valid `BUFFER_SIZE` defined at compile time.

---

# Features

* Reads one line per function call.
* Returns the newline character (`'\n'`) when present.
* Returns the last line even if it does not end with `'\n'`.
* Preserves unread characters using a static buffer.
* Supports any positive `BUFFER_SIZE`.
* Correctly handles empty files and invalid file descriptors.
* Memory-safe implementation (no leaks under normal usage).

---

# Function Prototype

```c
char *get_next_line(int fd);
```

---

# Instructions

The implementation follows four main steps:

1. Read data from the file descriptor until a newline or EOF is found.
2. Create the line to be returned.
3. Save the remaining characters for the next function call.
4. Return the allocated line.

Internally, helper functions are used to keep the code modular:

* `ft_read_line()`
* `ft_create_line()`
* `ft_update_leftover()`
* `ft_append_leftover()`

Utility functions (`ft_strlen`, `ft_substr`, `ft_strjoin`, etc.) are reimplemented as required by the project.

---

# Example Test

Example `main.c`:

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
	return (0);
}
```

Create a file named `text.txt`:

```
First line
Second line
Third line
```

Compile:

```bash
cc -Wall -Wextra -Werror \
-D BUFFER_SIZE=42 \
main.c get_next_line.c get_next_line_utils.c
```

Run:

```bash
./a.out
```

Output:

```
First line
Second line
Third line
```

---

# Testing

The implementation was validated using:

* Custom test programs.
* Multiple `BUFFER_SIZE` values.
* Empty files.
* Files with and without trailing newlines.
* Very large files.
* Invalid file descriptors.

It was also verified using the well-known Tripouille **gnlTester**, successfully passing the mandatory test suite.

---

# Concepts Practiced

* Static variables
* File descriptors
* System calls (`open`, `read`, `close`)
* Dynamic memory allocation
* Pointer arithmetic
* String manipulation
* Memory management
* Defensive programming

---

# Allowed Functions

* `read`
* `malloc`
* `free`

---

# What I Learned

This project deepened my understanding of low-level file I/O in C.

The most challenging aspects were managing the lifetime of dynamically allocated memory, preserving state between function calls with a static variable, and correctly handling every edge case involving newlines, end-of-file, and different buffer sizes.

Implementing `get_next_line` also reinforced the importance of modular design, resulting in a cleaner and easier-to-maintain solution.

---

# Resources

* 42 Subject — *get_next_line*
* Linux `read(2)` manual
* Linux `open(2)` manual
* Linux `close(2)` manual
* C Standard Library documentation

---

# AI Usage

Artificial Intelligence tool was used exclusively as a learning and mentoring tool during the development of this project. The assistance provided included:

* Understanding the role of the static variable and how it preserves unread data between function calls.
* Designing the overall architecture of the project before writing code.
* Defining the responsibilities of each helper function to keep the code modular and compliant with the 42 Norm.
* Discussing pointer arithmetic, memory ownership, and dynamic memory management.
* Analyzing the use of helper functions.
* Reviewing error handling, memory leaks, and cleanup strategies.
* Special attention was given to understanding *why* each function exists, how data flows through the program, and how each memory allocation is created, transferred, and released.

Every line of the final implementation was written, tested, debugged, and validated by the author. AI assistance served only as an educational resource and technical reviewer throughout the development process.

Luciano Furtado

Cadete at 42 School.