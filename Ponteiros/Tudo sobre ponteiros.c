/*-------- TUDO SOBRE PONTEIROS----------*/
//Serve para guardar endereço, e apenas isso.
//Este endereço irá te levar para algum lugar
//Para trabalhar com ponteiros em C, é preciso 3 tarefas
//1º-> Declarar a variável do tipo ponteiro (* -> Operador)
//2º-> Inicializar (guardar coisa no ponteiro)(& -> Operador)
//3º-> Usar o ponteiro (*)

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#string <string.h>

main ()
{
	/*-------1º declarar o ponteiro--------*/
	//Aqui eu pergunto.. ele é ponteiro pra quem ? no caso é pra inteiro, ou seja vou andar de 4 em 4 bits
	int *ponteiro, *ponteiro1; //Ponteiro para inteiros, ele tem que saber para onde ele aponta
	int variavel = 777;
	///Ponteiro te leva a algum lugar, no caso ele tá apontando para algo que seja inteiro*/
	float *outroPonteiro;//Se eu seguir este ponteiro, eu vou chegar em um valor float

	/*-----2º Inicializar o ponteiro*/
	//5 metódos para inicializar o ponteiro
	ponteiro = 0xB8000000;///Endereço em hexaDecimal
	ponteiro = funcao();///Devolvendo um valor em uma função
	ponteiro = umOutroPonteiro;/// Posso atribuir um ponteiro para outro ponteiro. Desde que sejam do mesmo tipo
								///Int com int, float com float etc...
	ponteiro = NULL;///Null é o enderço 0,  é usado para inicializar um ponteiro. Pois ela inicia no 0
					///0x0 em hexaDecimal


	ponteiro = &variavel;

	///&Recupera o endereço da variável

	printf("\nEndereço da variavel:  %p", ponteiro);///vai exibir o ENDEREÇO deste ponteiro
	printf("\nEndereço da variavel:  %p", *ponteiro);///Aqui eu estarei exibindo o VALOR que está no endereço apontado
	printf("\nConteudo da variavel: %i", variavel);///Imprimir oque tem dentro de variavel
	printf("\nConteudo da variavel usando ponteiro: %i", *ponteiro);///Aqui estou recebendo o conteudo que está no endereço indicado
	/*Um ponteiro pode receber outro ponteiro e armazenar o mesmo endereço em várias variaveis*/
	
	#include <stdio.h>

main ()
{
    char caractere = 'a';
    char *ponteiro;

    ponteiro = &caractere;

    printf("\nCaractere: %c", caractere);
    printf("\nCaractere: %c", *ponteiro);//Vai no endereço e me mostre o conteudo
    printf("\nEndereço: %p", ponteiro);
    ponteiro++;/*Vai andar +1 no endereço da variável*/
    printf("\nCaracetere: %c", *ponteiro);
    printf("\nEndereco: %p", ponteiro);

    for(;;)/*Forzinho pra sempre*/
    {

        printf("%c", *ponteiro);
        ponteiro++;
    }

}
	
	/*----PASSOS PARA INICIAR UM PONTEIRO*/

#include <stdio.h>
main()
{
  ///1o declarar o ponteiro:
  int *ponteiro, *ponteiro1; ///ponteiro para inteiro
  int variavel = 777;

  ///2o: inicializar o ponteiro

  ponteiro = &variavel; ///recupera o
                        ///endereço da
                        ///variavel
  printf("\nEndereco da variavel: %p", ponteiro);

  printf("\nConteudo da variavel: %i", variavel);
  printf("\nConteudo da variavel: %i", *ponteiro);
  ponteiro1= ponteiro;
  printf("\nConteudo da variavel: %i", *ponteiro1);

}


	/*----TESTANDO UM PONTEIRO----*/
	int x = 10;
	int *ponteiro;
	ponteiro = &x;///O ponteiro está recebendo o endereço de memória de x;

	int y = 20;
	*ponteiro = y;///Aqui eu estou dizendo que o endereço de memória de x, vai receber o valor de y (que no caso é 20);

	/*----TESTANDO PONTEIRO*/
	int x = 10;
	double y = 10.20;
	char z = 'b';

    double *ponteiroY = &y;
	int ponteiroX = &x;///Ponteiro X recebe o endereço de X;
    printf("O endereco de x é %i----valor de x = %i", ponteiroX, *ponteiroX);///O primeiro vai exibir o endereço da variável, e o segundo o valor que tem neste endereço
    ///iSSO TAMBÉM VALE PARA OS OUTROS TIPOS DE VARIÁVEIS
    /*----EXEMPLO DE OPERAÇÃO DE SOMA COM PONTEIRO*/
    double soma = *ponteiroX + *ponteiroY;///Estou dizendo que quero somar o valor (conteudo de x + y)
    ///Acessei o valor dos meus ponteiros
    printf("%f", soma);


}


