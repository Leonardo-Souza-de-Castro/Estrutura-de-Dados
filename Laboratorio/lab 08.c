#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct
{
    int valores[LEN];
    int qtde;
} heap;

int filho_esq(int pai)
{
    return (2 * pai) + 1;
}

int filho_dir(int pai)
{
    return (2 * pai) + 2;
}

int pai(int filho)
{
    return (filho - 1) / 2;
}

int ultimo_pai(heap *h)
{
    int pos_ult = (h->qtde / 2) - 1;

    return pos_ult;
}

void peneirar(heap *h, int pai)
{
    int filho_1 = filho_esq(pai);
    int filho_2 = filho_dir(pai);

    int maior = pai;

    if (filho_1 < h->qtde && h->valores[filho_1] > h->valores[maior])
    {
        maior = filho_1;
    }

    if (filho_2 < h->qtde && h->valores[filho_2] > h->valores[maior])
    {
        maior = filho_2;
    }

    if (maior != pai)
    {
        int teste = h->valores[pai];
        h->valores[pai] = h->valores[maior];
        h->valores[maior] = teste;
        peneirar(h, maior);
    }
}

void mostrar(heap *h)
{
    for(int i = 0; i < h->qtde; i++)
    {
        printf("%d ", h->valores[i]);
    }
    printf("\n");
}

void construir(heap *h)
{
    int ult = ultimo_pai(h);

    for(int i = ult; i >= 0; i--)
    {
        peneirar(h, i);
    }
}

void inserir(heap *h, int valor)
{
    h->valores[h->qtde++] = valor;

    int p = pai(h->qtde - 1);
    if (h->valores[p] < h->valores[h->qtde - 1])
    {
        construir(h);
    }
}

void remover(heap *h)
{
    h->qtde--; 
    int ultimo = h->valores[h->qtde];
    h->valores[0] = ultimo;
    construir(h);
}

int main(void)
{
    heap *h = malloc(sizeof(heap));
    int valor;
    h->qtde = 0;
    for (int i = 0; i < LEN; i++)
    {
        scanf("%d", &valor);
        inserir(h, valor);
        mostrar(h);
    }
    for (int i = 0; i < LEN; i++)
    {
        remover(h);
        mostrar(h);
    }

    return 0;
}