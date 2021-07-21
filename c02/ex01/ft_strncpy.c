char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = -1;
	while (*src != '\0' && ++i < n)
		dest[i] = *src++;
	while (++i < n)
		dest[i] = '\0';
	return (dest);
}
