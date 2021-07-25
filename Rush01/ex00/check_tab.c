#include <unistd.h>
#include "empilha_caixa.h"

int	coluna_eh_valida(char tabela[TAM][TAM],
	t_parametros *parametros, int x)
{
	int	i;
	int	maior_tamanho;
	int	visualizacoes;

	maior_tamanho = 0;
	visualizacoes = 0;
	i = -1;
	while (++i < TAM)
	{
		visualizacoes += tabela[i][x] > maior_tamanho;
		if (tabela[i][x] > maior_tamanho)
			maior_tamanho = tabela[i][x];
	}
	if (visualizacoes != parametros->acima[x])
		return (0);
	maior_tamanho = 0;
	visualizacoes = 0;
	while (--i >= 0)
	{
		visualizacoes += tabela[i][x] > maior_tamanho;
		if (tabela[i][x] > maior_tamanho)
			maior_tamanho = tabela[i][x];
	}
	if (visualizacoes != parametros->abaixo[x])
		return (0);
	return (1);
}

int	linha_eh_valida(char tabela[TAM][TAM],
	t_parametros *parametros, int y)
{
	int	i;
	int	maior_tamanho;
	int	visualizacoes;

	maior_tamanho = 0;
	visualizacoes = 0;
	i = -1;
	while (++i < TAM)
	{
		visualizacoes += tabela[y][i] > maior_tamanho;
		if (tabela[y][i] > maior_tamanho)
			maior_tamanho = tabela[y][i];
	}
	if (visualizacoes != parametros->esquerda[y])
		return (0);
	maior_tamanho = 0;
	visualizacoes = 0;
	while (--i >= 0)
	{
		visualizacoes += tabela[y][i] > maior_tamanho;
		if (tabela[y][i] > maior_tamanho)
			maior_tamanho = tabela[y][i];
	}
	if (visualizacoes != parametros -> direita[y])
		return (0);
	return (1);
}

int	pode_colocar_valor(char tabela[TAM][TAM], int x, int y, int valor)
{
	int	i;

	i = -1;
	while (++i < TAM)
	{
		if (tabela[y][i] == valor || tabela[i][x] == valor)
			return (0);
	}
	return (1);
}

int	procura_caso_vazio(char tabela[TAM][TAM], int	*x, int	*y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < TAM)
	{
		j = -1;
		while (++j < TAM)
		{
			if (tabela[i][j] == 0)
			{
				*x = j;
				*y = i;
				return (1);
			}
		}
	}
	return (0);
}
