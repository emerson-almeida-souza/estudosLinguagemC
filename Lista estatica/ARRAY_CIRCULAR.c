#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct
{
    int inicio, fim, quantidade;
    int itens[MAX];
}FILA;

void inicializar(FILA *f1)
{
    f1->inicio = 0;
    f1->quantidade = 0;
    f1->fim = -1;
}

int insere(FILA *f1, int valor)
{
    int deuCerto = 0;
    if(f1->quantidade < MAX)
    {
        if (f1->fim == MAX-1)
        {
            f1->fim = 0;
        }
        else
        {
            f1->fim++;
        }
        deuCerto = 1;
        f1->itens[f1->fim] = valor;
        f1->quantidade++;
    }
    return(deuCerto);
}

main()
{
    FILA f1;
    inicializar(&f1);
    int valores[5] = 10, 20, 30, 40, 50;
    int i, deuCerto;
    for (i = 0; i < 5; i++)
    {
        deuCerto = insere(&f1, &valores);
        if(deuCerto)
        {
            printf("Item [%i] inserido com sucesso", valores[i]);
        }
        else
        {
            puts("OVERFLOW!!!!");
        }
        
    }
}
