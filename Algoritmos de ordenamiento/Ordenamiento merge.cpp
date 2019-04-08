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

void merges(int a[], int inicio, int mitad, int fin){
    int temp[fin-inicio+1];
    int i=inicio, j=mitad+1, k=0;

    while(i<= mitad && j<=fin){
        if(a[i]<=a[j]){
            temp[k]=a[i];
            k++;
            i++;
        }
        else{
            temp[k]=a[j];
            k++;
            j++;
        }
    }
    for(i=inicio; i<=fin; i++){
        a[i]=temp[i-inicio];
    }
}

void mergeSort(int a[],int inicio, int fin){
    int x, n=10;
    if(inicio<fin){
        int mitad = (inicio+fin)/2;
        printf("mitad: %d\n", a[mitad]);
        mergeSort(a,inicio,mitad);
        mergeSort(a,mitad+1,fin);
        merges(a,inicio,mitad,fin);
        printf("\n");
    for(x=0; x<n; x++){
        printf("%d", a[x]);
    }
    }
}

main(){
    int x, n;

    printf("Tama%co del arreglo: ",164);
    scanf("%d", &n);

    int a[n];

    for(x=0; x<n; x++){
        a[x]=random(0,9);
        printf("%d", a[x]);
    }

    mergeSort(a, 0, n-1);

    printf("\n");
    for(x=0; x<n; x++){
        printf("%d", a[x]);
    }

}
