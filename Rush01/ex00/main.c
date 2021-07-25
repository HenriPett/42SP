#include <unistd.h>
#include "empilha_caixa.h"

int	imprime_tabela(char tabela[TAM][TAM])
{
	int	y;
	int	x;

	y = -1;
	while (++y < TAM)
	{
		x = -1;
		while (++x < TAM)
		{
			write(1, &tabela[y][x], 1);
			if (x != (TAM - 1))
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
	return (1);
}

int	resolucao(char tabela[TAM][TAM], t_parametros *parametros)
{
	int	x;
	int	y;
	int	valor;

	if (procura_caso_vazio(tabela, &x, &y))
	{
		valor = '0';
		while (++valor <= (TAM + '0'))
		{
			if (pode_colocar_valor(tabela, x, y, valor))
			{
				tabela[y][x] = valor;
				if (x == (TAM - 1) && !linha_eh_valida (tabela, parametros, y))
					continue ;
				if (y == (TAM - 1) && !coluna_eh_valida(tabela, parametros, x))
					continue ;
				if (resolucao(tabela, parametros) == 1)
					return (1);
			}
		}
		tabela[y][x] = 0;
		return (0);
	}
	return (1);
}

int	argumento_eh_valido(char *av, t_parametros *parametros)
{
	int		i;
	char	*ptr_parametros;

	i = -1;
	ptr_parametros = &parametros->acima[0];
	while (av[++i] != '\0')
	{
		if (i % 2 != 0 && av[i] == ' ')
			continue ;
		if (i % 2 != 0 && av[i] != ' ')
			return (0);
		*ptr_parametros = av[i] - '0';
		ptr_parametros++;
	}
	if (TAM == 4 && i != 31)
		return (0);
	if (TAM == 6 && i != 47)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_parametros	parametros;
	char			tabela[TAM][TAM];
	int				i;
	int				j;

	if (ac != 2 || !argumento_eh_valido(av[1], &parametros))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = -1;
	while (++i < TAM)
	{
		j = -1;
		while (++j < TAM)
			tabela[i][j] = 0;
	}
	if (!resolucao(tabela, &parametros))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	imprime_tabela(tabela);
	return (1);
}
