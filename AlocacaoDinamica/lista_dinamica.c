#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct//Criei o dado
{
    int cpf;
} CLIENTE;

typedef struct node//Criei os campos onde serão armaenados os nós
{
    CLIENTE cliente;//Datas
    struct node *next;//Ponteiro que aponta para quem é o próximo no (se for 1 e o ponteiro para 2...)
} LISTA;
//LISTA ou struct node é a mesma coisa
LISTA *criar_lista()//Faz o head, valer nulo
{
    return (NULL);//Mandei que meu ponteiro inicio(head) aponta para nulo
}

void insere_inicio(LISTA **head, CLIENTE novo_cliente)//Ponteiro de inicio por referencia, assim eu posso alterar o endereço ponteiro
{
    LISTA *novo;//Aloca memoria para o novo dado a ser inserido
    novo = (LISTA*) malloc(sizeof(LISTA));
    //É preciso verificar se o novo foi alocado corretamente
    novo->cliente = novo_cliente;//Armazenei os dados do cliente
    novo->next = NULL;//Se ele for o primeiro item da lista a ser inserido, o proximo dele ta vazio
    if(*head != NULL)//Se o inicio está apontando para alguem
    {
        novo->next = *head; //Se o head, estiver apontando para alguma coisa, o novo primeiro item aponta pra ele
    }
    *head = novo;//Novo agora é o head da lista
    printf("Endereco da cabeca da lista [%p]\tDado do comeco [%i]\n",*head, novo->cliente.cpf);
    printf("Endereco de novo[%p]\n", novo);
}


void insere_final(LISTA** inicio, CLIENTE c1)
{
    LISTA *novo = (LISTA*) malloc(sizeof(LISTA));
    LISTA *aux;//Para fazer o caminhamento na lista, pois eu n posso andar com a cabeça da lista
    novo->cliente = c1;//Recebo os dados
    novo->next = NULL;
    if(*inicio == NULL)//Se a lista estiver vazia
    {
        insere_inicio(&*inicio, c1);//Se a lista tiver vázia eu chamo uma inserção no inicio da lista
    }
    else
    {
        aux = *inicio;
        while (aux->next != NULL)//Quando aux->next for nulo, é porque chegou no final da lista
        {
            aux = aux->next;//Em quanto não chega no final, vai caminhando na lista
        }
        aux->next = novo;//Insere no final
        printf("Dado do fim %i\n",novo->cliente.cpf);
        printf("Endereco do ultimo item da lista [%p]\tDado do ultimo item da lista [%i]\n",*inicio, novo->cliente.cpf);
        printf("Endereco de novo[%p]\n", novo);
    }

}
void imprimi_lista(LISTA **inicio)
{
    LISTA* aux;
    aux = *inicio;
    if(aux == NULL)
        printf("A lista esta vazia!!!\n");
    else
    {
        while (aux != NULL)//Quando ele for nulo é porque chegou no final da lista
        {
            printf("cpfs dos clientes: %i \n", aux->cliente.cpf);//Imprime todos os dados do cliente
            aux = aux->next;//Caminha para o proximo cliente
        }
    }
}

int conta_lista(LISTA **inicio)
{
    int i = 0;
    LISTA *aux;
    aux = *inicio;
    while (aux != NULL)
    {
        i++;
        aux = aux->next;
    }
    return i;
}

void insere_em_ordem(LISTA** inicio, CLIENTE c1)
{
    LISTA *novo = (LISTA*) malloc (sizeof(LISTA));
    LISTA *anterior, *atual;//Anterior recebe sempre a posição atras do atual, que está caminhando na lista
    if(*inicio == NULL)//Se a lista estiver vázia
    {
        insere_inicio(&*inicio, c1);
    }
    else
    {
        novo->cliente = c1;
        novo->next = NULL;
        atual = *inicio;//Atual recebe inicio para caminhar na lista
        while (atual != NULL && c1.cpf > atual->cliente.cpf)
        {
            anterior = atual;//Anterior fica no 1...
            atual = atual->next;//Atual caminha para item 2...
        }
        if(atual == *inicio)//Caso o while n tenha rodado, quer dizer que é o menor valor possivel, ouu seja é inserido na primeira posição
        {
            insere_inicio(&*inicio, c1);
        }
        else
        {
            anterior->next = novo;
            novo->next = atual;
        }
    }
}

void menu()
{
    printf("Opcao 1: Insere no inicio.\n");
    printf("Opcao 2: Insere no final.\n");
    printf("Opcao 3: Insere em ordem.\n");
    printf("Opcao 4: Imprimir lista\n");
    printf("Opcao 5: Total de itens na lista\n");
    printf("Opcao 6: remove do inicio.\n");
    printf("Opcao 7: remove do final.\n");
    printf("Opcao 8: remove qualquer posicao.\n");
    printf("Opcao 9: Consulta posicao.\n");
    printf("Opcao 10: Consulta CPF.\n");
    printf("Opcao 0: Sai do programa.\n");
}

