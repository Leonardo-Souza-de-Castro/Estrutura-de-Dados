#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int valor;
    struct Celula *proximo;
} Celula;

typedef struct {
    Celula *primeiro;
    int qtd;
} LDE;

Celula *criar_celula(int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->proximo = NULL;
    nova->valor = valor;
    return nova;
}

LDE *criar_lista(){
    LDE *lista = malloc(sizeof(LDE));
    lista->primeiro = NULL;
    lista->qtd = 0;
    return lista;
}

void inserir(LDE *lista, int valor){
    Celula *nova = criar_celula(valor);
    Celula *anterior = NULL;
    Celula *atual = lista->primeiro;
    while(atual != NULL && atual->valor < nova->valor){
        anterior = atual;
        atual = atual->proximo;
    }
    if(anterior == NULL){
        lista->primeiro = nova;
    } else {
        anterior->proximo = nova;
    }
    nova->proximo = atual;
    lista->qtd++;
}

void remover(LDE *lista, int valor) {
    if (lista -> qtd == 0)
    {
        return;
    }

    Celula *anterior = NULL;
    Celula *atual = lista->primeiro;
    while(atual != NULL && atual->valor != valor){ //While igual ao do inserir porém ele vai rodar enquanto o valor do atual for diferente do valor que a pessoa quer remover
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) //Valida se existe o valor na lista
    {
        return; //Para a função em caso de não achar o termo na lista
    }

    if (atual != NULL && anterior == NULL) //Valida se o termo atual não esta vazio e o anterior esta
    //O que significa que este é o primeiro termo
    {
        //Neste caso a lista deve apontar para o proximo valor apartir do atual
        lista->primeiro = atual->proximo;
        lista->qtd--; // Decrementa um na quantidade de termos na lista
    }
    
    //Valida se o termo atual esta preenchido e o anterior também esta
    if (atual != NULL && anterior != NULL)
    {
        //Neste caso eu falo que o próximo do anterior não aponta mais para o atual
        anterior->proximo = atual->proximo;
        lista->qtd--; // Decrementa um na quantidade de termos na lista
    }

    free(atual);
    
}

void mostrar(LDE *lista){
    Celula *atual = lista->primeiro;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main(){
    LDE *lista = criar_lista();
    int num;
    for(int i = 0; i < 10; i++){
        scanf("%d", &num);
        inserir(lista, num);
        mostrar(lista);
    }
    for(int i = 0; i < 10; i++){
        scanf("%d", &num);
        remover(lista, num);
        mostrar(lista);
    }
    return 0;
}