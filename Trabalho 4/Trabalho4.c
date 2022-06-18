// TRABALHO 4 DE ALGORITMOS E ESTRUTURAS DE DADOS 1
//Informacoes do estudante
// Nome: Joao Pedro Pereira
// Curso: BCC
// RA: 769714

#include<stdio.h>
#include<stdlib.h>

int ordenaGenoma(int *v, int n) {
	int j, i, aux, cont; 
	cont = 0;
	for (j = 0; j < n; j++) {
		for (i = 1; i < n; i++) {
			if (v[i - 1] > v[i]) {
		 		aux = v[i - 1]; 
		 		v[i - 1] = v[i]; 
		 		v[i] = aux; 
		 		cont += 1;
			}
		}
	}
	return cont;	
}


int main()
{
	int i, n, resul;
	scanf("%d", &n);
	int genoma[n];
	for(i = 0; i < n; i++){
		scanf("%d", &genoma[i]);
	}
	resul = ordenaGenoma(genoma, n);
	printf("%d", resul);
    
    return 0;
}

