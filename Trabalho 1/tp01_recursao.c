 // TRABALHO 1 DE ALGORITMOS E ESTRUTURAS DE DADOS 1
//Informaçõeses do estudante
// Nome: João Pedro Pereira
// Curso: BCC
// RA: 769714

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromoR(int i, int f, char *s)
{
	if(i >= f) {
		
		return 1;
	}
	else if(s[i] != s[f]) {
		
		return 0;
	}
	
	
    
    return palindromoR(i + 1, f - 1, s);
}

void palindromo(char *s)
{
    int saida = palindromoR(0, strlen(s) - 1, s);

    printf("\"");
    printf("%s", s);
    printf("\" ");

    if (saida)
    {
        printf("eh palindromo\n");
    }
    else
    {
        printf("nao eh palindromo\n");
    }
}

void inversaR(char *str)
{

	if(*str != '\0') {
		(inversaR(str + 1));
		printf("%c", *str);
	}
	 		
	

}
void inversa(char *s)
{
    printf("inversa de \"");
    printf("%s", s);
    printf("\" = ");

    inversaR(s);

    printf("\n");
}

int fibonacciR(int n)
{
    int resultado = 0;
    
    if (n == 0) {
    	return 0;
	}else if (n == 1) {
		return 1;
	}
	return resultado = fibonacciR(n - 1) + fibonacciR(n - 2);
 	
    
}

void fibonacci(int n)
{
    int i;

    printf("%d primeiros numeros de fibonacci = ", n);
    for (i = 0; i < n; i++)
        printf("%d ", fibonacciR(i));

    printf("\n");
}

int pisoLogR(int x)
{
    int cont = 0;
    
    if(x == 1) {
    	return 0;
    }
    cont += 1;
    
    return cont += pisoLogR(x / 2);
    
}

 

void pisoLog(int x)
{
    int valor = 0;
    printf("piso de log base 2 de %d = ", x);
    valor = pisoLogR(x);
    printf("%d\n", valor);
}

int main(int argc, char *argv[])
{
    int t;

    scanf("%d", &t);

    if (t < 1 || t > 4)
    {
        printf("Parametros incorretos.\n");
        printf("Ex:\n");
        printf("tp01_recursao 1 [para testar palindromo]\n");
        printf("tp01_recursao 2 [para testar inversa]\n");
        printf("tp01_recursao 3 [para testar fibonacci]\n");
        printf("tp01_recursao 4 [para testar pisoLog]\n");
    }

    if (t == 1)
    {
        printf("\nTestando palindromo()\n\n");
        palindromo("");
        palindromo("1");
        palindromo("77");
        palindromo("505");
        palindromo("1111");
        palindromo("2112");
        palindromo("369963");
        palindromo("10101");
        palindromo("1001001");
        palindromo("12");
        palindromo("12451");
        palindromo("100011");
    }
    else if (t == 2)
    {
        printf("\nTestando inversa()\n\n");
        inversaR("");
        inversa("ab");
        inversa("gato");
        inversa("minerva");
    }
    else if (t == 3)
    {
        printf("\nTestando fibonacci()\n\n");
        fibonacci(0);
        fibonacci(1);
        fibonacci(2);
        fibonacci(4);
        fibonacci(10);
    }
    else if (t == 4)
    {
        printf("\nTestando pisoLog()\n\n");
        pisoLog(1);
        pisoLog(2);
        pisoLog(3);
        pisoLog(4);
        pisoLog(5);
        pisoLog(15);
        pisoLog(16);
        pisoLog(17);
        pisoLog(127);
        pisoLog(256);
        pisoLog(511);
        pisoLog(512);
    }

    return 0;
}
