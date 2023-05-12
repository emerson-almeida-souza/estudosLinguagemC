//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void mostrarEnderecoDoPonteiro()
{
	///Declarar ponteiro
	int *ponteiro; ///Ponteiro para inteiro
	int vareavel = 10;
	ponteiro = NULL; ///Para não apontar para lixo

	ponteiro = &vareavel; ///Passeu o endereço de 'variavel' para o ponteiro
	printf("Variavel: x-> [%i]\n", vareavel);
	printf("Endereco: x-> [%i]\n", &vareavel);
	printf("Ponteiro contendo o endereco de vareavel: x-> [%i]\n", ponteiro);
}

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

main()
{
	mostrarEnderecoDoPonteiro();
	manipularConteudoPeloPonteiro();
	int *ponteiro, *ponteiro1, variavel = 10;
	float froat = 20.0;

	ponteiro = &variavel;///Armazena o conteudo da 'variavel' NO PONTEIRO
	int valor = (*ponteiro);
	printf("[%i] TESTE \n", valor);
	printf("*p: %i \n", *ponteiro);///Imprimo o conteudo



	ponteiro1 = ponteiro;///Passei o endereço de um ponteiro para outro
	printf("*p1: %i \n", *ponteiro1); //Imprimo o conteudo


	system("pause");
	return 0;
}
