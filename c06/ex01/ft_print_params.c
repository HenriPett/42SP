#include <unistd.h>

int	main(int argc, char *argv[])
{
	unsigned int	n;
	int				i;
	char			*str;

	i = 0;
	while (++i < argc)
	{
		n = 0;
		str = argv[i];
		while (*str++ != '\0')
			++n;
		write(1, argv[i], n);
		write(1, "\n", 1);
	}
}
