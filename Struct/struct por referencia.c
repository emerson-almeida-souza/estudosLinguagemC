#include <stdio.h>
#include <stdlib.h>

struct valores ///estrutura global
{
    int valor1;
    int valor2;
};

void structPorReferencia(struct valores *estruturaValoresPorReferencia) ///Recebi o endere�o de 'estruturaParaValor'
{
    ///Adicionei valores na 'estruturaParaValor'
    estruturaValoresPorReferencia->valor1 = 1;
    estruturaValoresPorReferencia->valor2 = 2;
}

main()
{
    struct valores estruturaParaValor;

    structPorReferencia(&estruturaParaValor);///Passei o endere�o de 'estruturaParaValor'

    ///imprimi a fun��o com os novos valores
    printf("primeiro valor ---> [%i]\n", estruturaParaValor.valor1);
    printf("Segundo valor ----> [%i]\n", estruturaParaValor.valor2);
}
