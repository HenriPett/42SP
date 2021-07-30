#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char			*tpr;
	unsigned int	n;

	n = 0;
	while (src[n] != '\0')
		++n;
	tpr = malloc(n + 1);
	if (tpr != '\0')
	{
		tpr[n] = '\0';
		while (n--)
			tpr[n] = src[n];
	}
	return (tpr);
}
