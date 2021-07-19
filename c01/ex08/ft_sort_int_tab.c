void	ft_sort_int_tab(int *tab, int size)
{
	int	max_pos;
	int	cont;
	int	i;

	max_pos = size;
	while (max_pos > 0)
	{
		i = 0;
		while (++i < max_pos)
		{
			if (tab[i - 1] > tab[i])
			{
				cont = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = cont;
			}
		}
		--max_pos;
	}
}
