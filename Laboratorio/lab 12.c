#include <stdio.h>

#define V 8
#define E 20

int get_index(char x){
	return x - 114;
}

void inicia_arestas(int arestas[V][V]){
	int i;
	int j;
	for(i = 0; i < V; i++){
		for(j = 0; j < V; j++){
			arestas[i][j] = 0;
		}
	}
}

void cria_arestas(int arestas[V][V], int v, int u){
	arestas[v][u] = 1;
}

void mostra_arestas(int arestas[V][V]){
	int i;
	int j;
	for(i = 0; i < V; i++){
        for(j = 0; j < V; j++){
            printf("%d ", arestas[i][j]); 
        }
        printf("\n");
}

}

void mostra_adjacentes(int arestas[V][V], char v){
	int i;
	for (i = 0; i < V; i++)
	{
		if(arestas[get_index(v)][i] == 1){ //Pega dentro de uma lista especificas linha a linha e valida se o valor lá é igual a 1
		//Se for 1 significa que são adjascentes
			
			printf("%c -> %c \n", v, (i+114));
		} 

	}
	
}

void mostra_distancias(int arestas[V][V], char v){
	int distancias[] = {-1, -1, -1, -1, -1, -1, -1, -1};
	int Q[V];
	int head = 0;
	int tail = 0;
	int i;
	Q[tail++] = get_index(v);
	distancias[get_index(v)] = 0;

	while (head != tail)
	{
		int u = Q[head++];
		for (i = 0; i < V; i++)
		{
			if (arestas[u][i] == 1 && distancias[i] == -1)
			{
				distancias[i] = distancias[u] + 1;
				Q[tail++] = i;
			}
			
		}
	}

	for (i = 0; i < V; i++)
	{
		printf("%d ", distancias[i]);
	}

	printf("\n");
	
	
}

int main(void) {
	int i;
	char lista_de_vertices[V] = {'r', 's', 't', 'u', 'v', 'w', 'x', 'y'};
	char lista_de_arestas[E][2] = {"vr", "rv", "rs", "sr", "sw", "ws", "wt", "tw", "wx", "xw", "tx", "xt", "tu", "ut", "xu", "ux", "xy", "yx", "uy", "yu"};
  	int arestas[V][V];
	inicia_arestas(arestas);
	printf("Matriz de adjacências\n");
	for(i = 0; i < E; i++){
		cria_arestas(arestas, get_index(lista_de_arestas[i][0]), get_index(lista_de_arestas[i][1]));
	}
	mostra_arestas(arestas);
	printf("Lista de adjacências\n");
	for(i = 0; i < V; i++){
		mostra_adjacentes(arestas, lista_de_vertices[i]);
	}
	printf("Matriz de distâncias\n");
	for(i = 0; i < V; i++){
		mostra_distancias(arestas, lista_de_vertices[i]);
	}		
  return 0;
}