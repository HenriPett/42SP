#include <unistd.h>
#include "empilha.h"

int imprime_tabela(char tabela[TAMANHO][TAMANHO])
{
    int y;
    int x;

    y = -1;
    while (++y < TAMANHO)
    {
        x = -1;
        while (++x < TAMANHO)
        {
            write(1, &tabela[y][x], 1);
            if (x != (TAMANHO - 1))
                write(1, " ", 1);
        }
        write(1, "\n", 1);
    }
    return 1;
}

int resolucao(char tabela[TAMANHO][TAMANHO], t_parametros *parametros)
{
    int x;
    int y;
    int valor;

    if(procura_caso_vazio(tabela, &x, &y))
    {
        valor = '0';
        while (++valor <= (TAMANHO + '0'))
        {
            if(pode_colocar_valor(tabela, x, y, valor))
            {
                tabela[y][x] = valor;
                if(x == (TAMANHO -1) && !linha_eh_valida(tabela, parametros, y))
                    continue;
                if(y == (TAMANHO - 1) && !coluna_eh_valida(tabela, parametros, x))
                    continue;
                if(resolucao(tabela, parametros) == 1)
                    return 1;
            }
        }
        tabela[y][x] = 0;
        return 0;
    }
    return 1;
}

int argumento_eh_valido(char *av, t_parametros *parametros)
{
    int i;
    char *ptr_parametros;

    i = -1;
    ptr_parametros = &parametros->acima[0];
    while (av[++i] != '\0')
    {
        if(i % 2 != 0 && av[i] == ' ')
            continue;
        if(i % 2 != 0 && av[i] != ' ')
            return 0;
        *ptr_parametros = av[i] - '0';
        ptr_parametros++;
    }
    if(TAMANHO == 4 && i != 31)
        return 0;
    if(TAMANHO == 6 && i != 47)
        return 0;
    return 1;
}

int main(int ac, char **av)
{
    t_parametros    parametros;
    char tabela[TAMANHO][TAMANHO];
    int i;
    int j;

    if (ac != 2 || !argumento_eh_valido(av[1], &parametros))
    {
        write(1, "Error\n", 6);
        return 0;
    }
    i = -1;
    while (++i < TAMANHO)
    {
        j = -1;
        while (++j < TAMANHO)
        {
            tabela[i][j] = 0;
        }
    }
    if (!resolucao(tabela, &parametros))
    {
        write(1, "Error\n", 6);
        return 0;
    }
    imprime_tabela(tabela);
    return 1;
}
