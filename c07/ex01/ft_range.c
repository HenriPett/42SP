#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*arr;
	unsigned int	i;

	if (min < max)
	{
		arr = malloc((max - min) * sizeof(int));
		i = 0;
		if (arr)
			while (min < max)
				arr[i++] = min++;
		return (arr);
	}
	return (0);
}
