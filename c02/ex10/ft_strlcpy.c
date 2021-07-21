unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	chars_copied;

	chars_copied = 0;
	while (*src != '\0' && chars_copied < size)
	{
		dest[chars_copied] = src[chars_copied];
		++chars_copied;
	}
	if (chars_copied == size)
	{
		--dest;
	}
	dest[chars_copied] = '\0';
	while (*src != '\0')
	{
		++chars_copied;
		++src;
	}
	return (chars_copied);
}
