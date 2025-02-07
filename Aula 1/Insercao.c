#include <stdio.h>


//Define uma constante que servira para definir nosso tamanho
#define LEN 10

//Define a estrutura (struct) renomeado (les) com typedef, onde definimos os campos que fazem parte da nossa estrutura

typedef struct{
    int dados[LEN];
    int qntd;
} les;

int i = 0;

int is_full(les *les){
    return les ->qntd == LEN; //Nesse caso acessamos o elemento len (com ->) e dentro dele comparamos a sua propriedade quntd com o possivel tamanho da linhas
}

int position(les *les, int value){
    for (i = 0; i < les->qntd; i++)
    {
        if (les->dados[i] > value) //Mapeamos a lista de dados dentro do nosso les e vemos se esse termo é maior que o valor a ser inserido, se for significa que naquela posição o nosso value deve ser add
        {
            return i;
        }
        
    }
    return les->qntd;
}

void move_right(les *les, int index){
    //Funcao para mover os elementos para frente nos ponteiros a ideia é comparar a posicao final antes dela ser menor que nosso index movemos o termo para a frente
    for (i = les->qntd; i > index ; i--)
    {
        les->dados[i] = les->dados[i-1];
    }
    
}

//Adicionamos um item na lista se todas as condições forem atendidas
void insert(les *les, int value){
    int idx = position(les, value);
    
    if (!is_full(les))
    {
        move_right(les, idx);
        les->dados[idx] = value;
        les->qntd++;
    }else{
        return;
    } 
}

void show(les *les){
    for (i = 0; i < les->qntd; i++)
    {
        printf("%d", les->dados[i]);
    }
    
}

int main(){
    //define a lista (lista) e o ponteiro dela (p_lista) e passamos as funções
    les lista;
    les *p_lista = &lista;

    for (i = 10; i >= 0; i++)
    {
        insert(p_lista, i);
        show(p_lista);
    } 
};