# Recursion

This directory contains the seven mandatory C recursion tasks.

## Files

- `0-puts_recursion.c` - prints a string followed by a new line.
- `1-print_rev_recursion.c` - prints a string in reverse.
- `2-strlen_recursion.c` - returns the length of a string.
- `3-factorial.c` - returns the factorial of a number.
- `4-pow_recursion.c` - returns a number raised to a power.
- `5-sqrt_recursion.c` - returns the natural square root of a number.
- `6-is_prime_number.c` - checks whether a number is prime.
- `main.h` - contains all function prototypes.
- `_putchar.c` - provides the character-output helper used by tasks 0 and 1.

Each solution uses recursion and follows the required function prototype.

## Compilation

Compile a task with its test main file using GCC and the required flags. For
example:

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \
    _putchar.c 0-main.c 0-puts_recursion.c -o 0-puts_recursion
```

Tasks that do not call `_putchar` do not require `_putchar.c` during
compilation.
