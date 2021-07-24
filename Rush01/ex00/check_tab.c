#include <unistd.h>
#include "empilha.h"

int coluna_eh_valida(char tabela[TAMANHO][TAMANHO], t_parametros *parametros, int x)
{
    int i;
    int maior_tamanho;
    int visualizacoes;

    maior_tamanho = 0;
    visualizacoes = 0;
    i = -1;
    
    while (++i < TAMANHO)
    {
        visualizacoes += tabela[i][x] > maior_tamanho;
        maior_tamanho = ((tabela[i][x] > maior_tamanho) ? tabela[i][x] : maior_tamanho);
    }
    if (visualizacoes != parametros->acima[x])
        return (0);
    maior_tamanho = 0;
    visualizacoes = 0;
    while (--i >= 0)
    {
        visualizacoes += tabela[i][x] > maior_tamanho;
        maior_tamanho = ((tabela[i][x] > maior_tamanho) ? tabela[i][x] : maior_tamanho);
    }
    if(visualizacoes != parametros->abaixo[x])
        return (0);
    return (1);
}

int linha_eh_valida(char tabela[TAMANHO][TAMANHO], t_parametros *parametros, int y)
{
    int i;
    int maior_tamanho;
    int visualizacoes;

    maior_tamanho = 0;
    visualizacoes = 0;
    i = -1;
    while (++i < TAMANHO)
    {
        visualizacoes += tabela[y][i] > maior_tamanho;
        maior_tamanho = ((tabela[y][i] > maior_tamanho) ? tabela[y][i] : maior_tamanho);
    }
    if(visualizacoes != parametros->esquerda[y])
        return 0;
    maior_tamanho = 0;
    visualizacoes = 0;
    while (--i >= 0){
        visualizacoes += tabela[y][i] > maior_tamanho;
        maior_tamanho = ((tabela[y][i] > maior_tamanho) ? tabela[y][i] : maior_tamanho);
    }
    if(visualizacoes != parametros->direita[y])
        return 0;
    return 1;
}

int pode_colocar_valor (char tabela[TAMANHO][TAMANHO], int x, int y, int valor)
{
    int i;

    i = -1;
    while (++i < TAMANHO)
    {
        if(tabela[y][i] == valor || tabela[i][x] == valor)
        return 0;
    }
    return 1;
}

int procura_caso_vazio (char tabela[TAMANHO][TAMANHO], int *x, int *y)
{
    int i;
    int j;

    i = -1;
    while (++i < TAMANHO)
    {
        j = -1;
        while (++j < TAMANHO)
        {
            if(tabela[i][j] == 0)
            {
                *x = j;
                *y = i;
                return 1;
            }
        }
        
    }
    return 0;
}
