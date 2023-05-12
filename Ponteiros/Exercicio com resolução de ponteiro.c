///EMERSON ALMEIDA SOUZA
/*. A função puts(char *string) exibe na tela uma string recebida por
parâmetro. Construa um programa em linguagem C que implemente e invoque
a função upts(char *string) que, a semelhança da função puts(char
*string), exibe na tela uma string recebida por parâmetro, com a diferença de
que primeiramente serão exibidas todas as vogais da string e, depois, todas as
consoantes. Os demais caracteres deverão ser ignorados. Exemplo: caso receba a
string “IFSP Campus Capivari”, deverá exibir na tela
“IauaiaiFSPCmpsCpvr”. A função deverá ser implementada exclusivamente

através de ponteiros. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


void organizaFrase(char *enderecoPonteiroFrase)///Recebi um endereço de ponteiro que aponta para um char
{
    int count;
    int countConsoantes = 0;
    int countVogais = 0;

    ///Variáveis aux para receber as consoantes e as vogais
    char receberConsoantes[50];
    char receberVogais[50];

    ///For para fazer todos os caracteres receber '\0', assim não imprimo lixo na tela
    for (count=0; count < 50; count++)
    {
        receberConsoantes[count] = '\0';
        receberVogais[count] = '\0';
    }

    ///Percorrendo o conteudo do endereço recebido como parametro
    ///Vai percorrer caractere por caractere
    ///Verifico se é igual a cada letra que faz parte do grupo de vogais 'a, e, i, o , u'
    for (count = 0; *(enderecoPonteiroFrase+count) != '\0'; count++)
    {

        if( *(enderecoPonteiroFrase+count) == 'a' )
        {
            ///Verifico se o caractere é espaço
            if(*(enderecoPonteiroFrase+count) == 32)
            {
                ///Se for, recebe um '\b': backspace
                *(enderecoPonteiroFrase+count) = '\b';
            }

            ///Faço minhas variáveis auxiliares receberem a letra com um contador próprio de caracteres
            ///Assim eu sei quantos caracteres eu terei que guardar na variável auxiliar
            receberVogais[countVogais] = 'a';
            countVogais++;///Se achar por exemplo, a primeira letra como 'a', ele adiciona ela no indice 0 do aux 'receberVogais'

        }

        else if ( *(enderecoPonteiroFrase+count) == 'e' )
        {


            if(*(enderecoPonteiroFrase+count) == 32)
            {
                *(enderecoPonteiroFrase+count) = '\b';
            }
            receberVogais[countVogais] = 'e';
            countVogais++;
        }

        else if ( *(enderecoPonteiroFrase+count) == 'i' )
        {


            if(*(enderecoPonteiroFrase+count) == 32)
            {
                *(enderecoPonteiroFrase+count) = '\b';
            }
            receberVogais[countVogais] = 'i';
            countVogais++;
        }

        else if ( *(enderecoPonteiroFrase+count) == 'o' )
        {


            if(*(enderecoPonteiroFrase+count) == 32)
            {
                *(enderecoPonteiroFrase+count) = '\b';
            }
            receberVogais[countVogais] = 'o';
            countVogais++;
        }

        else if ( *(enderecoPonteiroFrase+count) == 'u' )
        {

            if(*(enderecoPonteiroFrase+count) == 32)
            {
                *(enderecoPonteiroFrase+count) = '\b';
            }
            receberVogais[countVogais] = 'u';
            countVogais++;
        }
    }

    for (count = 0; *(enderecoPonteiroFrase+count) != '\0'; count++)
    {
        if(*(enderecoPonteiroFrase+count) != 'a' && *(enderecoPonteiroFrase+count) != 'e' && *(enderecoPonteiroFrase+count) != 'i' && *(enderecoPonteiroFrase+count) != 'o' && *(enderecoPonteiroFrase+count) != 'u')
        {

            if(*(enderecoPonteiroFrase+count) == 32)
            {
                *(enderecoPonteiroFrase+count) = '\b';
            }

            receberConsoantes[countConsoantes] = *(enderecoPonteiroFrase+count);
            countConsoantes++;
        }
    }


    ///Impressão dos valores, percorrendo todo conteudo caractere por caractere
    ///imprimir todas as vogais
    for(count = 0; count < strlen(receberVogais); count++)
    {
        printf("%c", receberVogais[count]);
    }

    ///Imprimir todas as consoantes
    for(count = 0; count < strlen(receberConsoantes); count++)
    {
        printf("%c", receberConsoantes[count]);
    }
}

main()
{
    ///Ponteiro para frase
    char *ponteiroFrase;
    char frase[50];
    int count = 0;

    printf("\nDigite a frase: ");
    gets(frase);

    ///Fazer todos os caracteres ficarem minusculos, percorrendo caractere por caractere
    for(count = 0; count < strlen(frase); count++)
    {
        frase[count] = tolower(frase[count]);
    }

    ///Recebendo o endereço de frase
    ponteiroFrase = &frase;

    ///Chamo meu método e mando o endereço de frase como parametro
    organizaFrase(ponteiroFrase);
}
