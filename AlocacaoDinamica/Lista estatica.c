#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3
#define PRIMEIRO_ITEM 0

struct alunos
{
    int matricula;
    char nome[30];
};

typedef struct nodes Lista;

struct nodes
{
    int posicao; ///Vai armazenar onde tem um nó livre para armazenar um aluno
    struct alunos dados_aluno[3];///Nesta lista, conterá no máximo 3 alunos
};

Lista* criaLista()///Função que retonar um endereço para uma lista
{
    Lista *li; ///Cria um ponteiro para lista
    li = (Lista*) malloc(sizeof(struct nodes)); ///Aloca memoria para essa lista criada
    if(li == NULL)///Verifico se a alocação foi feita com sucesso
        printf("Sem memória para alocar!!!");
    else
    {
        li->posicao = 0;///Como eu estou criando uma lista, ela não tem itens dentro dela
    }

    return li;///Retorno o endereço da lista
}

void apagaLista (Lista* l1)
{
    free(l1);
}

int tamanho_lista(Lista* l1)
{
    return l1->posicao;
}

int estah_vazia(Lista* l1)
{
    if(l1->posicao == 0)
        return 1;
    else
        return 0;
}

int estah_cheia(Lista* l1)
{
    if(l1->posicao >= MAX)
        return 1;
    else
        return 0;
}


int insere_comeco(Lista* l1, struct alunos a1)
{
    if(l1 == NULL)
        return 0;
    if(estah_vazia(l1))///Se retornar 1 da função é porque é verdadeiro que a lista esta vazia
        {
            l1->dados_aluno[PRIMEIRO_ITEM] = a1;///Confirmei que a lista esta vazia, então inseri no primeiro indice da lista de alunos
            l1->posicao++;
            return 1;
        }
        return 0;
}

int inserir_final(Lista* l1, struct alunos a1)
{
    if(l1==NULL)
        return 0;
    if(estah_cheia(l1))
        return 0;
    l1->dados_aluno[l1->posicao] = a1;//São structs do mesmo tipo, então eu posso atriuir uma a outra
    l1->posicao++;//Tem que andar a posição pra sabermos quando ela estahh cheia
    return 1;
}

int insere_inicio_lista(Lista* l1, struct alunos a1)//Função que vai inserir no primeiro indice [0] da lista de alunos
{
    if(l1==NULL)
    return 0;
    if(estah_cheia(l1))
    return 0;

    int i;
    //Função que abre espaço para inserir no inicio
    for (i = l1->posicao - 1; i >= 0 ; i--)//l1 recebe a posição[que é onde está livre] atual -1 da lista, em quanto ñ chegar no inicio da lista, vai decrementando
    {
        l1->dados_aluno[i+1] = l1->dados_aluno[i];//Empurrando o array, seu proxímo campo, para deixar o primeiro campo livre
        //o proximo campo, sempre vai receber o campo atual, até chegar no primeiro
    }
    l1->dados_aluno[PRIMEIRO_ITEM] = a1;//Inseri no inicio
    l1->posicao++;//Adicionei mais uma posição
    return 1;
}

int insere_em_ordem(Lista* l1, struct alunos a1)///Função que vai inserir um aluno no meio da lista ordenando na ordem crescente por matricula
{
    if(l1 == NULL) return 0;
    if(estah_cheia(l1)) return 0;
    int indice_while = 0;
    while (a1.matricula <= l1->dados_aluno[indice_while].matricula  && indice_while < l1->posicao)///Descubro onde eu vou encaixar ela, em ordem crescente
    indice_while++;

    int indice_for;
    for(indice_for = l1->posicao - 1; indice_for >= indice_while; indice_for--)//Indice for recebe a ultima posiçao onde contem dados, percorre ele até o indice que eu enconrei, que é onde será inserido
    {
        l1->dados_aluno[indice_for + 1] = l1->dados_aluno[indice_for];///Faço a proxima posição, que é onde está vazio receber o ultimo dado e vou caminando no array, até chegar na posição onde a matricula não é maior
    }
    l1->dados_aluno[indice_while] = a1;///Insere o dado na ordem correta
    l1->posicao++;
    return 1;
}

int remove_final(Lista* l1)
{
    if(l1 == NULL) return 0;
    if(estah_vazia(l1)) return 0;
    l1->posicao--;//Como a variavel já é algo que contém um valor (um lixo) então n tem importancia deixar o valor lá, eu so digo que a posição está vaga para dar lugar a outro item.
    return 1;
}

int remove_inicio(Lista* l1)
{
    if(l1 == NULL) return 0;
    if(estah_vazia(l1)) return 0;
    int i;
    for (i = 0; i < l1->posicao - 1; i++)
    {
        l1->dados_aluno[i] = l1->dados_aluno[i + 1]; //Caminha o array uma posição para frente, sobrescrevendo o primeiro item do array, fazendo a posição atual [i] receber o proximo item [i + 1]
    }
    l1->posicao--;
    return 1;
}

int remove_meio_lista(Lista* l1, int matricula, struct aluno *a1)
{
    if(l1 == NULL) return 0;
    if(estah_cheia(l1)) return 0;
    int campoencontrado = 0, i;
    while (l1->dados_aluno[campoencontrado].matricula != matricula && campoencontrado < l1->posicao)//Se a matricula for igual a de algum aluno da lista, eu retorno a posição dele
    campoencontrado++;
    if(campoencontrado == l1->posicao) return 0;//Percorreu todo array e não achou o item
    for (i = campoencontrado; i < l1->posicao - 1; i++)//Caso tenha achado, o i recebe o indice onde está o item, em quanto i, for menor que a quantidade de itens da lista (li->posicao - 1), percorra o array
    {
        l1->dados_aluno[i] = l1->dados_aluno[i + 1];///I recebeu onde esta o item a ser removido, e fez um caminhando a partir dele sobrescebendo e trazendo todo mundo a frente uma posição para tras
    }
    l1->posicao--;
    return 1;
}

//Recebe uma struct alunos por referencia para que possa ser exibida no resultado da busca  
int consulta_matricula(Lista* l1, int matricula, struct alunos *a1)//Recebe a lista que contem os alunos, a matricula do aluno que quero procurar, e um struct vaiza para armazenar os dados do aluno caso encontrado
{
    if(l1 == NULL) return 0;
    if(estah_vazia(l1)) return 0;
    int i = 0;
    while(i < l1->posicao && l1->dados_aluno[i].matricula != matricula)//Em quanto não percorrer toda a lista e em quanto a matricula for diferente de todas as matriculas da lista
    i++;///Em quanto as duas foram verdadeiras, vai somando + 1
    if(i == l1->posicao) return 0;///Se percorreu toda a lista e não encontrou a matricula, retorna falso
    *a1 = l1->dados_aluno[i];//Armazeno o aluno encontrado na struct passada, para que possa ser exibieda
    return 1;
}

///Para acessar o conteúdo do ponteiro eu uso asterisco
///Para acessar o ponteiro eu uso ele normalmente
main()
{
    //Criar lista
    Lista *l1;///1º Cria um ponteiro que aponta para a lista
    l1 = criaLista();///Atribuo um endereço para este ponteiro
    //Preenchimento de uma struct para enviar para lista
    struct alunos dados_aluno, dados_encontrar;
    puts("Nome");
    gets(dados_aluno.nome);
    fflush(stdin);
    puts("Matricula");
    scanf("%i", &dados_aluno.matricula);
    consulta_matricula(l1, 3001253, &dados_encontrar);


}
