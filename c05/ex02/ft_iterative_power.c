int	ft_iterative_power(int nb, int power)
{
	int	n;

	if (power < 0)
		return (0);
	n = 1;
	while (power > 0)
	{
		n *= nb;
		--power;
	}
	return (n);
}
