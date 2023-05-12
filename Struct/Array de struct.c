#include <stdio.h>
#include <string.h>

main()
{
    struct arrey
    {
        int idade;
        char nome[50]
    };

    struct arrey arreyStruct[3];

    int i;
    for (i =0; i < 3;i++)
    {
        printf("\nDIgite a %i° idade: ", i + 1);
        scanf("%i", &arreyStruct[i].idade);

        fflush(stdin);

        printf("\nDigite o nome: \n");
        gets(arreyStruct[i].nome);
    }

      for (i = 0; i < 3; i++)
    {
        printf("Nome: %s \t", arreyStruct[i].nome);
        printf("idade: %i \n", arreyStruct[i].idade);

    }


}
