int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if (!(('z' >= *str && *str >= 'a') || ('Z' >= *str && *str >= 'A')))
			return (0);
		++str;
	}
	return (1);
}
