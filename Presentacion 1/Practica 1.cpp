//Practica 1 Palabra dentro de otra

#include <stdio.h>
#include <string.h>


int contarPalabra(char cad1[], char cad2[]){
	
	int	tam1= strlen(cad1);
	int	tam2= strlen(cad2);
	int count=0;
	
	for(int i=0; i<tam2-tam1; i++){
		int j;
		for(j=0; j<tam1; j++)
			if (cad2[i+j] != cad1[j]) 
                break; 
		if(j==tam1){
			count++;
			j=0;
		}
	}
	
	return count;
}

main(){
	char cad1[]= "aba";
	char cad2[]="abaababa";
	int n;
	
	printf("%s\n", cad1);
	printf("%s\n", cad2);
	n=contarPalabra(cad1,cad2);
	printf("%d", n);
}
