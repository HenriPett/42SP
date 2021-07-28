int	ft_iterative_factorial(int nb)
{
	int	fatorial;

	if (nb < 0)
		return (0);
	fatorial = 1;
	while (nb > 0)
		fatorial *= nb--;
	return (fatorial);
}
