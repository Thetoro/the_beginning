//algoritmos de ordenacion

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
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

void burbuja(){ 
	char num[10];
	int temp;
	
	for(int i=0; i<10; i++){
		num[i] = random(0,9);
		printf("%d", num[i]);
	}
	
	for(int i=0; i<10; i++){
		for(int j=0; j<9; j++){
			if(num[j]>num[j+1]){
				temp = num[j];
				num[j] = num[j+1];
				num[j+1] = temp;
			}
		}
	}
	
	printf("\n");
	
	for(int i=0; i<10; i++){
		printf("%d", num[i]);
	}
}

void insert(){
	char num[10], j;
	int temp;
	
	for(int i=0; i<10; i++){
		num[i] = random(0,9);
		printf("%d", num[i]);
	}
	

	for(int i=1; i<10; i++){
		temp = num[i];
		j = i-1;
		
		while(num[j]>temp){
			num[j+1] = num[j];
			j--;
		}
		num[j+1] = temp;
	
	}
	
	printf("\n");
	for(int i=0; i<10; i++){
		printf("%d", num[i]);
	}
}

void selection(){
	char num[10];
	int temp, min;
	
	for(int i=0; i<10; i++){
		num[i] = random(0,9);
		printf("%d", num[i]);
	}
	
	for(int i=0; i<9; i++){
		min = i;
		for(int j= i+1; j<10; j++){
			if(num[j]<num[min]){
				min = j;
			}
		}
		temp = num[min];
		num[min] = num[i];
		num[i] = temp;
	}
	
	printf("\n");
	for(int i=0; i<10; i++){
		printf("%d", num[i]);
	}
}

main(){
	printf("Bubble sort\n");
	burbuja();
	printf("\n");
	printf("\nInsert sort\n");
	insert();
	printf("\n");
	printf("\nSelection sort\n");
	selection();
}
