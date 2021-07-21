int	ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
	{
		if (!('A' <= *str && *str <= 'Z'))
			return (0);
		++str;
	}
	return (1);
}
