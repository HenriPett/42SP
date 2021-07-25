#ifndef EMPILHA_CAIXA_H

# define	EMPILHA_CAIXA_H
# define	TAM 4

typedef struct s_parametros
{
	char	acima[TAM];
	char	abaixo[TAM];
	char	esquerda[TAM];
	char	direita[TAM];
}	t_parametros;

int	argumento_eh_valido(char *av, t_parametros *parametros);
int	resolucao(char tabela[TAM][TAM], t_parametros *parametros);
int	procura_caso_vazio(char tabela[TAM][TAM], int *x, int *y);
int	pode_colocar_valor(char tabela[TAM][TAM], int x, int y, int valor);
int	linha_eh_valida(char tabela[TAM][TAM],
		t_parametros	*parametros, int	y);
int	coluna_eh_valida(char tabela[TAM][TAM],
		t_parametros	*parametros, int	x);
int	calcula_vizualizacoes(char tabela[TAM][TAM], int pos);
int	imprime_tabela(char tabela[TAM][TAM]);

#endif