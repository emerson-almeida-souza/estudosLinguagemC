#include <stdio.h>
#include <stdlib.h>
#define MAXALOC 5

main()
{
    int *p;
    ///Alocar espaço para um array de 5 posições inteiras
    ///Depois de alocado eu já posso tratar como um array normalmente, armazenando com i, etc
    ///Esquece que c é um ponteiro
    p = (int* ) malloc(MAXALOC*sizeof(int));

    if(p == NULL)
    {
        printf("A alocação falhou, sem memória!!!\n");
        exit(1);
    }

    int i;
    for (i = 0; i < MAXALOC; i++)
    {
        ///Dar um print no CONTEÚDO do ponteiro.
        printf("Digite 5 valores\n");
        scanf("%d", &p[i]);
        system("cls");
        /*printf("%d\n", p[i]);*/
    }

    for (i = 0; i < MAXALOC; i++)
    {
        printf("%d\n", p[i]);
    }
    free(p);///Após utilizado a memória, eu posso liberar ela para que outro programa utilize

}
