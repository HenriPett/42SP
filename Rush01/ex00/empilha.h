#ifndef EMPILHACAIXA_H

#define EMPILHACAIXA_H
#define TAMANHO 4

typedef struct s_parametros
{
    char acima[TAMANHO];
    char abaixo[TAMANHO];
    char esquerda[TAMANHO];
    char direita[TAMANHO];
}   t_parametros;

int argumento_eh_valido(char *av, t_parametros *parametros);
int resolucao(char tabela[TAMANHO][TAMANHO], t_parametros *parametros);
int procura_caso_vazio(char tabela[TAMANHO][TAMANHO], int *x, int *y);
int pode_colocar_valor(char tabela[TAMANHO][TAMANHO], int x, int y, int valor);
int linha_eh_valida(char tabela[TAMANHO][TAMANHO], t_parametros *parametros, int y);
int coluna_eh_valida(char tabela[TAMANHO][TAMANHO], t_parametros *parametros, int x);
int calcula_vizualizacoes(char tabela[TAMANHO][TAMANHO], int pos);
int imprime_tabela(char tabela[TAMANHO][TAMANHO]);

#endif