#include <stdio.h>
#include <stdlib.h>

///Fuunção que recebe um pomteiro p/inteiros
int *aloca(int num)///Recebe quantos numeros eu vou alocar, ex 10
{
 int count,
  *numbers;///Ponteiro para cada numero

 numbers = (int *)malloc(num*sizeof(int));///Aloco espaço para 10 numeros

 ///Realizando armazenamento
 for(count=0 ; count < num ; count++)
 {
  printf("Numero [%d]: ", count+1);
  scanf("%d", &numbers[count]);
 }

 return numbers;///Retorno os endereços dos numeros///Só do primeiro
}

float media(int *numbers, int num)
{
 float media=0.0;
 int count;

 for(count=0 ; count< num ; count++)
  media += numbers[count];///A media recebe o total de numeros, (1, 2, 3.... 9, 10) a soma de tudo isso

 return media/num; ///Tiro a media da soma de todos os 10 numeros
}

void exibe(int *numbers, int num)
{
 int count;

 for(count=0 ; count < num ; count++)
  printf("%3d", numbers[count]);
}

int main(void)
{
 int num=1,
  *numeros;

 while(num) ///Em quanto n degitar 0, o programa roda
 {
  printf("Media de quantos numeros [0 para sair]: ");///Ex, será tirado a media de 10 numeros
  scanf("%d", &num);

  if(num > 0)
  {
   numeros = aloca(num);///Memória alocada para 10 numeros
   exibe(numeros, num);///Exibição destes numeros
   printf("\nA media destes numeros eh: %.2f\n", media(numeros, num) );
   free(numeros);
  }
 }

 return 0;
}
