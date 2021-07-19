void	ft_rev_int_tab(int *tab, int size)
{
	int	cont;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		cont = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = cont;
		++i;
	}
}
