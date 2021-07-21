int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (32 > *str || *str > 126)
			return (0);
		++str;
	}
	return (1);
}
