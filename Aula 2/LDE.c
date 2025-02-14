#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    int valor;
    struct Celula *prox;
}Celula;

typedef struct{
    Celula *primeiro;
    int qnt;
} LDE;

Celula *criar_celula(int valor){
    Celula *nova = malloc(sizeof(Celula)); //Aqui alocamos em memória um espaço reservado para criar uma nova célula, além disso o ponteiro nova marca a primeira posição dessa sequencia
    nova -> prox = NULL; //Coloca como o proximo valor sendo null por que esse foi acabado de ser adicionado então não tem nada depois
    nova -> valor = valor; //Adicionamos o valor na celula
    return nova;
}

LDE *criar_lista(){
    LDE *lista = malloc(sizeof(LDE));
    lista -> primeiro = NULL;
    lista -> qnt = 0;
}

void inserir(LDE *lista, int valor){
    Celula *nova = criar_celula(valor);
    //Add valor se a lista esta vazia
    if(lista->primeiro == NULL){
        lista->primeiro = nova;
        lista->qnt++;
        return;
    }

    //Valida em uma lista cheia a posição que termo deve ser inserido
    Celula *anterior = NULL;
    Celula *atual = lista->primeiro;
    //Percorre a lista vendo se o valor do termo atual é menor que o novo valor a ser inserido
    //Nesse caso é como se o ponteiro apontasse para si mesmo
    while (atual != NULL && atual->valor < nova->valor)
    {
        anterior = atual;
        atual = atual->prox;
    }

    //Adiciona um novo primeiro valor na lista
    if (anterior == NULL && atual != NULL)
    {
        nova->prox = atual; //nova célula vai apontar para a atual
        lista->primeiro = nova; //A primeira poss da lista aponta para a nova célula
        lista->qnt++;
        return;
    }
    
    //Adiciona valor no final de uma lista não vazia
    if (atual == NULL && anterior != NULL)
    {
        anterior->prox = nova; // anterior (ultima) aponta para a nova célula
        lista->qnt++;
        return;
    }

    //adicionando no meio da lista
    if(atual != NULL && anterior != NULL){
        anterior->prox = nova; //anterior aponta pra nova celula
        nova->prox = atual; // nova aponta para a atual célula
        lista->qnt++;
        return;
    }
    
}

void mostrar(LDE *lista){
    Celula *atual = lista->primeiro;
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
    
}

int main(){
    LDE *lista = criar_lista();
    int i = 0;
    for (i = 10; i > 0; i--)
    {
        inserir(lista, i);
        mostrar(lista);
    }
    
    return 0;
}