//Ejercicio 2 Mayor y menor elemento de una matriz

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

main(){
	int x, y, n, d=0, k=0, m=10, posx, posy, a=0, posx2,posy2;
	int matriz[i][j];
	
    printf("De que tamaño quieres la cadena?");
	printf("\nx= ");
	scanf("%d", &i);
	printf("y= ");
	scanf("%d", &j);
	
	for(x=0; x<i; x++){
            printf("\n");
        for(y=0; y<j; y++){
            matriz[x][y]=random(0,10);
            printf(" %d ", matriz[x][y]);
            n=matriz[x][y];
            if(n>d){
            	d=n;
            	if(n==d){
            		k++;
					posx=y;
            		posy=x;
				}
			}
			if(n<m){
				m=n;
				if(n==m){
					a++;
					posx2=y;
					posy2=x;
				}
			}
        }
	}
	
	printf("\n");
	printf("\nEl numero mas grande es: %d", d);
	printf("\nLa posicion es (%d,%d).", posx+1,posy+1);
	printf("\nAparece %d veces.", k);
	printf("\n");
	printf("\nEl numero mas pequeño es: %d", m);
	printf("\nLa posicion es (%d,%d).", posx2+1,posy2+1);
	printf("\nAparece %d veces.", a);
}
