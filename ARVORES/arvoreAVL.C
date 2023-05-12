#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct no
{
  int item;
  struct no *esq, *dir;
  int FB;
};

// prototipo das funcoes
void insereAVL(struct no **raiz, struct no *novo);
void emordem(struct no *raiz);
void imprimirDeLado(struct no *raiz, int espaco);
int devolveAltura (struct no *raiz);
void rotacaoSimplesDireita(struct no **pivot);
void rotacaoSimplesEsquerda(struct no **pivot);
void consertaFB(struct no *raiz);
int verificaSeEhDupla(struct no *raiz);

main()
{
  struct no *raiz, *novo;
  char opcao;
  int numero;
  raiz = NULL;
  system("cls");
  do
  {
    printf("\nOperacoes em Arvores AVL");
    printf("\n1 - Incluir novo item");
    printf("\n2 - Imprimir emordem");
    printf("\n3 - Imprimir bonitinho");
    printf("\nS - Sair do programa");
    printf("\nDigite sua opcao: ");
    fflush(stdin);
    scanf("%c", &opcao);
    switch(toupper(opcao))
    {
      case '1': // incluir novo item
      {
        printf("\nDigite um numero: ");
        scanf("%i", &numero);
        novo = (struct no *) malloc(sizeof(struct no));
        novo->item = numero;
        novo->FB = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        insereAVL(&raiz, novo);
        break;
      }
      case '2':
      {
        printf("\nImprimindo emordem\n ");
        emordem(raiz);
        break;
      }
      case '3':
      {
        printf("\nImprimindo bonitinho\n ");
        imprimirDeLado(raiz, 1);
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
    fflush(stdin);
  }
  while(toupper(opcao) != 'S');
} //  main

int verificaSeEhDupla(struct no *raiz)
{
  int oQueRetorna = 0;
  if (raiz->FB < 0)
  {
    if (raiz->esq->FB >= 0)
    {
      oQueRetorna = 1;
    }
  }
  if (raiz->FB > 0)
  {
    if (raiz->dir->FB <= 0)
    {
      oQueRetorna = 1;
    }
  }
  return(oQueRetorna);
}

void consertaFB(struct no *raiz)
{
  if (raiz != NULL)
  {
    consertaFB(raiz->esq);
    raiz->FB = (devolveAltura(raiz->dir)) - (devolveAltura(raiz->esq));
    consertaFB(raiz->dir);
  }
}

void rotacaoSimplesDireita(struct no **pivot)
{
  struct no *aux;
  aux = *pivot;
  *pivot = (*pivot)->esq;
  aux->esq = (*pivot)->dir;
  (*pivot)->dir = aux;
}

void rotacaoSimplesEsquerda(struct no **pivot)
{
  struct no *aux;
  aux = *pivot;
  *pivot = (*pivot)->dir;
  aux->dir = (*pivot)->esq;
  (*pivot)->esq = aux;
}

int devolveAltura (struct no *raiz)
{
  if (raiz == NULL)
  {
    return 0; // altura de arvore vazia
  }
  else
  {
    int he = devolveAltura(raiz->esq);
    int hd = devolveAltura(raiz->dir);
    if (he < hd)
    {
      return hd + 1;
    }
    else
    {
      return he + 1;
    }
  }
}

void insereAVL(struct no **raiz, struct no *novo)
{
  if  (*raiz == NULL)
  {
    *raiz = novo;
  }
  else
  {
    if(novo->item == (*raiz)->item)///Dados iguais
    {
      printf("\nNao sao permitidos dados repetidos");
    }
    else
    {
      if(novo->item < (*raiz)->item)
      {
        insereAVL(&(*raiz)->esq, novo);
      }
      else
      {
        insereAVL(&(*raiz)->dir, novo);
      }

      (*raiz)->FB = (devolveAltura((*raiz)->dir)) - (devolveAltura((*raiz)->esq));

      if ((*raiz)->FB == -2)
      {
        printf("\nDESBALANCEOU. FB = %i. No pivot igual a %i",(*raiz)->FB,(*raiz)->item);
        if (verificaSeEhDupla(*raiz))
        {
          printf("\nRotacao Dupla para a Direita");
          rotacaoSimplesEsquerda(&(*raiz)->esq);
          rotacaoSimplesDireita(&(*raiz));
        }
        else
        {
          printf("\nRotacao Simples para a Direita");
          rotacaoSimplesDireita(&(*raiz));
        }
        consertaFB(*raiz);
      }
      else
      {
        if ((*raiz)->FB == 2)
        {
          printf("\nDESBALANCEOU. FB = %i. No pivot igual a %i",(*raiz)->FB,(*raiz)->item);
          if (verificaSeEhDupla(*raiz))
          {
            printf("\nRotacao Dupla para a Esquerda");
            rotacaoSimplesDireita(&(*raiz)->dir);
            rotacaoSimplesEsquerda(&(*raiz));
          }
          else
          {
            printf("\nRotacao Simples para a Esquerda");
            rotacaoSimplesEsquerda(&(*raiz));
          }
          consertaFB(*raiz);
        }
      }
    }
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

void imprimirDeLado(struct no *raiz, int espaco)
{
  int i;
  if (raiz != NULL)
  {
    imprimirDeLado(raiz->dir, (espaco+1));
    for(i = 0; i < espaco; i++)
    {
      printf("     ");
    }
    printf("%3i(%i)\n", raiz->item, raiz->FB);
    imprimirDeLado(raiz->esq, (espaco+1));
  }
}
