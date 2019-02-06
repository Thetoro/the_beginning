//Ejercicio Arreglos 1

#include <stdio.h>

main(){
	int A[5];
	int i=0;
	
	for(int j=0; j< 5; j++){
		scanf("%d", &i);
		if( i>0){
			scanf("%d", &A[j]);
		}
		else{
			printf("-");
		}
	}
		
	for(int j=0; j<5; j++){
		printf("%d", A[j]);
	}
}
