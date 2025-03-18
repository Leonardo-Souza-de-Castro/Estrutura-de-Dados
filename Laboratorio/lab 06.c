#include <stdio.h>
#include <stdlib.h>

typedef struct Celula
{
    int valor;
    struct Celula *proximo;
    struct Celula *anterior;
} Celula;

typedef struct
{
    Celula *head;
    Celula *tail;
    int qtde;
} Queue;

Celula *cria_celula(int valor)
{
    Celula *celula = malloc(sizeof(Celula));
    celula->proximo = NULL;
    celula->anterior = NULL;
    celula->valor = valor;

    return celula;
}

Queue *cria_queue()
{
    Queue *queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->qtde = 0;

    return queue;
}

void enqueue(Queue *queue, int valor)
{
    Celula *nova = cria_celula(valor);

    if (queue->qtde == 0)
    {
        queue->head = nova;
    }
    else
    {
        queue->tail->proximo = nova;
        nova->anterior = queue->tail;
    }

    queue->tail = nova;
    queue->qtde++;
}

int dequeue(Queue *queue)
{
    Celula *nova = queue->head;
    int valor = nova->valor;
    if (queue->qtde == 1)
    {
        queue->head = NULL;
        queue->tail = NULL;
    }
    else
    {
        queue->head = queue->head->proximo;
        queue->head->proximo->anterior = NULL;
    }

    free(nova);
    queue->qtde--;

    return valor;
}

void show(Queue *queue)
{
    Celula *atual = queue->head;
    while (queue->qtde > 0)
    {
        printf("%d", atual->valor);
        atual = atual->proximo;
        queue->qtde--;
    }

    printf("\n");
}

void show_invertido(Queue *queue)
{
    Celula *atual = queue->tail;
    while (atual != NULL)
    {
        printf("%d", atual->valor);
        atual = atual->anterior;
    }
    printf("\n");
}

Queue calcular_valor(Queue *queue1, Queue *queue2)
{
    Queue *resultado = cria_queue();
    Celula *atual1 = queue1->tail;
    Celula *atual2 = queue2->tail;

    int carry = 0;
    while (queue1->qtde > 0)
    {
        int soma = atual1->valor + atual2->valor + carry;
        if (soma > 9)
        {
            carry = 1;
            soma -= 10;
        }
        else
        {
            carry = 0;
        }
        enqueue(resultado, soma);
        atual1 = atual1->anterior;
        atual2 = atual2->anterior;
        queue1->qtde--;
    }
    if (carry)
    {
        enqueue(resultado, carry);
    }
    return *resultado;
}

int main(void)
{
    Queue *qnum1 = cria_queue();
    Queue *qnum2 = cria_queue();
    Queue *res = cria_queue();

    char num1[100];
    char num2[100];
    fgets(num1, sizeof(num1), stdin);
    fgets(num2, sizeof(num2), stdin);

    int i = 0;
    while (num1[i] != '\n')
    {
        enqueue(qnum1, (int)(num1[i]) - 48);
        enqueue(qnum2, (int)(num2[i]) - 48);
        i++;
    }

    *res = calcular_valor(qnum1, qnum2);
    show_invertido(res);
}