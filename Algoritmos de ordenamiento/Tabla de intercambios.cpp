//Tabla de intercambios.

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

	
int burbuja(){ 
	int temp, a=0;
	char num[10]= {3,5,9,4,7,8,2,1,0,6};
	
	for(int i=0; i<10; i++){
		for(int j=0; j<9; j++){
			if(num[j]>num[j+1]){
				temp = num[j];
				num[j] = num[j+1];
				num[j+1] = temp;
				a++;
			}
		}
	}
	
	return a;
}

int insert(){
	char  j;
	int temp, a=0;
	char num[10]= {3,5,9,4,7,8,2,1,0,6};
	
	for(int i=1; i<10; i++){
		temp = num[i];
		j = i-1;
		
		while(num[j]>temp){
			num[j+1] = num[j];
			j--;
			a++;
		}
		num[j+1] = temp;
	}
	
	
	return a;
}

int selection(){
	int temp, min, a=0;
	char num[10]= {3,5,9,4,7,8,2,1,0,6};
	
	for(int i=0; i<9; i++){
		min = i;
		for(int j= i+1; j<10; j++){
			if(num[j]<num[min]){
				min = j;
				a++;	
			}
		}
		temp = num[min];
		num[min] = num[i];
		num[i] = temp;
		
	}
	
	return a;
}

int shell(){
    int x, i, j, k, temp, a=0;
    int inter = 10/2;
	char num[10]= {3,5,9,4,7,8,2,1,0,6};

   while(inter>0){
        for(i=inter+1; i<10;i++){
            j= i-inter;
            while(j>=0){
                k=j+inter;
                if(num[j]<=num[k]){
                    j=-1;
                }
                else{
                    temp = num[j];
                    num[j] = num[k];
                    num[k] = temp;
                    i = j-inter;
                    a++;
                }
            }
        }
        inter = inter/2;
    }

    
    return a;
}

main(){
	int b, i, se, sh;
	char num[10]= {3,5,9,4,7,8,2,1,0,6};
	
	b = burbuja();
	i = insert();
	se = selection();
	sh = shell();
	
	printf("El arreglo usado fue: ");
	for(int j=0; j<10; j++){
		printf("%d", num[j]);
	}
	printf("\n");
	printf("Burbuja:   %d\n", b);
	printf("Insertion: %d\n", i);
	printf("Selection: %d\n", se);
	printf("Shell:     %d", sh);
	
}

