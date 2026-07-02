*This project has been created as part of the 42 curriculum by **lfurtado**.*

# ft_printf

A custom implementation of the C Standard Library's `printf` function, developed from scratch using only the functions allowed by the 42 project subject.

---

# Description

`ft_printf` recreates the behavior of the standard C `printf` function for the mandatory conversions while providing a deeper understanding of how formatted output works internally.

The primary objective of this project is to explore fundamental concepts of low-level programming, including:

* Variadic functions (`stdarg.h`)
* Parser implementation
* Recursive algorithms
* Integer and hexadecimal number conversion
* Pointer manipulation
* Modular software design

Rather than relying on the standard library implementation, this project builds the formatting mechanism from scratch, reproducing both the formatted output and the number of printed characters returned by the original `printf`.

## Supported Conversions

| Conversion | Description                      |
| ---------: | -------------------------------- |
|       `%c` | Character                        |
|       `%s` | String                           |
|       `%p` | Pointer address                  |
|       `%d` | Signed decimal integer           |
|       `%i` | Signed integer                   |
|       `%u` | Unsigned decimal integer         |
|       `%x` | Unsigned hexadecimal (lowercase) |
|       `%X` | Unsigned hexadecimal (uppercase) |
|       `%%` | Percent sign                     |

---

# Features

* Custom implementation of `printf`
* Variadic argument handling using `va_list`
* Recursive decimal conversion
* Recursive hexadecimal conversion
* Pointer formatting
* Accurate character counting
* Modular architecture
* No dynamic memory allocation required

---

# Project Architecture

The project follows a modular design where each function has a single responsibility.

| Function                | Responsibility                                                                            |
| ----------------------- | ----------------------------------------------------------------------------------------- |
| `ft_printf()`           | Parses the format string and coordinates the entire printing process                      |
| `ft_conversion_pf()`    | Retrieves the next variadic argument and dispatches it to the correct conversion function |
| `ft_putchar_pf()`       | Prints a single character                                                                 |
| `ft_putstr_pf()`        | Prints a string                                                                           |
| `ft_putnbr_pf()`        | Prints signed integers                                                                    |
| `ft_putnbr_unsint_pf()` | Prints unsigned integers                                                                  |
| `ft_puthex_pf()`        | Prints hexadecimal values (`%x` and `%X`)                                                 |
| `ft_putptr_pf()`        | Prints pointer values (`%p`)                                                              |
| `ft_puthex_ptr_pf()`    | Converts memory addresses to hexadecimal                                                  |

Separating the parser from the conversion functions makes the code easier to understand, maintain, and test while closely reflecting the internal workflow of the original `printf`.

---

# Algorithm and Data Structure

## Format String Parser

The parser scans the format string one character at a time.

* Ordinary characters are written directly to the standard output.
* When a `%` character is encountered, the following character is interpreted as a conversion specifier.
* The parser delegates the conversion to `ft_conversion_pf()`.
* `ft_conversion_pf()` retrieves the next argument using `va_arg()` and forwards it to the appropriate helper function.
* Every helper function returns the number of printed characters, allowing `ft_printf()` to return the exact total required by the original function.

This separation of responsibilities results in a simple and extensible parser.

---

## Recursive Number Conversion

Decimal and hexadecimal numbers are printed using recursion.

For decimal values:

1. Divide the number by 10.
2. Continue recursively until only one digit remains.
3. Print digits while the recursive calls return.

For hexadecimal values:

1. Divide the value by 16.
2. Use the remainder as an index into a hexadecimal lookup table.
3. Continue recursively until the most significant digit is reached.
4. Print each digit during the recursion unwind.

This strategy naturally preserves the correct digit order without requiring temporary buffers or reversing strings.

---

## Pointer Conversion

Pointers are received as `void *` values.

Before converting them to hexadecimal, they are cast to an integer type capable of storing memory addresses. The hexadecimal representation is then generated recursively, and the `"0x"` prefix is added before printing.

---

## Data Structures

No dynamic data structures are required for this project.

The implementation relies on:

* recursion for number conversion;
* constant lookup tables for hexadecimal digits;
* the `va_list` mechanism from the C Standard Library to access variadic arguments.

Because characters are written directly to the output, there is no need for intermediate buffers or heap allocation (`malloc` / `free`).

This design keeps the implementation lightweight while minimizing memory usage.

---

# Instructions

## Clone the repository

```bash
git clone <repository_url>
cd ft_printf
```

## Compile

```bash
make
```

This generates:

```text
libftprintf.a
```

## Clean object files

```bash
make clean
```

## Remove object files and the library

```bash
make fclean
```

## Rebuild

```bash
make re
```

---

## Usage Example

```c
#include "ft_printf.h"

int main(void)
{
    int number = 42;

    ft_printf("Character : %c\n", 'A');
    ft_printf("String    : %s\n", "Hello");
    ft_printf("Decimal   : %d\n", number);
    ft_printf("Unsigned  : %u\n", 42U);
    ft_printf("Hex       : %x\n", 255);
    ft_printf("Pointer   : %p\n", &number);
    return (0);
}
```

---

# What I Learned

This project strengthened my understanding of:

* designing a parser from scratch;
* implementing variadic functions with `stdarg.h`;
* recursive algorithms for number conversion;
* hexadecimal representation and pointer formatting;
* low-level memory representation;
* modular software design and separation of responsibilities;
* reproducing the behavior of a standard library function while working under strict implementation constraints.

---

# Resources

## References

* ISO C Standard Library (`stdarg.h`)
* Linux Manual Pages (`man 3 printf`)
* The C Programming Language — Brian W. Kernighan & Dennis M. Ritchie
* cppreference.com

## AI Usage

ChatGPT (OpenAI) was used as a learning and review tool throughout the development of this project.

AI assistance was limited to:

* explaining language concepts such as variadic functions, recursion, pointer manipulation, and hexadecimal conversion;
* discussing parser design and implementation strategies;
* reviewing algorithms and architectural decisions;
* improving project documentation.

All source code was designed, implemented, tested, and debugged by the project author.
