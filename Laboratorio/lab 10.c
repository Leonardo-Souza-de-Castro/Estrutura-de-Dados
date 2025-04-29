#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
	int valor;
	struct Vertice* esq;
	struct Vertice* dir;
	struct Vertice* pai;
} Vertice;

typedef struct Arvore{
	Vertice* raiz;
	int qtde;
} Arvore;

void in_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        in_ordem(raiz->esq);
        printf("%d ", raiz->valor);
        in_ordem(raiz->dir);
    }
}

void pre_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void pos_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

Vertice *cria_vertice(int valor){
	Vertice* novo = malloc(sizeof(Vertice));
	novo->dir = NULL;
	novo->esq = NULL;
	novo->pai = NULL;
	novo->valor = valor;
	
	return novo;
}

Arvore *cria_arvore(){
	Arvore* arvore = malloc(sizeof(Arvore));
	arvore->raiz = NULL;
	arvore->qtde = 0;

	return arvore;
}

void inserir(Arvore* arvore, int valor){
	Vertice* novo = cria_vertice(valor);

	Vertice* anterior = NULL;
	Vertice* atual = arvore->raiz;

	while(atual != NULL){
		anterior = atual;
		if(valor <= anterior->valor){
			atual = atual->esq;
		}else{
			atual = atual->dir;
		}
	}

	novo->pai = anterior;
	if(anterior != NULL){
		if(valor <= anterior->valor){
			anterior->esq = novo;
		}else{
			anterior->dir = novo;
		}
	}else{
		arvore->raiz = novo;
	}
	arvore->qtde++;
}

int remover_vertice(Arvore* arvore, Vertice* vertice) {
    if (vertice->pai == NULL)
    {
        if (vertice->dir != NULL && vertice->esq != NULL)
        {
            Vertice* vertice_sub = vertice->esq;
            while (vertice_sub->dir != NULL)
            {
                vertice_sub = vertice_sub->dir;
            }
            int valor = vertice->valor;
            vertice->valor = vertice_sub->valor;
            vertice_sub->valor = valor;
            remover_vertice(arvore, vertice_sub);
            
        }
        else if (vertice->dir == NULL && vertice->esq != NULL)
        {
            arvore->raiz = vertice->esq;
            vertice->esq->pai = NULL;
            free(vertice);
        }
        else if (vertice->dir != NULL && vertice->esq == NULL){
            arvore->raiz = vertice->dir;
            vertice->dir->pai = NULL;
            free(vertice);
        }else{
            arvore->raiz = NULL;
            free(vertice);
        }
    }
    else{
        Vertice* vertice_sub;
        if (vertice->dir != NULL && vertice->esq != NULL)
        {
            Vertice* vertice_sub = vertice->esq;
            while (vertice_sub->dir != NULL)
            {
                vertice_sub = vertice_sub->dir;
            }
            int valor = vertice->valor;
            vertice->valor = vertice_sub->valor;
            vertice_sub->valor = valor;
            remover_vertice(arvore, vertice_sub);
        }
        else if (vertice->dir == NULL && vertice->esq != NULL)
        {
            vertice_sub = vertice->esq;
            if (vertice->pai->esq == vertice)
            {
                vertice->pai->esq = vertice_sub;
                vertice_sub->pai = vertice->pai;
                free(vertice);
            }
            else{
                vertice->pai->dir = vertice_sub;
                vertice_sub->pai = vertice->pai;
                free(vertice);
            }
            
        }
        else if (vertice->dir != NULL && vertice->esq == NULL){
            vertice_sub = vertice->dir;
            if (vertice->pai->esq == vertice)
            {
                vertice->pai->esq = vertice_sub;
                vertice_sub->pai = vertice->pai;
                free(vertice);
            }
            else{
                vertice->pai->dir = vertice_sub;
                vertice_sub->pai = vertice->pai;
                free(vertice);
            }
        }
        else{
             if (vertice->pai->esq == vertice)
            {
                vertice->pai->esq = NULL;
                free(vertice);
            }
            else{
                vertice->pai->dir = NULL;
                free(vertice);
            }
        }
    }

    return 0;
}

Vertice *buscar_valor(Arvore* arvore, int valor){
	Vertice* atual = arvore->raiz;
	while(atual != NULL){
		if(valor < atual->valor){
			atual = atual->esq;
		}else if(valor > atual->valor){
			atual = atual->dir;
		}else{
			return atual;
		}
	}
	return NULL;
}


int main(void) {
	int dados[] = {5, 3, 8, 2, 4, 7, 9, 1, 6, 10};
  	Arvore *arvore = cria_arvore();
  	
	for(int i = 0; i < 10; i++){
		inserir(arvore, dados[i]);
		printf("Inseriu %d mostra em ordem -> ", dados[i]);
		in_ordem(arvore->raiz);
		printf("\n");
		printf("Inseriu %d mostra em pré-ordem -> ", dados[i]);
		pre_ordem(arvore->raiz);
		printf("\n");
		printf("Inseriu %d mostra em pós-ordem -> ", dados[i]);
		pos_ordem(arvore->raiz);
		printf("\n");
	}

	for(int i = 0; i < 10; i++){
		Vertice *vertice = buscar_valor(arvore, dados[i]);
		if(vertice != NULL){
			remover_vertice(arvore, vertice);
		}
		printf("Removeu %d mostra em ordem -> ", dados[i]);
		in_ordem(arvore->raiz);
		printf("\n");
		printf("Removeu %d mostra em pré-ordem -> ", dados[i]);
		pre_ordem(arvore->raiz);
		printf("\n");
		printf("Removeu %d mostra em pós-ordem -> ", dados[i]);
		pos_ordem(arvore->raiz);
		printf("\n");
	}

	free(arvore);
		
    return 0;
}
