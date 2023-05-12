#include <stdio.h>

struct no
{
  int item;
  struct no *esq, *dir;
};

// prototipo das funcoes
void insere(struct no **raiz, struct no *novo);
void consultar(struct no *raiz, int numero);
void preordem(struct no *raiz);
void emordem(struct no *raiz);
void posordem(struct no *raiz);
void imprimirDeLado(struct no *raiz, int espaco);
void procurarUmParaExcluir(struct no **raiz, int numero, int *achou);
void excluir(struct no **raiz);
int devolveAltura (struct no *raiz);

main()
{
  struct no *raiz, *novo;
  char opcao;
  int numero, achou;
  raiz = NULL;
  clrscr();
  do
  {
    system("cls");
    printf("\nOperacoes em Arvores Binarias de Busca");
    printf("\n1 - Incluir novo item");
    printf("\n2 - Consultar novo item");
    printf("\n3 - Imprimir em preordem");
    printf("\n4 - Imprimir emordem");
    printf("\n5 - Imprimir em posordem");
    printf("\n6 - Imprimir bonitinho");
    printf("\n7 - Excluir um item");
    printf("\n8 - Destruir a arvore");
    printf("\n9 - Imprime a altura da arvore");
    printf("\nS - Sair do programa");
    printf("\nDigite sua opcao: ");
    flushall();
    scanf("%c", &opcao);
    switch(toupper(opcao))
    {
      case '1': // incluir novo item
      {
        printf("\nDigite um numero: ");
        scanf("%i", &numero);
        novo = (struct no *) malloc(sizeof(struct no));
        novo->item = numero;
        novo->esq = NULL;
        novo->dir = NULL;
        insere(&raiz, novo);
        break;
      }
      case '2': //  consultar um item
      {
        printf("\nDigite um numero: ");
        scanf("%i", &numero);
        consultar(raiz, numero);
        break;
      }
      case '3':
      {
        printf("\nImprimindo em preordem\n ");
        preordem(raiz);
        break;
      }
      case '4':
      {
        printf("\nImprimindo emordem\n ");
        emordem(raiz);
        break;
      }
      case '5':
      {
        printf("\nImprimindo em posordem\n ");
        posordem(raiz);
        break;
      }
      case '6':
      {
        printf("\nImprimindo bonitinho\n ");
        imprimirDeLado(raiz, 1);
        break;
      }
      case '7':
      {
        if (raiz == NULL)
        {
          printf("\nImpossivel remover numero de uma Arvore VAZIA");
        }
        else
        {
          printf("\nDigite um numero: ");
          scanf("%i", &numero);
          achou = 0;
          printf("\nValor de raiz antes.: %p\n", raiz);
          procurarUmParaExcluir(&raiz, numero, &achou);
          printf("\nValor de raiz depois: %p\n", raiz);
          if(achou)
          {
            printf("\nO numero %d foi removido da arvore", numero);
          }
          else
          {
            printf("\nO numero %d NAO existe na arvore", numero);
          }
        }
        break;
      }
      case '8':
      {
        printf("\nDestruindo a arvore inteira: ");
        if (raiz == NULL)
        {
          printf("\nImpossivel destruir. Arvore VAZIA");
        }
        else
        {
          while(raiz != NULL)
	        {
	          excluir(&raiz);
          }
        }
        break;
      }
      case '9':
      {
        printf("\nAltura da Arvore:  ");
        printf("%i", devolveAltura(raiz));
        break;
      }
      case 'S':
      {
        printf("\nPrograma encerrado\n\n");
        break;
      }
      default:
      {
        printf("\nOpcao invalida !");
      }
    }
    flushall();
  }
  while(toupper(opcao) != 'S');
} //  main

int devolveAltura (struct no *raiz)
{
   if (raiz == NULL)
      return 0; // altura de arvore vazia
   else
   {
      int he = devolveAltura(raiz->esq);
      int hd = devolveAltura(raiz->dir);
      if (he < hd)
        return hd + 1;
      else
        return he + 1;
   }
}

void insere(struct no **raiz, struct no *novo)
{
  if (*raiz == NULL)
  {
    *raiz = novo;
  }
  else
  {
    if(novo->item <= (*raiz)->item)
    {
      insere(&(*raiz)->esq, novo);
    }
    else
    {
      insere(&(*raiz)->dir, novo);
    }
  }
}

void consultar(struct no *raiz, int numero)
{
  if(raiz == NULL)
  {
    printf("\nO numero %d NAO existe na arvore", numero);
  }
  else
  {
    if(raiz->item == numero)
    {
      printf("\nO numero %d EXISTE na arvore", numero);
    }
    else
    {
      if(numero < raiz->item)
      {
        consultar(raiz->esq, numero);
      }
      else
      {
        consultar(raiz->dir, numero);
      }
    }
  }
}

void preordem(struct no *raiz)
{
  if (raiz != NULL)
  {
    printf("%d ", raiz->item);
    preordem(raiz->esq);
    preordem(raiz->dir);
  }
}

void emordem(struct no *raiz)
{
  if (raiz != NULL)
  {
    emordem(raiz->esq);
    printf("%d ", raiz->item);
    emordem(raiz->dir);
  }
}

void posordem(struct no *raiz)
{
  if (raiz != NULL)
  {
    posordem(raiz->esq);
    posordem(raiz->dir);
    printf("%d ", raiz->item);
  }
}


void imprimirDeLado(struct no *raiz, int espaco)
{
  int i;
  if (raiz != NULL)
  {
    imprimirDeLado(raiz->dir, (espaco+1));
    for(i = 0; i < espaco; i++)
    {
      printf("   ");
    }
    printf("%3d\n", raiz->item);
    imprimirDeLado(raiz->esq, (espaco+1));
  }
}

void procurarUmParaExcluir(struct no **raiz, int numero, int *achou)
{
  if((*raiz != NULL) && (*achou != 1))
  {
    if((*raiz)->item == numero)
    {
      *achou = 1;
      excluir (&(*raiz));
    }
    else
    {
      if (numero < (*raiz)->item)
      {
        procurarUmParaExcluir(&(*raiz)->esq,numero,&(*achou));
      }
      else
      {
        procurarUmParaExcluir(&(*raiz)->dir,numero,&(*achou));
      }
    }
  }
}

void excluir(struct no **raiz)
{
  struct no *aux;
  if((*raiz)->dir == NULL)
  {
    aux = *raiz;
    *raiz = (*raiz)->esq;
    free(aux);
  }
  else
  {
    if((*raiz)->esq == NULL)
    {
      aux = *raiz;
      *raiz = (*raiz)->dir;
      free(aux);
    }
    else // ambas as subarvores vazias
    {
      aux = (*raiz)->dir;
      while(aux->esq != NULL)
      {
        aux = aux->esq;
      }
      aux->esq = (*raiz)->esq;
      aux = *raiz;
      *raiz = (*raiz)->dir;
      free(aux);
    }
  }
}
