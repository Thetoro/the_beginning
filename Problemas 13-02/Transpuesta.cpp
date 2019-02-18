// Ejercicio 1 Transpuesta

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

int i,j;

int rdtsc(){
	__asm__ __volatile__("rdtsc");

}

int random(int min, int max){
	int num;
	srand(rdtsc());

	num= min + rand() % max;
	return num;
}

void voltMatriz(int A[i][j]){
    int x, y;
    for(x=0; x<i; x++){
            printf("\n");
        for(y=0; y<j; y++){
            printf(" %d ", A[y][x]);
        }
	}
}

void crearMatriz(int M[i][j]){
	int x, y;

	for(x=0; x<i; x++){
            printf("\n");
        for(y=0; y<j; y++){
            M[x][y]=random(0,10);
            printf(" %d ", M[x][y]);
        }
	}
	printf("\nLa matriz transpuesta es: ");
	voltMatriz(M);
}

main(){
    int matriz[i][j];

    printf("De que tamaño quieres la cadena?\n");
	printf("x= ");
	scanf("%d", &i);
	printf("y= ");
	scanf("%d", &j);

	crearMatriz(matriz);
}
