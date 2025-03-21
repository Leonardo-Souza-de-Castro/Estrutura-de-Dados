#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    struct Celula *anterior;
    int valor;
    struct Celula *proximo;
} Celula;

typedef struct {
    Celula *topo;
    int qtde;
}Pilha;

Celula *criar_celula(int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->anterior = NULL;
    nova->proximo = NULL;
    nova->valor = valor;

    return nova;
}

Pilha *criar_pilha(){
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->qtde = 0;
    pilha->topo = NULL;

    return pilha;
}

void push(Pilha *pilha, int valor){

    Celula *nova = criar_celula(valor);
    printf("TOPO -> ");
    if (pilha->qtde != 0)
    {
        pilha->topo->proximo = nova;
        nova->anterior = pilha->topo;
    }

    pilha->topo = nova;
    pilha->qtde++;
}

void mostrar(Pilha *pilha){
    Celula *atual = pilha->topo;

    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }

    printf(" <- BASE\n");
    
}

int pop(Pilha *pilha){
    
    Celula *topo = pilha->topo;
    int valor = pilha->topo->valor;

    if (pilha->qtde > 1)
    {
        pilha->topo->anterior->proximo = NULL;
        pilha->topo = pilha->topo->anterior;
    }else if (pilha->qtde == 1)
    {
        pilha->topo = NULL;
    }

    free(topo);
    pilha->qtde--;
    return valor;
}

void main(){
    Pilha *pilha = criar_pilha();
    int i = 0;
    for (i; i < 10; i++)
    {
        push(pilha, i);
        mostrar(pilha);
    }
    i = 0;
    for (i; i < 10; i++)
    {
        pop(pilha);
        mostrar(pilha);
    }

    
}