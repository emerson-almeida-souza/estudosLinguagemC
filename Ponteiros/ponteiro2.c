#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
  float valores[20] = {10, 20, 30, 40, 50};
  int i;

  printf("\nEndereco de valores: %p", valores);

  printf("\nConteudo de valores: ");
  for(i = 0; i < 20; i++)
  {
    printf("%f", *(valores+i));
  }
  printf("\n");
  for(i = 0; i < 5; i++)
  {
    printf("\nednereco: %p\t valor inteiro: %f", (valores+i),*(valores+i));
  }
}
