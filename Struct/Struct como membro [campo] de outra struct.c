#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///� poss�vel criar tipos com vetores
typedef char nome[50];
nome novoNome; ///Nome cabe at� no m�ximo 50 caracteres e � um tipo char

struct endereco{

	char NomeDaRua[50];
	int numeroDaCasa;
};

typedef struct endereco TIPOENDERECO;

struct pessoa{

	char nomeDaPessoa[50];
	int numeroDaPessoa;
	TIPOENDERECO enderecoDaPessoa;///Como � um tipo, eu posso colocar uma struct como um membro de uma outra struct
};

int main()
{

	struct pessoa primeiraPessoa;
	primeiraPessoa.enderecoDaPessoa.numeroDaCasa = 10;///'primeiraPessoa' no seu membro 'enderecoDaPessoa' em seu campo 'numeroDaCasa '
	printf("%i\n", primeiraPessoa.enderecoDaPessoa.numeroDaCasa);

	system("pause");
	return 0;
}
