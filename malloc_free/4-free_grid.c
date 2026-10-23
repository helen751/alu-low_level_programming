#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a two dimensional grid
 * @grid: grid to free
 * @height: number of rows in the grid
 */
void free_grid(int **grid, int height)
{
	int row;

	if (grid == NULL)
		return;

	row = 0;
	while (row < height)
	{
		free(grid[row]);
		row++;
	}
	free(grid);
}
