#include <stdio.h>

void	write_matriz(int matriz[4][4]);

int	sum_view_aux(int *cell, int step)
{
	int	i;
	int	qty;
	int	last_view;

	i = 0;
	qty = 0;
	last_view = 0;
	while (i < 4)
	{
		if (*cell > last_view)
		{
			last_view = *cell;
			qty++;
		}
		cell += step;
		i++;
	}
	return (qty);
}

int	sum_view(int matriz[4][4], int direction, int position)
{
	int	qty;

	qty = 0;
	if (direction == 0)
		qty = sum_view_aux(&matriz[0][position], 4);
	else if (direction == 1)
		qty = sum_view_aux(&matriz[3][position], -4);
	else if (direction == 2)
		qty = sum_view_aux(&matriz[position][0], 1);
	else if (direction == 3)
		qty = sum_view_aux(&matriz[position][3], -1);
	return (qty);
}

int	check_matriz(int rules[4][4], int matriz[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (rules[i][j] != sum_view(matriz, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
