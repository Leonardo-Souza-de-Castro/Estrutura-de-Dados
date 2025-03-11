#include <stdio.h>

#define LEN 100

typedef struct
{
    char data[LEN];
    int head;
    int tail;
    int qtde;
} Queue;

void enqueue(Queue *queue, char caracter)
{
    if (queue->qtde == LEN)
    {
        return;
    }

    queue->data[queue->tail++] = caracter;
    queue->qtde++;
}

int dequeue(Queue *queue)
{
    if (queue->qtde == 0)
    {
        return 0;
    }

    char valor = queue->data[queue->head++];
    queue->qtde--;

    return valor;
}

void show(Queue *queue)
{
    int i = 0;
    for (i = queue->head; i < queue->tail; i++)
    {
        printf("%c", queue->data[i]);
    }
}

void start_queue(Queue *queue)
{
    queue->head = 0;
    queue->tail = 0;
    queue->qtde = 0;
}

int main(void)
{
    int flag = 1;
    char s[LEN];
    fgets(s, sizeof(s), stdin);
    Queue queue;
    start_queue(&queue);
    Queue *pq = &queue;


    for (int i = 0; s[i] != '\0'; i++)
    {
        enqueue(&queue, s[i]);
    }

    Queue parenteses;
    start_queue(&parenteses);
    Queue *pontpara = &parenteses;

    for (int i = pq->head; i < pq->tail; i++)
    {
        char valor = dequeue(pq);
        // valor = queue->data[i];
        if (valor == 0)
        {
            break;
        }
        
        
        if (valor == '(')
        {
            enqueue(&parenteses, valor); // enqueue -> ADICIONAR
            // dequeue -> REMOVER
        }
        else if (valor == ')')
        {
            if (dequeue(&parenteses) == 0)
            {
                flag = 0;
                break;
            }
        }

        show(pq);
    }

    if (pontpara->qtde != 0)
    {
        flag = 0;
    }
    

    if (flag == 0)
    {
        printf("incorreto\n");
    }
    else
    {
        printf("correto\n");
    }

    return 0;
}
