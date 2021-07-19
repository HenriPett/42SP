void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div_a;
	int	div_b;

	div_a = *a;
	div_b = *b;
	*a = div_a / div_b;
	*b = div_a % div_b;
}
