#include <stdio.h>
#include <stdlib.h>

typedef struct Celula
{
    struct Celula *anterior;
    struct Celula *proximo;
    int valor;
} Celula;

typedef struct{
    int qtde;
    Celula *head;
    Celula *tail;
} Fila;

Celula *criar_celula(int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->proximo = NULL;
    nova->anterior = NULL;
    nova->valor = valor;

    return nova;
}

void enfileirar(int valor, Fila *fila){
    Celula *nova = criar_celula(valor);

    if (fila->qtde == 0)
    {
        fila->head = nova;
    }else{
        fila->tail->proximo = nova;
        nova->anterior = fila->tail; 
    }

    fila->tail = nova;
    fila->qtde++;
}

