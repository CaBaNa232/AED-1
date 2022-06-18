// TRABALHO 2 DE ALGORITMOS E ESTRUTURAS DE DADOS 1
//Informações do estudante
// Nome: João Pedro Pereira
// Curso: BCC
// RA: 769714

#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa Pessoa;
struct pessoa
{
    int posicao;
    Pessoa *prox;
};

/* lista inicialmente vazia */
Pessoa *inicio = NULL;
Pessoa *finalLista = NULL;
//DECLARAR MAIS VARIAVEIS GLOBAIS SE NECESSARIO

void *mallocsafe(unsigned tam)
{
    void *p;
    p = malloc(tam);
    if (p == NULL)
    {
        printf("Deu ruim! malloc() falou\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

void insereLista( int pos); 
void removeLista( Pessoa * p); 
void imprimeLista ();
int resolveJosephus( int n, int m);


int main()
{
    int nroexecs;

    scanf("%d", &nroexecs);
    int *n = malloc(nroexecs * sizeof(int));
    int *m = malloc(nroexecs * sizeof(int));
	int i;
    for (i = 0; i < nroexecs; i++)
    {
        scanf("%d", &n[i]);
        scanf("%d", &m[i]);
    }

    inicio = NULL; // inicializa a lista como vazia

    //INICIALIZAR OUTRAS VARIAVEIS GLOBAIS SE NECESSARIO

    for (i = 0; i < nroexecs; i++)
    {
        printf("Usando n=%d, m=%d, resultado=%d\n", n[i], m[i], resolveJosephus(n[i], m[i]));
    }

    return 0;
}

/* Insere no fim da lista */
void insereLista(int pos)
{
	Pessoa *nova; //Ponteiro auxiliar do tipo Pessoa
	
	nova = (Pessoa *)mallocsafe(sizeof(Pessoa)); //Alocando dinâmicamente
	nova->posicao = pos; //Posição de nova recebe nova posição
	
	if(inicio == NULL){ //Não há elementos na lista
		inicio = nova; //aux recebe o inicio da lista
	}else{
		finalLista->prox = nova;
	}
	nova->prox = inicio; //Nova aponta para o inicio, dando uma volta na lista
	finalLista = nova; //Aponta para o final da lista
	
}


/* Remove o elemento imediatamente após o elemento p presente na lista */
/* Supõe que a lista tem pelo menos dois elementos */
void removeLista(Pessoa *p)
{
   Pessoa * remove; //Ponteiro remove do tipo Pessoa
   remove = p->prox; //Salvando o nó seguinte ao nó que será removido
   
   p->prox = p->prox->prox; //Aponta para o nó seguinte
   free(remove); //Desalocando remove
   remove = NULL; //remove aponta para NULL


}

/* Imprime cada elemento dentro da lista */
void imprimeLista()
{
  Pessoa *imprime; //Ponteiro auxiliar do tipo Pessoa
  imprime = inicio; //Imprime recebe o inicio da lista
  
  while(imprime->prox != inicio){ //Enquanto não percorrer a lista toda
      printf("%d\n", imprime->posicao); //Imprime a posição
      imprime = imprime->prox; //Aponta para o proximo nó da lista
  }
  printf("%d\n", imprime->posicao); //Imprime a posição
}


int resolveJosephus(int n, int m) {
	
	inicio = NULL;
	finalLista = NULL; 
	int i, contador = n; 
	Pessoa *matador, *antecessor, *sobrevivente; //Ponteiro auxiliar do tipo Pessoa
  	
  	for(i = 1; i <= n; i++) {
		insereLista(i); //Chama a função insereLista n vezes
	}
  	
	if(n == 1) { //Se tiver só uma pessoa, a posição segura é ela mesma
  		return n;
  	}
	else {
		while(contador > 1) { //Enquanto não restar 1 sobrevivente
			if(contador == n) { // Testando é a primeira volta da lista
				matador	= inicio; //"Matador" é o primeiro nó da lista
				antecessor = matador; //Recebe quem "matou"
				for(i = 1; i < m; i++) {
					antecessor = antecessor->prox; //Encerra a execução uma pessoa antes de que irá "morrer"
				}
				if(matador == antecessor->prox){ //Verificando se o "matador" é a pessoa que morre
					antecessor = antecessor->prox; //Encerra a execução uma pessoa antes de que irá "morrer"
				}
				removeLista(antecessor); 
				contador--; //Decrementa o número de vivos
			}
			else{
				matador = antecessor->prox; //Se uma volta foi dada, quem "mata" é o próximo de quem morreu
				antecessor = matador; 
			
				for(i = 1; i < m; i++) {
					antecessor = antecessor->prox; 
				}
				if(matador == antecessor->prox){ 
					antecessor = antecessor->prox; 
				}
				removeLista(antecessor);
				contador--; //Decrementa o numero de vivos
			}
	 	}
	}
	sobrevivente = matador; //Posição segura
	return sobrevivente->posicao;
  }
  
