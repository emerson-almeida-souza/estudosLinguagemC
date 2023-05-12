#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

///Utilizando ponteiros
void mostrarEnderecoDoPonteiro()
{
	///Declarar ponteiro
	int *ponteiro; ///Ponteiro para inteiro
	int vareavel = 10;
	ponteiro = NULL; ///Para não apontar para lixo

	ponteiro = &vareavel; ///Passeu o endereço de 'variavel' para o ponteiro
	printf("Variavel: x-> [%i]\n", vareavel);
	printf("\n");
	printf("Endereco: x-> [%i]\n", &vareavel);
	printf("\n");
	printf("Ponteiro contendo o endereco de vareavel: x-> [%i]\n", ponteiro);
	printf("\n");
	printf("Conteudo do ponteiro: [%i]\n", *ponteiro);
	printf("\n");
}

///Função que muda o conteudo do ponteiro
void manipularConteudoPeloPonteiro()
{
	int *ponteiro; ///Ponteiro para inteiro
	int vareavel = 10;
	ponteiro = NULL; ///Para não apontar para lixo

	ponteiro = &vareavel; ///Passeu o endereço de 'variavel' para o ponteiro


	printf("Variavel: x-> [%i]\n", vareavel);
	printf("Endereco: x-> [%i]\n", ponteiro); ///Imprimi endereço
	///Modificando valor do conteudo do endereço pelo ponteiro
	*ponteiro = 50;

	printf("Conteudo do ponteiro: x-> [%i]\n", *ponteiro);///Conteudo do endereco

}

///O ponteiro só aceita operações de somar e subtrair
///Posso comparar endereços
void somarOuSubtrairPonteiro()
{
	int *ponteiroParaInteiro = 1000;
	char *ponteiroParaChar = 2000;

	printf("\n\tPONTEIROS ANTES DE EU SOMAR MAIS UM\n");
	printf("->ponteiroParaInteiro = [%i]\->nponteiroParaChar [%i]\n", ponteiroParaInteiro, ponteiroParaChar);

	printf("\n");

	ponteiroParaInteiro++; ///Andei para o próximo endereço do ponteiro [int = 4 bits] amdeo mais 4 casinhas na memória
	ponteiroParaChar++;///char = 1 bit, andeo apenas uma casinha
	printf("\n\tPONTEIROS APOS EU SOMAR MAIS UM\n");
	printf("->ponteiroParaInteiro = [%i]\n->ponteiroParaChar [%i]\n", ponteiroParaInteiro, ponteiroParaChar);

	printf("\n");
	ponteiroParaChar = 2000;
	ponteiroParaInteiro = 1000;
	printf("\n\tPONTEIROS ANTES DE EU SUBTRAIR MAIS UM\n");
	printf("->ponteiroParaInteiro = [%i]\->nponteiroParaChar [%i]\n", ponteiroParaInteiro, ponteiroParaChar);
	ponteiroParaInteiro--; ///Andei para o próximo endereço do ponteiro [int = 4 bits] amdeo mais 4 casinhas na memória
	ponteiroParaChar--;///char = 1 bit, andeo apenas uma casinha
	printf("\n\tPONTEIROS APOS EU SUBTRAIR MAIS UM\n");
	printf("->ponteiroParaInteiro = [%i]\n->ponteiroParaChar [%i]\n", ponteiroParaInteiro, ponteiroParaChar);


}

///Ponteiro que aponta para qualquer tipo
void ponteiroParaQualquerTipo()
{
	void *ponteiroParaQualquerTipo;
	int *ponteiroParaInteiro = 10;

	ponteiroParaQualquerTipo = &ponteiroParaInteiro;///Recebendo o endereço do inteiro
	printf("Endereco do ponteiro que aponta para qualquer tipo, apontando para um numero inteiro no momento ->[%i]\n", ponteiroParaQualquerTipo);

	printf("\n");
	printf("\n");

	///é preciso converter o ponteiro que não tem tipo, para o tipo do conteudo que eu quero acessar
	printf("Conteudo do endereco generico apos receber o endereco do inteiro e convertido para inteiro -> [%i]\n", *(int*)ponteiroParaQualquerTipo);
}

void ponteiroEarrays()
{
	//Um vetor já é um ponteiro para a primeira posição do vetor [um array é a mesma coisa que um ponteiro]
	int vetor[5] = { 1, 2, 3, 4, 5 };
	int *ponteiroParaVetor = vetor;
	int contadorVetor;
	for (contadorVetor = 0; contadorVetor < 5; contadorVetor++)
	{
		///Recebe o endereço do ponteiro e vai indo sequencialmente somando um no endereço
		///printf("[%i]\n", ponteiroParaVetor[contadorVetor]); //-> Vetor normal
		printf("[%i]\n", *(ponteiroParaVetor + contadorVetor)); //vetor com ponteiro, alterando o conteudo e não o sue endereço
	}
	void arrayDePonteiro()
	{
		int *ponteiroParaVetor[5]; ///5 ponteiros criados

		int valor1 = 10, valor2 = 20;
		ponteiroParaVetor[0] = &valor1;
		ponteiroParaVetor[1] = &valor2;

		printf("[%i]", *ponteiroParaVetor[1]);
	}

}

main()
{
	arrayDePonteiro();
	/*ponteiroEarrays();
	ponteiroParaQualquerTipo();
	mostrarEnderecoDoPonteiro();
	manipularConteudoPeloPonteiro();
	int *ponteiro, *ponteiro1, variavel = 10;
	float froat = 20.0;

	ponteiro = &variavel;///Armazena o conteudo da 'variavel' NO PONTEIRO
	int valor = (*ponteiro);
	printf("[%i] TESTE \n", valor);
	printf("*p: %i \n", *ponteiro);///Imprimo o conteudo



	ponteiro1 = ponteiro;///Passei o endereço de um ponteiro para outro
	///Um ponteiro só pode apontar para  um conteudo com o seu tipo, int com int, float com float struct com struct

	printf("*p1: %i \n", *ponteiro1); //Imprimo o conteudo

	somarOuSubtrairPonteiro();*/


	system("pause");
	return 0;
}
