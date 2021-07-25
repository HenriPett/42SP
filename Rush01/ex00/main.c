#include <unistd.h>

int	rush(int rules[3][4][4], int matriz[4][4]);

int	str_to_vetor_int(char *arg, int rules[3][4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (*arg < '1' || *arg > '4')
				return (0);
			rules[0][i][j] = *arg - '0';
			arg += 2;
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	rules[3][4][4];
	int	matriz[4][4];

	if (argc == 2 && str_to_vetor_int(argv[1], rules) && rush(rules, matriz))
		return (0);
	write(1, "Error\n", 6);
	return (1);
}
