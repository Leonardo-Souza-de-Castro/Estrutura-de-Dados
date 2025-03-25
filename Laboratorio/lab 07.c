#include <stdio.h>
#include <stdlib.h>

typedef struct Cell
{
    struct Cell *anterior;
    struct Cell *proximo;
    char valor;
} Cell;

typedef struct
{
    Cell *top;
    int qtde;
} Stack;

Cell *start_cell(char valor)
{
    Cell *nova = malloc(sizeof(Cell));
    nova->anterior = NULL;
    nova->proximo = NULL;
    nova->valor = valor;
    return nova;
}

Stack *start_stack()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->qtde = 0;
    stack->top = NULL;
    return stack;
}

void push(Stack *stack, char valor)
{
    Cell *nova = start_cell(valor);
    if (stack->qtde != 0)
    {
        nova->proximo = stack->top;
        stack->top->anterior = nova;
    }
    stack->top = nova;
    stack->qtde++;
}

char pop(Stack *stack)
{
    if (stack->qtde > 0)
    {
        char valor = stack->top->valor;
        Cell *top = stack->top;
        stack->top = stack->top->proximo;
        if (stack->top != NULL)
            stack->top->anterior = NULL;
        stack->qtde--;
        free(top);
        return valor;
    }
    else
    {
        return 'x';
    }
}

int valida_par(char abre, char fecha)
{
    return (abre == '(' && fecha == ')') || (abre == '{' && fecha == '}') || (abre == '[' && fecha == ']');
}

int main(void)
{
    int parenteses = 0;
    int colchetes = 0;
    int chaves = 0;
    int correto = 1;
    Stack *stack = start_stack();

    char expr[100];
    fgets(expr, sizeof(expr), stdin);

    for (int i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == '(')
        {
            push(stack, expr[i]);
            parenteses++;
        }
        if (expr[i] == '[')
        {
            if (parenteses > 0)
            {
                correto = 0;
            }
            push(stack, expr[i]);
            colchetes++;
        }
        if (expr[i] == '{')
        {
            if (colchetes > 0)
            {
                correto = 0;
            }
            push(stack, expr[i]);
            chaves++;
        }

        if (expr[i] == ')')
        {
            char valor = pop(stack);
            if (valor != '(')
                correto = 0;
            parenteses--;
        }
        if (expr[i] == ']')
        {
            char valor = pop(stack);
            if (valor != '[')
                correto = 0;
            colchetes--;
        }
        if (expr[i] == '}')
        {
            char valor = pop(stack);
            if (valor != '{')
                correto = 0;
            chaves--;
        }
    }

    if (correto)
    {
        printf("correto");
    }
    else
    {
        printf("incorreto");
    }
    return 0;
}