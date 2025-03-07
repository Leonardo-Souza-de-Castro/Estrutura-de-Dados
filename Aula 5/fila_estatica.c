#include <stdio.h>
#include <stdlib.h>

#define CAP 10

typedef struct{
    int queue[CAP];
    int head;
    int tail;
    int qtd;
}Queue;

int IsFull(Queue *q){
    return q->qtd == CAP;
}

void Enqueue(Queue *q, int value){
    if (IsFull(q))
    {
        return;
    }
    
    //q->queue[q->tail] = value; //Caso seja uma fila estatica normal não circular
    q->queue[q->tail%CAP] = value; //Caso seja uma fila circular

    q->tail++;
    q->qtd++;
}

int IsEmpty(Queue *q){
    return q->qtd == 0;
}

int Dequeue(Queue *q){
    if (IsEmpty(q))
    {
        return 0;
    }

    //int value = q->queue[q->head] //Caso seja uma fila estatica não circular
    int value = q->queue[q->head%CAP]; //Caso seja uma fila circular

    q->head++;
    q->qtd--;
    
    return value;
}

void Show(Queue *q){
    int i = 0;
    
    for(i = q->head; i < q->tail; i++)
    {
        printf("%d ", q->queue[i%CAP]);
    }

    printf("\n");
    
}

void main(){
    Queue q;
    //Para acessar os membros de ponteiros usamos ->, para acessar os membros de listas usamos .

    q.head = 0;
    q.tail = 0;
    q.qtd = 0;

    Queue *pq = &q;
    int i = 0;
    for (i; i < 15; i++)
    {
        Enqueue(pq, i);
        Show(pq);
    }
    

    for (i = 0; i < 15; i++)
    {
        printf("Valor removido: %d\n", Dequeue(pq));
        Show(pq);
    }
    
}