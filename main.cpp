#include <stdio.h>
#define MAX 1000
#define MAX_T 500
#define MAX_N 100000

int main(){

	int tam_entrada;
	char palavra[MAX];
	int graus_vertice_origem[27];
	int graus_vertice_destino[27];
	int quant_palavras;
	bool flag;
	scanf("%d", &tam_entrada);
	if(tam_entrada > MAX_T)
		return 0;
	for (int i = 0; i < tam_entrada; i++){
		for (int l = 0; l < 27; l++){
			graus_vertice_origem[l] = graus_vertice_destino[l] = 0;
		}
		flag = false;
		scanf("%d", &quant_palavras);
		if(quant_palavras > MAX_N || quant_palavras < 1)
			return 0;
		for (int j = 0; j < quant_palavras; j++){
			scanf("%s", &palavra[0]);
			int k;
			for (k = 0; palavra[k+1] != '\0'; k++);
			if(k == 0)
				return 0;
			
			graus_vertice_origem[palavra[0]-97]++;
			graus_vertice_destino[palavra[k]-97]++;
			
		}
		int quant_graus_impar = 0;
		int quant_zeros = 0;
		int quant_uns = 0;
		for (int l = 0; l < 27; l++){
			if((graus_vertice_origem[l]+graus_vertice_destino[l]) % 2 ==0){
				if(graus_vertice_origem[l] != graus_vertice_destino[l])
					flag = true;
				if(graus_vertice_destino[l] == 1 && graus_vertice_origem[l] == 1)
					quant_uns++;
				if(graus_vertice_destino[l] == 0 && graus_vertice_origem[l] == 0)
					quant_zeros++;
			}
			else{
				if(graus_vertice_origem[l]%2 != 0)
					quant_graus_impar++;

				if(graus_vertice_destino[l]%2 != 0)
					quant_graus_impar++;
			}
			if (quant_graus_impar > 2){
				flag = true;	
			}
		}
		if(quant_zeros == 27)
			flag = true;
		if(quant_uns > 2)
			flag = true;
		
		for (int l = 0; l < 27; ++l){
			printf("%d ", graus_vertice_origem[l]);
		}
		printf("\n");
		for (int l = 0; l < 27; ++l){
			printf("%d ", graus_vertice_destino[l]);
		}
		printf("\n");
		
		if(flag){
			printf("The door cannot be opened.\n");
		}else{
			printf("Ordering is possible.\n");
		}
	}
	
	return 0;
}