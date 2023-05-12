//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


main()
{
	typedef struct
	{
		int *ponteiroParaHORA;
		int *ponteiroParaMINUTO;
		int *ponteiroParaSEGUNDO;

	}TIPOHORARIO;

	TIPOHORARIO HOJE;

	int hora = 200;
	int minuto = 300;
	int segundo = 400;

	///RECEBENDO OS ENDEREÇOS
	HOJE.ponteiroParaHORA = &hora;
	HOJE.ponteiroParaMINUTO = &minuto;
	HOJE.ponteiroParaSEGUNDO = &segundo;

	///ACESSANDO E IMPRIMINDO OS CONTEUDOS DOS PONTEIROS
	printf("Hora->[%i]\n", *HOJE.ponteiroParaHORA);
	printf("Minuto->[%i]\n", *HOJE.ponteiroParaMINUTO);
	printf("Segundo->[%i]\n", *HOJE.ponteiroParaSEGUNDO);

	*HOJE.ponteiroParaSEGUNDO = 1000; ///ATRIBUI 1000 AO CONTEUDO CONTIDO NO ENDEREÇO DE PONTEIRO PARA SEGUNDO

	system("pause");
	return 0;
}
