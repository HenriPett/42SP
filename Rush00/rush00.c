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
			if ((ypos == 0 || ypos == y - 1) && (xpos == 0 || xpos == x - 1))
				ft_putchar('o');
			else if (ypos == 0 || ypos == y - 1)
				ft_putchar('-');
			else if (xpos == 0 || xpos == x - 1)
				ft_putchar('|');
			else
				ft_putchar(' ');
			xpos++;
		}
		ft_putchar('\n');
		ypos++;
	}
}
