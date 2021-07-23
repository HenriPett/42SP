unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	size_attempt;
	int				should_null_terminate;

	size_attempt = 0;
	while (*dest != '\0' && size_attempt < size)
		++dest && ++size_attempt;
	should_null_terminate = size_attempt < size;
	while (*src != '\0' && size_attempt < size)
	{
		*dest++ = *src++;
		++size_attempt;
	}
	if (size_attempt == size)
		--dest;
	if (should_null_terminate)
		*dest = '\0';
	while (*src != '\0')
		++src && ++size_attempt;
	return (size_attempt);
}
