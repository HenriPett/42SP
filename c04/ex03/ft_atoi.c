int	ft_atoi(char *str)
{
	int	sign;
	int	num;

	while ((9 <= *str && *str <= 15) || *str == ' ')
		++str;
	sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		++str;
	}
	num = 0;
	while ('9' >= *str && *str >= '0')
	{
		num *= 10;
		num += sign * (*str - '0');
		++str;
	}
	return (num);
}
