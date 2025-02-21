#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    struct Celula *anterior;
    struct Celula *proximo;
    int valor;
} Celula;

typedef struct{
    Celula *primeiro;
    int qntd;
} LDDE;

Celula *criar_celula(int valor){
    Celula *novo = malloc(sizeof(Celula));

    novo->anterior = NULL;
    novo->proximo = NULL;
    novo->valor = valor;

    return novo;
}

LDDE *criar_lista(){
    LDDE *lista = malloc(sizeof(LDDE));

    lista->primeiro = NULL;
    lista->qntd=0;

    return lista;
}

void Inserir(int valor, LDDE *lista){
    Celula *novo = criar_celula(valor);
    Celula *anterior = NULL;
    Celula *atual = lista->primeiro;

    while (atual != NULL && atual->valor < novo->valor)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    //Add termo em uma lista vazia
    if (lista->qntd == 0)
    {
        lista->primeiro = novo;
    }
    
    //Add termo em uma lista não vazia na primeira posição
    else if(anterior == NULL && atual != NULL)
    {
        lista->primeiro = novo;
        novo->proximo = atual;
        atual->anterior = novo;
    }

    //Add termo no fim da lista
    else if(anterior != NULL && atual == NULL){
        anterior->proximo = novo;
        novo->anterior = anterior;
    }

    //Add termo no meio da lista
    else{
        anterior->proximo = novo;
        novo->anterior = anterior;
        novo->proximo = atual;
        atual->anterior = novo;

        
    }

    lista->qntd++;
}


void exibir(LDDE *lista){
    Celula *atual = lista->primeiro;

    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("\n");
    
}

int main(){
    LDDE *lista = criar_lista();

    Inserir(12, lista);
    exibir(lista);
    Inserir(8, lista);
    exibir(lista);
    Inserir(18, lista);
    exibir(lista);
    Inserir(15, lista);
    exibir(lista);

    return 0;
}