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

Fila *criar_fila(){
    Fila *fila = malloc(sizeof(Fila));
    fila->head = NULL;
    fila->tail = NULL;
    fila->qtde = 0;

    return fila;
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

int desenfileirar(Fila *fila){
    if (fila->qtde == 0)
    {
        return -1;
    }

    Celula *liberar = fila->head;
    int valor = fila->head->valor;

    if (fila->qtde == 1)
    {
        fila->head = NULL;
        fila->tail = NULL;
    
    } else{
        fila->head->proximo->anterior = NULL;
        fila->head = fila->head->proximo;

    }

    fila->qtde--;
    free(liberar);
    return(valor);
    
}

void mostrar_fila(Fila *fila, int inversa){
    if (!inversa)
    {
        Celula *atual = fila->head;
        printf("HEAD -> ");
        while (atual!=NULL)
        {
            printf("%d ", atual->valor);
            atual = atual->proximo;
        }
        printf("<- TAIL");
    }else{
        Celula *atual = fila->tail;
        printf("TAIL -> ");
        while (atual!=NULL)
        {
            printf("%d ", atual->valor);
            atual = atual->anterior;
        }
        printf("<- HEAD");
    }
    printf("\n");
}

void main(){
    Fila *fila = criar_fila();

    enfileirar(10, fila);
    // mostrar_fila(fila, 0);
    // mostrar_fila(fila, 1);
    enfileirar(20, fila);
    // mostrar_fila(fila, 0);
    // mostrar_fila(fila, 1);
    enfileirar(30, fila);
    mostrar_fila(fila, 0);
    mostrar_fila(fila, 1);
    
    int i = 0;
    for (i; i < 4; i++)
    {
        printf("%d\n", desenfileirar(fila));
        mostrar_fila(fila, 0);
        mostrar_fila(fila, 1);
    }
}