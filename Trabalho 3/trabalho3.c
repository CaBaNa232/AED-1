// TRABALHO 2 DE ALGORITMOS E ESTRUTURAS DE DADOS 1
//Informacoes do estudante
// Nome: Joao Pedro Pereira
// Curso: BCC
// RA: 769714

#include<stdio.h>
#include<stdlib.h>

#define N 4

//Tipo No de uma fila implementada usando lista ligada
typedef struct no{
	
    int lin;
    int col;
    struct no * prox;
    
}No;

No * fila;

//retorna um ponteiro para o inicio da fila criada
No *cria(){
	
	No *fila;
	fila = NULL;
	
	return fila;
}

No *entra(No * inicio, int lin, int col){
	
	No *nova; 
	No *aux; 
	nova = (No *)malloc(sizeof(No));
	aux = inicio;
	nova->lin = lin;
	nova->col = col;
	nova->prox = NULL;
	
	if(inicio == NULL){
		inicio = nova;
	}
	else{
		aux = inicio;
		while(aux->prox != NULL){
			aux = aux->prox; 
		}
		aux->prox = nova;
	}
	nova->prox = NULL;

	return inicio;
}

No * sai(No * inicio, int * lin, int * col){
	
	No *morta;
	morta = inicio;
	*lin = inicio->lin;
	*col = inicio->col;
	inicio = inicio->prox;
	free(morta);
	morta = NULL;
	return inicio;	
}


int vazia(No * inicio){
	
	int lista_vazia = 0;
	
	if (inicio == NULL){
		lista_vazia = 1;
	}
	return lista_vazia;
   
}

void printSolution(int sol[N][N])
{
    fila = cria();
    int i, j;
    for (i = 0; i < N; i++) {
    	
        for (j = 0; j < N; j++){
        	
            printf(" %d ", sol[i][j]);
            
            if(sol[i][j] == 1)
            
                fila = entra(fila,i,j);
                
        }
        
        printf("\n");
    }
    int lin, col;
    
    while(fila != NULL){
    	
        fila = sai(fila,&lin,&col);
        printf("(%d,%d)->",lin,col);
    }
}

int solLabirinto(int mat[][N], int x, int y, int aux[][N]) {
	
	
	if(x == N - 1 && y == N - 1){
	
		aux[x][y] = 1;
		
		return 1;
	}
	
	if(x > N || y > N || mat[x][y] != 1 ){ 
	
		return 0;
	}
	if (x>=0 && y<N && y>=0 && x<N && mat[x][y] == 1){
		aux[x][y] = 1;
		
		if(solLabirinto(mat, x + 1, y, aux)){
			
			return 1;
		}
		if(solLabirinto(mat, x, y  + 1, aux)) {
			
			return 1;
		}
		aux[x][y] = 0;
		return 0;

	}

	return 0;
}
    
void resolveLabirinto(int x[N][N]) {
	
	int i, j, M[N][N], resul;

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			M[i][j] = 0;
		}
	}
	
	resul =  solLabirinto(x, 0, 0, M);
	
	if(resul == 1){
		printSolution(M);
	}else{
		printf("\nSEM SOLUCAO");
	}
	
}



/* Imprime solucao a partir de uma matriz com 1 nas posicoes que fazem parte da solucao e 0 na posicoes que nao fazem parte*/

int main()
{
	
    int labirinto1 [N][N] = { { 1, 0, 0, 0 },
                              { 1, 1, 0, 1 },
                              { 0, 1, 0, 0 },
                              { 1, 1, 1, 1 } };

    int labirinto2 [N][N] = { { 1, 1, 1, 0 },
                              { 0, 0, 1, 1 },
                              { 0, 0, 0, 1 },
                              { 1, 1, 1, 1 } };

    int labirinto3 [N][N] = { { 1, 1, 1, 0 },
                              { 0, 1, 0, 1 },
                              { 0, 1, 1, 0 },
                              { 1, 1, 1, 1 } };


    int labirinto4 [N][N] = { { 1, 1, 1, 0 },
                              { 1, 0, 0, 1 },
                              { 1, 0, 1, 0 },
                              { 1, 1, 1, 1 } };

    int labirinto5 [N][N] = { { 1, 1, 0, 0 },
                              { 0, 0, 0, 1 },
                              { 0, 0, 1, 0 },
                              { 0, 1, 1, 1 } };

    resolveLabirinto(labirinto1);
    printf("\n");
    
    resolveLabirinto(labirinto2);
    printf("\n");
    
    resolveLabirinto(labirinto3);
    printf("\n");
    
    resolveLabirinto(labirinto4);
    printf("\n");
    
    resolveLabirinto(labirinto5);
    
    return 0;
}

