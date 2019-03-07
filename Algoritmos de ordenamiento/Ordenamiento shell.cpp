//Shell

#include <stdio.h>
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

intercambio(int x,int y){
    int temp;

    temp = x;
    x = y;
    y = temp;
}

void shell(int n){
    int num[n];
    int x, i, j, k, temp, a=0;
    int inter = n/2;

    for(x=0; x<n; x++){
        num[x]=random(0,9);
        printf("%d", num[x]);
    }

   while(inter>0){
        for(i=inter+1; i<n;i++){
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

    printf("\n");
    for(x=0; x<n; x++){
    printf("%d", num[x]);
    }
    printf("\n%d", a);
}

main(){
    int n;

    printf("Dame el tama%co del arreglo: ",164);
    scanf("%d", &n);

    shell(n);
}
