#include <unistd.h>

void	ft_print_comb(void)
{
	char	num[3];
	char	separador[2];

	num[0] = '0';
	num[1] = '1';
	num[2] = '2';
	separador[0] = ',';
	separador[1] = ' ';
	write(1, num, 3);
	num[2] = '3';
	while (num[0] <= '7')
	{
		while (num[1] <= '8')
		{
			while (num[2] <= '9')
			{
				write(1, separador, 2);
				write(1, num, 3);
				++num[2];
			}
			num[2] = ++num[1] + 1;
		}
		num[1] = ++num[0] + 1;
		num[2] = num[1] + 1;
	}
}
