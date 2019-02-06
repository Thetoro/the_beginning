//Ejercicio Arreglos 2

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

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
	int muestra[10];
	int n, count=0;
	
	for(int i=0; i<10; i++){
		//n=random(0,50);
		//printf("%d\n", n);
			scanf("%d", &muestra[i]);
		
		if(muestra[i]>=5 && muestra[i]<=10){
			count++;
		}
	}
	printf("\nLa cantidad de numeros son: %d", count);
	/*for(int i=0; i<50; i++){
		printf("%d", muestra[i]);
	}*/
}
