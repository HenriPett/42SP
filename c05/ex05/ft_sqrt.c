int	ft_sqrt(int nb)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1 + ((nb < 0) * -2);
	while (i * i < nb && ((i < 0) == (nb < 0)))
		i += sign;
	if (i * i == nb)
		return (i);
	return (0);
}
