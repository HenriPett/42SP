#include <unistd.h>

int	main(int argc, char *argv[])
{
	unsigned int	n;
	char			*str;

	while (--argc > 0)
	{
		n = 0;
		str = argv[argc];
		while (*str++ != '\0')
			++n;
		write(1, argv[argc], n);
		write(1, "\n", 1);
	}
}
