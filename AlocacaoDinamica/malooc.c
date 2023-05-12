/**malloc(), de Memory Allocation, é uma função da biblioteca stdlib.h que recebe como argumento números inteiros positivos (size_t), que irão representar o número de bytes que iremos alocar.
Essa função retorna um ponteiro contendo o endereço do bloco alocado.
Sua sintaxe é:

void *malloc(size_t numero_de_bytes);**/

/**Como a função malloc() serve para declarar qualquer tipo de dado,
seja int, float, double ou uma struct criada por você, sua sintaxe foi mostrada como void**/

#include <stdio.h>
#include <stdlib.h>

///PROGRAMA QUE TRAVA A MEMÓRIA DO COMPUTADOR
void aloca()
{
 int *ptr;
 ptr = (int *) malloc(100);///Recebo um pedaço de memória de 100bts
}

int main(void)
{
 while(1)///Criei vários blocos com 100 bits até acabar a memória
  aloca();

 return 0;
}

void senha()
{
 char *senha;

 senha = (char *) malloc(21*sizeof(char));
 printf("Digite sua senha [ate 20 caracteres]: ");
 scanf("%[^\n]s", senha);

 printf("Senha: %s\n", senha);
 printf("Endereço antes da free(): %d\n", &senha);

 free(senha);

 printf("Endereço depois da free(): %d\n", &senha); ///EU APENAS LIBEREI O ESPAÇO, MAIS AINDA TEM INFORMAÇÃO DENTRO
 senha = NULL; ///Assim eu garanto que essa memória agora n terá minha senha salva, evitando hackers e usos maliciosos

 return 0;
}

void boaPratica() ///SEMRPE USAR UM IF PARA PERGUNTAR SE DEU CERTO A ALOCAÇÃO
{
 int* ptr = (int *) malloc(1000000000000000000);

 if(ptr == NULL)
  printf("Sem espaço suficiente\n");

 return 0;
}

main()
{
    ///ALOCANDO MEMÓRIA PARA UMA STRING DE 20 CARACTERES
    ///char *nome;
    ///nome = (char *) malloc(21);
    char *nomeComSizeOf = (char *) malloc(21 * sizeof(char));
    printf("Digite seu nome: ");
    gets(nomeComSizeOf);

    printf("%sn", nomeComSizeOf);

    return 0;

    ///EVITAR USAR NUMEROS PARA O MALLOC, UTILIZAR O SIZE OF


    ///SEMPRE LIMPAR A MEMÓRIA DEPOIS DE USA-LA

    free(nomeComSizeOf);
}