void remove_inicio(LISTA **inicio)
{
    if(*inicio == NULL)
        printf("\nNao foi possivel remover, a lista esta vazia.\n");
    else
    {
        LISTA *aux;
        aux = *inicio;
        if(aux->next == NULL)
        {
            free(aux);
            *inicio = NULL;
        }
        else
        {
            *inicio = aux->next;
            free(aux);
        }
    }
}

void remove_final(LISTA** inicio)
{
    if(*inicio == NULL)
        printf("\nNão foi possível remover, lista vázia\n");
    else
    {
        LISTA *atual, *anterior;
        atual = *inicio;
        while (atual->next != NULL)
        {
            anterior = atual;
            atual = atual->next;
        }
        if(atual == *inicio)
            remove_inicio(&*inicio);
        else
        {
            free(atual);
            anterior->next = NULL;
        }
    }
}

int remove_qualquer_cliente(LISTA **inicio, CLIENTE c1)
{
    if(*inicio == NULL)
        return 0;
    else
    {
        LISTA *atual, *anterior;
        atual = *inicio;
        while (atual != NULL && c1.cpf != atual->cliente.cpf)
        {
            anterior = atual;
            atual = atual->next;
        }
        if(atual == NULL)
            return 0;

        if(atual == *inicio)
        {
            remove_inicio(&*inicio);
        }
        else
        {
            anterior->next = atual->next;
        }
        free(atual);
        return 1;
    }
}

int consulta_posicao(LISTA **inicio,int posicao,CLIENTE *c1)//Lembrar de colocar verificação se o numero for negativo
{
    if(*inicio == NULL)
        return 0;
    int contador = 1;
    LISTA *aux = *inicio;
    //Caminhar na lista e comparar se posição é igual a posicao que foi passada
    while (aux != NULL && contador != posicao)
    {
        contador++;
        aux = aux->next;
    }
    if(aux == NULL)
    {
        return 0;
    }
    else
    {
        *c1 = aux->cliente;
        return 1;
    }
}

int consulta_cpf(LISTA **inicio, int cpf, CLIENTE *c1)//Lembrar de colocar verificação se o numero for negativo
{
    if(*inicio == NULL)
        return 0;
    else
    {

        LISTA *aux = *inicio;
        while (aux != NULL &&  cpf != aux->cliente.cpf)
        {
            aux = aux->next;
        }

        if(aux == NULL)
            return 0;
        else
        {
            *c1 = aux->cliente;
            return 1;
        }

    }

}

main()
{
    CLIENTE c1;
    LISTA *head;
    int contador_lista;
    int retorno;
    int posicao;
    head = criar_lista();//Mandei que meu ponteiro inicio(head) aponta para nulo
    printf("Endereco do inico da lista depois de criada [%p]", head);
    int opcao;
    while (1)
    {
        printf("\n");
        menu();
        printf("Digite a opcao: \n");
        scanf("%i", &opcao);
        system("CLS");
        switch (opcao)
        {
        case 1:
            printf("Insira o cpf para inserir no inicio\n");
            scanf("%i", &c1.cpf);
            insere_inicio(&head, c1);
            system("CLS");
            break;
        case 2:
            printf("Insira o cpf para inserir na ultima posicao\n");
            scanf("%i", &c1.cpf);
            insere_final(&head, c1);
            break;
        case 3:
            printf("Insira o cpf para inserir Em ordem\n");
            scanf("%i", &c1.cpf);
            insere_em_ordem(&head, c1);
            break;
        case 4:
            imprimi_lista(&head);
            break;
        case 5:
            contador_lista = conta_lista(&head);
            printf("Quantos itens na lista [%i]\n", contador_lista);
            break;
        case 6:
            printf("Removendo o primeiro item\n");
            remove_inicio(&head);
            break;
        case 7:
            printf("Removendo o ultimo item\n");
            remove_final(&head);
        case 8:
            printf("Digite o cpf que voce quer remover\n");
            scanf("%i", &c1.cpf);
            retorno = remove_qualquer_cliente(&head, c1);
            if(retorno == 0)
                printf("\nA lista esta vazia ou CPF nao foi encontrado.");
            else
                printf("CPF removido!!!");
            break;
        case 9:
            printf("Digite a posicao que voce quer consultar: \n");
            scanf("%i", &posicao);
            retorno = consulta_posicao(&head, posicao, &c1);
            if(retorno == 0)
                printf("\nA lista esta vazia ou a posicao nao foi encontrado");
            else
                printf("Posicao %i encontrada, o valor do cpf eh: %i", posicao, c1.cpf);
            break;
        case 10:
            printf("Digite o cpf que voce quer consultar: \n");
            scanf("%i", &c1.cpf);
            retorno = consulta_cpf(&head, c1.cpf, &c1);
            if(retorno == 0)
                printf("\nA lista esta vazia ou o cpf nao foi encontrado");
            else
                printf("CPF encontrada, o valor do cpf eh: %i", c1.cpf);
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("\nOpcao invalida\n");
            break;
        }
    }
}
