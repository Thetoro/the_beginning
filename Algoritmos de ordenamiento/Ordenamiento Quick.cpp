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

void quick(int a[], int i, int n){
    int pivote, x, temp, j=n-1;

    pivote = random(0,n);

    printf("\nPivote: %d", a[pivote]);

    do{
        while(a[i]<a[pivote]){
            i++;
        }
        while(a[j]>a[pivote]){
            j--;
        }
        if(i<=j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            printf("---%d , %d", a[i], a[j]);
            i++;
            j--;
        }

    printf("\n");
    for(x=0; x<n; x++){
        printf("%d-", a[x]);
    }

    }while(i<=j);

    if(i==j){
        temp = a[i];
        a[i] = a[pivote];
        a[pivote] = a[i];
        printf("---%d , piv: %d", a[i], a[pivote]);
    }

    if(0<j){
        quick(a,0,pivote);
    }
    if(n>i){
        quick(a,pivote,n);
    }

}

main(){
    int n, x, j, pivote;

    printf("Tama%co del arreglo: ",164);
    scanf("%d", &n);

    int a[n];

    for(x=0; x<n; x++){
        a[x]=random(0,9);
        printf("%d", a[x]);
    }

    j=n-1;

    quick(a, 0, n);
}
