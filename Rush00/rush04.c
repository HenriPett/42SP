void	rush(int x, int y)
{
	int	xpos;
	int	ypos;

	ypos = 0;
	while (ypos < y)
	{
		xpos = 0;
		while (xpos < x)
		{
			if ((ypos == 0 && xpos == 0))
				ft_putchar('A');
			else if ((ypos == 0 && xpos == x - 1)
				|| (ypos == y - 1 && xpos == 0))
				ft_putchar('C');
			else if ((ypos == y - 1 && xpos == x - 1))
				ft_putchar('A');
			else if (ypos == 0 || ypos == y - 1 || xpos == 0 || xpos == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			xpos++;
		}
		ft_putchar('\n');
		ypos++;
	}
}
