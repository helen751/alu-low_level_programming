# malloc_free

This directory contains the mandatory dynamic-memory allocation tasks.

## Files

- `1-strdup.c` duplicates a string into newly allocated memory.
- `2-str_concat.c` concatenates two strings into newly allocated memory.
- `3-alloc_grid.c` allocates and zero-initializes a two-dimensional grid.
- `4-free_grid.c` frees a grid created by `alloc_grid`.
- `main.h` contains the required function prototypes.

All allocated memory is checked for failure and can be released with `free`.

## Compilation examples

```sh
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 \
    1-main.c 1-strdup.c -o strdup_test

gcc -Wall -pedantic -Werror -Wextra -std=gnu89 \
    2-main.c 2-str_concat.c -o concat_test

gcc -Wall -pedantic -Werror -Wextra -std=gnu89 \
    4-main.c 3-alloc_grid.c 4-free_grid.c -o grid_test
```