/*-----ARRAY COM PONTEIRO-----*/
#include<stdio.h>

main()
{
  char array[50] = {"valter ego"};
  char *ponteiro;

  ponteiro = array;

  int i;
  for(i = 0; *(ponteiro+i) != '\0'; i++)
  {
    printf("\nValor: %c", *(ponteiro+i));
  }
}

#include <stdio.h>

main()
{
  int array[5] = {100, 200, 300, 400, 500};

  int *ponteiro;

  ponteiro = array;

  printf("\nPonteiro: %p", ponteiro);
  printf("\nArray...: %p", array);

  printf("\nValor apontado:%i", *array);
  printf("\nValor apontado:%i", array[0]);
  printf("\nValor apontado + 1:%i", array[1]);
  printf("\nValor apontado + 1:%i", *(array+1));
  printf("\nValor apontado + 2:%i", *(array+2));

  int i;
  for(i = 0; i < 5; i++)
  {
    printf("\narray[%i] = %i", i, *(array+i));
  }
}

/*-----STRUCT COM PONTEIRO-----*/
#include <stdio.h>
///com o operador asteristico quer dizer que eu estou lidando com o valor que está no endereço, ele sozinho estou me referindo a endereço
main (void)
{
    struct horario{
    int *ponteiroHora;
    int *ponteiroMinuto;
    int *ponteiroSegundo;
    ///DECLAREI OS ATRIBUTOS DA MINHA ESTRUTURA COMO PONTEIROS, QUE IRÁ CONTÉR UM VALOR INTEIRO
    };

    struct horario hoje;
    ///Como eu declarei que esta estrutura contém atributos com ponteiros, tenho que definir 3 variáveis para recebe-las
    int hora = 200;
    int minuto = 300;
    int segundo = 400;

    hoje.ponteiroHora = &hora;///Meu ponteiro ponteiroHora está apontando no endereço de memória de hora (&hora);
    hoje.ponteiroMinuto = &minuto;
    hoje.ponteiroSegundo = &segundo;

    printf("Hora - %i   minuto - %i   segundo - %i\n", *hoje.ponteiroHora, *hoje.ponteiroMinuto, *hoje.ponteiroSegundo);///Exibindo os conteudos dos endereços apontados

    *hoje.ponteiroSegundo = 1000;///Quero que altere o valor que está dentro do endereço de memória hoje.ponteiroSegundo
    printf("hoje.ponteiroSegundo -> %i", *hoje.ponteiroSegundo);///Exibir o conteudo de hoje.ponteiroSegundo;
}

/*-----STRUCT COM PONTEIRO 2-----*/

#include <stdio.h>

main()
{
    struct horario{
    int hora;
    int minuto;
    int segundo;
    };

    struct horario agora, *depois;///Declarei uma estrutura de horario, chamada AGORA e um ponteiro chamado DEPOIS para receber o endereço de AGORA
    depois = &agora;///Todo o conteudo que está no endereço da estruturas DEPOIS, será passado para dentro da estrutura AGORA

    /*(*depois).hora = 20;///O valor que está dentro do endereço depois.hora recebe o valor de 20;
    ///Lembrar-se da precedencia de sinais, colocando os parenteses no ponteiro
    (*depois).minuto = 20;
    (*depois).segundo = 20;*/

    /*Uma manteira mais fácil de usar ponteiros em estruturas*/
    depois->hora = 20;///Estou dizendo que, no endereço depois.hora, será atribuido o valor de 20;
    depois->minuto = 80;
    depois->segundo = 50;

    int somatorio = 100;
    struct horario antes;
    antes.hora = somatorio + depois->segundo;///Estou dizendo que o ponteiro depois, que está apontada para uma estrutura do tipo horário
    ///Será somada com o conteúdo dentro de depois.segundo
    antes.minuto = agora.hora + depois->minuto;///Agora.hora vale 20;
    ///Depois->minuto vale 80;
    antes.segundo = depois->minuto + depois->segundo;///Antes.segundo está recebendo a soma de 80, que é oque está dentro de depois->minuto mais oque está dentro de depois->segundo
    ///É assim para qualquer operação matematica

    printf ("%i:%i:%i", antes.hora, antes.minuto, antes.segundo);///Exibindo o resultado
}



