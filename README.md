# libasm

*Version: 5.4*

## Grade - 100/100

Mandaroty Part : 100/100  

## Description

Libasm is a low-level programming project from the 42 Common Core.
Its objective is to introduce students to x86-64 assembly language by reimplementing standard C library functions using NASM and respecting the System V AMD64 calling convention.

The project focuses on understanding how high-level C functions interact with the system at a lower level, including register usage, syscalls, memory management, and error handling.

## Overview

The project consists of writing a static library, libasm.a, containing several commonly used C functions rewritten entirely in 64-bit assembly.

The mandatory part includes:
- String manipulation functions
- System call wrappers
- Proper error and errno handling
- A C test program to validate correctness

The goal is not performance optimization, but correctness, robustness, and strict compliance with the calling convention and subject constraints.

## Implemented Functions (Mandatory)

The following functions were reimplemented in assembly:

- ft_strlen    : returns the length of a string
- ft_strcpy    : copies a string from source to destination
- ft_strcmp    : compares two strings
- ft_write     : writes data to a file descriptor
- ft_read      : reads data from a file descriptor
- ft_strdup    : duplicates a string using dynamic memory allocation

All functions strictly replicate the behavior of their libc counterparts.

## Technical Constraints

- 64-bit assembly only
- NASM assembler
- Intel syntax (AT&T syntax is forbidden)
- No inline assembly
- Respect of the System V AMD64 ABI
- No usage of the -no-pie compilation flag
- Proper syscall error handling
- Correct propagation of errno using ___error / errno_location
- Static library named libasm.a
- A functional Makefile with the rules:
  - all
  - $(NAME)
  - clean
  - fclean
  - re

## Error Handling

System calls (read, write) are checked for failure conditions.

In case of error:
- The return value strictly matches libc behavior
- The global variable errno is set appropriately
- Errors are propagated back to the caller without crashing

This ensures full compatibility with standard C programs.

## Build & Usage

To compile the library `libasm.a`:
```javascript
make
```

A test libasm.c with main function is provided to compare the behavior of the assembly functions with their libc equivalents.

To test the functions and compil with `libasm.c`:
```javascript
make tester && ./tester < srcs/testing/ft_read_testing.txt
```

You can try `<` with any file or modify the content of `ft_read_testing.txt` or just skip the test by running `./tester` without any file.

## Testing

The project was tested using:
- Custom test programs
- Comparisons with libc implementations
- Edge cases (empty strings, large buffers)
- Invalid file descriptors
- Standard input (stdin) handling

All tests confirmed identical behavior between the assembly functions and their C equivalents.

## Notes

- Bonus functions were not implemented
- The project strictly follows the mandatory requirements
- Code clarity and register discipline were prioritized to ease defense explanations

## Credits

Project made by [ffouquet42](https://github.com/ffouquet42)