*This project has been created as part of the 42 curriculum by danda-si.*

# Get Next Line

## Overview

Get Next Line is a project from the 42 curriculum that consists of implementing a function capable of reading a file line by line.

The goal is to create a robust implementation that works with any valid file descriptor and any `BUFFER_SIZE` value while correctly handling memory allocation and file reading.

This project introduces important concepts such as:

- File descriptors
- Static variables
- Dynamic memory allocation
- String manipulation
- Buffer management
- EOF (End Of File) handling
- Memory leak prevention

---

# Prototype

```c
char	*get_next_line(int fd);
```

The function returns:

- The next line from the file.
- `NULL` when the end of the file is reached or an error occurs.

---

# Learning Objectives

Through this project I learned:

- How the `read()` system call works.
- How file descriptors are managed by the operating system.
- How to preserve data between function calls using static variables.
- How to dynamically allocate and free memory safely.
- How to build reusable utility functions.
- How to handle edge cases and EOF conditions.

---

# Project Structure

```text
.
├── get_next_line.c
├── get_next_line_utils.c
└── get_next_line.h
```

### get_next_line.c

Main project logic:

- Reads from the file descriptor
- Stores unread content
- Extracts the current line
- Updates the remaining content

### get_next_line_utils.c

Helper functions:

- ft_strlen
- ft_strdup
- ft_strchr
- ft_strjoin
- ft_substr

### get_next_line.h

Header file containing:

- Function prototypes
- Required includes
- BUFFER_SIZE definition

---

# How It Works

The project uses a static variable called `stash`.

```c
static char *stash;
```

The stash stores data that has already been read but not yet returned.

### Example

File:

```text
Hello
42
São Paulo
```

First call:

```c
get_next_line(fd);
```

Returns:

```text
Hello\n
```

Second call:

```c
get_next_line(fd);
```

Returns:

```text
42\n
```

Third call:

```c
get_next_line(fd);
```

Returns:

```text
São Paulo\n
```

Fourth call:

```c
get_next_line(fd);
```

Returns:

```c
NULL
```

---

# Internal Flow

```text
get_next_line()
│
├── Validate fd and BUFFER_SIZE
│
├── Read data from file
│
├── Store content in stash
│
├── Extract current line
│
├── Update stash
│
└── Return line
```

---

# Compilation

Compile with:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c \
get_next_line_utils.c
```

---

# Creating Test Files

### Simple file

```bash
echo -e "Hello\n42\nSão Paulo" > test.txt
```

Content:

```text
Hello
42
São Paulo
```

---

### Single line without newline

```bash
printf "Single line without newline" > test_no_newline.txt
```

---

### Empty file

```bash
touch empty.txt
```

---

### Multiple empty lines

```bash
printf "\n\n\n\n" > empty_lines.txt
```

---

### Very long line

```bash
python3 -c "print('A' * 10000)" > long_line.txt
```

---

# Test Main

Create a temporary main:

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);

	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}

	close(fd);
	return (0);
}
```

Compile:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
main.c \
get_next_line.c \
get_next_line_utils.c
```

Run:

```bash
./a.out
```

---

# Testing Different BUFFER_SIZE Values

One of the requirements of the project is that the function works correctly with different buffer sizes.

Compile using:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 *.c
```

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=10 *.c
```

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
```

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 *.c
```

---

# Memory Leak Check

Run Valgrind:

```bash
valgrind \
--leak-check=full \
--show-leak-kinds=all \
./a.out
```

Expected result:

```text
All heap blocks were freed -- no leaks are possible
```

---

# Common Edge Cases

The implementation should correctly handle:

- Empty files
- Files with only one line
- Files ending without `\n`
- Multiple consecutive `\n`
- Very large lines
- Very small BUFFER_SIZE values
- Very large BUFFER_SIZE values
- Invalid file descriptors
- Read errors

---

# Resources

### Official Documentation

- Linux Manual: read(2)
- Linux Manual: malloc(3)
- Linux Manual: free(3)
- POSIX Documentation

### Books

- The C Programming Language — Brian W. Kernighan & Dennis M. Ritchie

### 42 Resources

- Get Next Line Subject
- Peer Evaluations
- Moulinette Tests

---

# AI Usage

Artificial Intelligence tools were used exclusively as learning support for:

- Understanding project concepts
- Reviewing memory management techniques
- Clarifying the behavior of system calls
- Improving documentation

All implementation, debugging, testing, and validation of the final code were performed by the author.

---

# Author

Daniel da Silva Carvalho

42 São Paulo