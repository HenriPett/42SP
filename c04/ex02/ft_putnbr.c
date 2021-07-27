#include <unistd.h>

void	ft_putnbr(int nb)
{
	char			c;
	unsigned int	div;
	unsigned int	num;

	if (nb < 0)
		write(1, "-", 1);
	if (nb < 0)
		num = (-1) * nb;
	else
		num = nb;
	div = 1;
	while (nb / 10)
	{
		nb = nb / 10;
		div *= 10;
	}
	while (div)
	{
		c = '0' + num / div;
		write(1, &c, 1);
		num = num % div;
		div = div / 10;
	}
}
