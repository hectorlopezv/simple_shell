#include "shell.h"
/**
 * _free - free up a 2d grid
 * @grid: double pointer 2d grid
 * @height: height of grid
 */

void _free(char **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
