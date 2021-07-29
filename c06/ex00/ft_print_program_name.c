#include <unistd.h>

int	main(int argc, char *argv[])
{
	unsigned int	n;
	char			*str;

	if (argc > 0)
	{
		n = 0;
		str = argv[0];
		while (*str++ != '\0')
			++n;
		write(1, argv[0], n);
		write(1, "\n", 1);
	}
}
