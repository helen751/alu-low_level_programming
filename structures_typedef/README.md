# Structures and typedef

This directory contains the mandatory `struct dog` tasks.

## Files

- `dog.h` defines `struct dog`, the `dog_t` typedef, and function prototypes.
- `1-init_dog.c` initializes an existing dog structure.
- `2-print_dog.c` prints a dog's information and handles NULL values.
- `4-new_dog.c` dynamically creates a dog and copies its name and owner.
- `5-free_dog.c` frees the dog and its copied strings.

## Compilation

Compile each task with the checker-provided main file. For example:

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 1-main.c 1-init_dog.c -o task1
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 2-main.c 2-print_dog.c -o task2
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 4-main.c 4-new_dog.c -o task4
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 5-main.c 4-new_dog.c 5-free_dog.c -o task5
```
