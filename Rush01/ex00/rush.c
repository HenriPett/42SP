#include <unistd.h>
#include <stdio.h>

int	check_matriz(int rules[4][4], int matriz[4][4]);

void	write_matriz(int matriz[4][4])
{
	int		row;
	int		column;
	char	c;

	row = 0;
	while (row < 4)
	{
		column = 0;
		while (column < 4)
		{
			c = '0' + matriz[row][column];
			write(1, &c, 1);
			write(1, " ", 1);
			column++;
		}
		row++;
		write(1, "\n", 1);
	}
}

int	fill_board(int rules[3][4][4], int matriz[4][4], int row, int column)
{
	int	value;

	if (row == 4)
		return (check_matriz(rules[0], matriz));
	if (column == 4)
		return (fill_board(rules, matriz, row + 1, 0));
	value = 1;
	while (value < 5)
	{
		if (!rules[1][row][value - 1] && !rules[2][column][value - 1])
		{
			rules[1][row][value - 1] = 1;
			rules[2][column][value - 1] = 1;
			matriz[row][column] = value;
			if (fill_board(rules, matriz, row, column + 1))
				return (1);
			rules[1][row][value - 1] = 0;
			rules[2][column][value - 1] = 0;
		}
		value++;
	}
	return (0);
}

void	start(int rules[3][4][4], int matriz[4][4])
{
	int	row;
	int	column;

	row = 0;
	while (row < 4)
	{
		column = 0;
		while (column < 4)
		{
			matriz[row][column] = 0;
			rules[1][row][column] = 0;
			rules[2][row][column] = 0;
			column++;
		}
		row++;
	}
}

int	rush(int rules[3][4][4], int matriz[4][4])
{
	start(rules, matriz);
	if (fill_board(rules, matriz, 0, 0))
	{
		write_matriz(matriz);
		return (1);
	}
	else
		return (0);
}
