#include <stdio.h>
#define MAX 1000
#define MAX_T 500
#define MAX_N 100000
#define MAX_ALFA 27

int grafo[MAX_ALFA][MAX_ALFA];
int visitados[MAX_ALFA];
int graus[MAX_ALFA];
int quant_vertices;
int quant_graus_impar;
int graus_vertice_origem[MAX_ALFA];
int graus_vertice_destino[MAX_ALFA];

void busca(int k){
	for(int j = 0; j < MAX_ALFA ; j++){
		if( (grafo[k][j] == 1 || grafo[j][k] == 1) && visitados[j] == 0){
			visitados[j] = 1;
			busca(j);
		}
	}
}


bool pode_ser_euleriano(){
	bool flag = true;
		quant_graus_impar = 0;
		for (int l = 0; l < MAX_ALFA; l++){
			// Tem grau par
			if((graus_vertice_origem[l]+graus_vertice_destino[l]) % 2 ==0){
				// Por ter grau par, tem que sair a mesma quantidade de arestas que chega.
				if(graus_vertice_origem[l] != graus_vertice_destino[l]){
					flag = false;
				}
			}
			// Tem grau impar
			else{
				// Conta 1 para o grau impar
				if(graus_vertice_origem[l]%2 != 0)
					quant_graus_impar++;
				// Conta 1 para o grau impar
				if(graus_vertice_destino[l]%2 != 0)
					quant_graus_impar++;
			}
			// Se passar de 2 graus impares entao nao eh euleriano
			if (quant_graus_impar > 2){
				flag = false;
			}
		}
	return flag;
}

bool conexo(){

	for(int l = 0; l < MAX_ALFA; l++){
		if(graus[l] > 0){
			visitados[l] = 1;
			busca(l);
			break;
		}
	}

	int cont = 0;
	for (int l = 0; l < MAX_ALFA; l++)
	{
		if(visitados[l] == 1)
			cont++;
	}

	if(cont < quant_vertices)
		return false;
	return true;
}

int main(){

	int tam_entrada;
	char palavra[MAX];
	int quant_palavras;
	scanf("%d", &tam_entrada);

	if(tam_entrada > MAX_T)
		return 0;

	for (int i = 0; i < tam_entrada; i++){

		// Inicializacao, zerando tudo
		for (int l = 0; l < MAX_ALFA; l++){
			graus[l] = graus_vertice_origem[l] = graus_vertice_destino[l] = 0;
			visitados[l] = 0;
			for (int m = 0; m < MAX_ALFA; ++m){
				grafo[l][m] = 0;
			}
		}
		quant_vertices = 0;

		// Lendo 
		scanf("%d", &quant_palavras);
		if(quant_palavras > MAX_N || quant_palavras < 1)
			return 0;
		for (int j = 0; j < quant_palavras; j++){
			scanf("%s", &palavra[0]);
			int k;
			for (k = 0; palavra[k+1] != '\0'; k++);
			if(k == 0)
				return 0;

			int o = palavra[0]-'a';
			int d = palavra[k]-'a';
			graus_vertice_origem[o]++;
			graus_vertice_destino[d]++;
			grafo[o][d] = 1;
			graus[o]++;
			graus[d]++;
			
		}

		for (int j = 0; j < MAX_ALFA; j++)
		{
			if(graus[j] > 0)
				quant_vertices++;
		}

		/*
		if (1)
		{
			
			printf("\nQuantidade de vertices: %d\n", quant_vertices);
			for (int l = 0; l < MAX_ALFA; ++l){
				printf("%d ", graus_vertice_origem[l]);
			}
			printf("\n");
			for (int l = 0; l < MAX_ALFA; ++l){
				printf("%d ", graus_vertice_destino[l]);
			}
			printf("\n");
			for (int l = 0; l < MAX_ALFA; ++l){
				printf("%d ", visitados[l]);
			}
			printf("\n");	
			
		}
		if(v)
			printf("Sim pode ser euleriano\n");
		if(c)
			printf("Eh conexo\n");
		*/
		bool v = pode_ser_euleriano();

		bool c = conexo();

		if( v && c ){
			printf("Ordering is possible.\n");
		}else{
			printf("The door cannot be opened.\n");
		}
	}
	
	return 0;
}