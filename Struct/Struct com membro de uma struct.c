#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct endereco{

	char NomeDaRua[50];
	int numeroDaCasa;
};

struct pessoa{

	char nomeDaPessoa[50];
	int numeroDaPessoa;
	struct endereco enderecoDaPessoa;///Como é um tipo, eu posso colocar uma struct como um membro de uma outra struct
};

int main()
{

	struct pessoa primeiraPessoa;
	primeiraPessoa.enderecoDaPessoa.numeroDaCasa = 10;///'primeiraPessoa' no seu membro 'enderecoDaPessoa' em seu campo 'numeroDaCasa'
	printf("%i\n", primeiraPessoa.enderecoDaPessoa.numeroDaCasa);

	system("pause");
	return 0;
}
