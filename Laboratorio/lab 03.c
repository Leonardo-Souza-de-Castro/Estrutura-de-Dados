#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó na lista duplamente encadeada
typedef struct no {
    int valor;
    struct no *anterior;
    struct no *proximo;
} No;

// Definição da estrutura da lista duplamente encadeada
typedef struct lista_duplamente_encadeada {
    int quantidade;
    No *inicio;
} ListaDuplamenteEncadeada;

/**
 * Cria uma nova lista duplamente encadeada e a inicializa.
 *
 * @return Um ponteiro para a nova lista criada.
 */
ListaDuplamenteEncadeada *criar_lista() {
    ListaDuplamenteEncadeada *lista = malloc(sizeof(ListaDuplamenteEncadeada));
    lista->inicio = NULL;
    lista->quantidade = 0;
    return lista;
}

/**
 * Cria um novo nó contendo o valor especificado.
 *
 * @param valor O valor a ser armazenado no nó.
 * @return Um ponteiro para o novo nó criado.
 */
No *criar_no(int valor) {
    No *novo_no = malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->anterior = NULL;
    novo_no->proximo = NULL;
    return novo_no;
}

/**
 * Insere um valor na lista de forma ordenada.
 *
 * @param lista Ponteiro para a lista onde o valor será inserido.
 * @param valor O valor a ser inserido na lista.
 */
void inserir_valor(ListaDuplamenteEncadeada *lista, int valor) {
    No *novo = criar_no(valor);
    No *anterior = NULL;
    No *atual = lista->inicio;

    while (atual != NULL && atual->valor < novo->valor)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    //Add termo em uma lista vazia
    if (lista->quantidade == 0)
    {
        lista->inicio = novo;
    }
    
    //Add termo em uma lista não vazia na primeira posição
    else if(anterior == NULL && atual != NULL)
    {
        lista->inicio = novo;
        novo->proximo = atual;
        novo->anterior = NULL;
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
    lista->quantidade++;
}

/**
 * Exibe os valores da lista em ordem crescente.
 *
 * @param lista Ponteiro para a lista a ser exibida.
 */
void exibir_lista(ListaDuplamenteEncadeada *lista) {
    No *atual = lista->inicio;

    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("\n");
}

/**
 * Exibe os valores da lista em ordem decrescente.
 *
 * @param lista Ponteiro para a lista a ser exibida.
 */
void exibir_lista_invertida(ListaDuplamenteEncadeada *lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia\n");
        return; // Se a lista estiver vazia, não há nada a exibir
    }

    No *atual = lista->inicio;
    No *anterior = NULL;

    while (atual->proximo != NULL)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }
    
    printf("\n");
}

/**
 * Remove o nó que contém o valor especificado da lista.
 *
 * @param lista Ponteiro para a lista de onde o valor será removido.
 * @param valor O valor a ser removido da lista.
 */
void remover_valor(ListaDuplamenteEncadeada *lista, int valor) {
    //Valida se a lista esta vazia
    if(lista->inicio == NULL){
        printf("Lista vazia\n");
        return;
    }
    //Lista não vazia atribui a um nó o valor do primeiro termo da lista
    No *atual = lista->inicio;

    //Compara enquanto o atual não estiver vazio e valor for diferente
    while (atual != NULL && atual->valor != valor)
    {
        atual = atual->proximo;
    }

    // Se no fim da comparação atual for nulo aquele valor não existe na lista
    if (atual == NULL)
    {
        return;
    }
    //Se atual for o primeiro termo da lista
    if(atual == lista->inicio){
        //Se a lista tiver um unico termo
        if(lista->quantidade == 1){
            //remove ele, atualiza quantidade e inicio volta a ser NULL
            free(atual);
            lista->quantidade--;
            lista->inicio = NULL;
            return;
        }
        //Se não for o unico termo inicio aponta para o proximo termo
        lista->inicio = atual->proximo;
        //Se inicio não for nulo o valor anterior a ela vai ser NULL
        if (lista->inicio != NULL){
            lista->inicio->anterior = NULL;
        }
    }
    //Se o atual estiver no meio ou final da lista
    else{
        //O proximo valor do anterior vai apontar pro proximo do atual
        atual->anterior->proximo = atual->proximo;
        //Se o proximo valor do atual for diferente de null o anterior do proximo aponta pro anterior do atual
        if (atual->proximo != NULL){
            atual->proximo->anterior = atual->anterior;
        }

    }
    //Libera a memoria
    free(atual);
    //Decrementa a quantidade
    lista->quantidade--;
}


int main(void) {
    ListaDuplamenteEncadeada *lista = criar_lista();

    inserir_valor(lista, 10);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    inserir_valor(lista, 5);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    inserir_valor(lista, 20);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    inserir_valor(lista, 15);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 5);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 15);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 20);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 10);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    int i = 1;
    for (i; i <= 10; i++) {
        inserir_valor(lista, i);
    }
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    for (i = 1; i <= 10; i++) {
        remover_valor(lista, i);
    }
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 100);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    inserir_valor(lista, 10);
    inserir_valor(lista, 10);
    inserir_valor(lista, 10);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    return 0;
}
