# File I/O

This directory contains C programs and functions for basic POSIX file input and output.

## Files

- `0-read_textfile.c` reads a text file and prints it to standard output.
- `1-create_file.c` creates a file and writes text to it.
- `2-append_text_to_file.c` appends text to an existing file.
- `3-cp.c` copies one file into another using a 1024-byte buffer.
- `main.h` contains the required function prototypes.

## Compile

Compile a task with the checker-provided main file. For example:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-read_textfile.c -o read_file
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 1-main.c 1-create_file.c -o create_file
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 2-main.c 2-append_text_to_file.c -o append_file
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-cp.c -o cp
```

## Run the copy program

```bash
./cp file_from file_to
```
