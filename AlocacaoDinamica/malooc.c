/**malloc(), de Memory Allocation, � uma fun��o da biblioteca stdlib.h que recebe como argumento n�meros inteiros positivos (size_t), que ir�o representar o n�mero de bytes que iremos alocar.
Essa fun��o retorna um ponteiro contendo o endere�o do bloco alocado.
Sua sintaxe �:

void *malloc(size_t numero_de_bytes);**/

/**Como a fun��o malloc() serve para declarar qualquer tipo de dado,
seja int, float, double ou uma struct criada por voc�, sua sintaxe foi mostrada como void**/

#include <stdio.h>
#include <stdlib.h>

///PROGRAMA QUE TRAVA A MEM�RIA DO COMPUTADOR
void aloca()
{
 int *ptr;
 ptr = (int *) malloc(100);///Recebo um peda�o de mem�ria de 100bts
}

int main(void)
{
 while(1)///Criei v�rios blocos com 100 bits at� acabar a mem�ria
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
 printf("Endere�o antes da free(): %d\n", &senha);

 free(senha);

 printf("Endere�o depois da free(): %d\n", &senha); ///EU APENAS LIBEREI O ESPA�O, MAIS AINDA TEM INFORMA��O DENTRO
 senha = NULL; ///Assim eu garanto que essa mem�ria agora n ter� minha senha salva, evitando hackers e usos maliciosos

 return 0;
}

void boaPratica() ///SEMRPE USAR UM IF PARA PERGUNTAR SE DEU CERTO A ALOCA��O
{
 int* ptr = (int *) malloc(1000000000000000000);

 if(ptr == NULL)
  printf("Sem espa�o suficiente\n");

 return 0;
}

main()
{
    ///ALOCANDO MEM�RIA PARA UMA STRING DE 20 CARACTERES
    ///char *nome;
    ///nome = (char *) malloc(21);
    char *nomeComSizeOf = (char *) malloc(21 * sizeof(char));
    printf("Digite seu nome: ");
    gets(nomeComSizeOf);

    printf("%sn", nomeComSizeOf);

    return 0;

    ///EVITAR USAR NUMEROS PARA O MALLOC, UTILIZAR O SIZE OF


    ///SEMPRE LIMPAR A MEM�RIA DEPOIS DE USA-LA

    free(nomeComSizeOf);
}
