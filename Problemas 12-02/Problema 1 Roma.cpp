//Problema 1 Romano a Arabigo

#include <stdio.h>
#include <string.h>

int conv(char a[]){
	int tem[10];
	int j=0, tam;
	tam=strlen(a);
	
	for(int i=0; i<tam; i++){
		if(a[i]=='M'){
			tem[i]=1000;
		}
		if(a[i]=='D'){
			tem[i]=500;
		}
		if(a[i]=='C'){
			tem[i]=100;
		}
		if(a[i]=='L'){
			tem[i]=50;
		}
		if(a[i]=='X'){
			tem[i]=10;
		}
		if(a[i]=='V'){
			tem[i]=5;
		}
		if(a[i]=='I'){
			tem[i]=1;
		}
	}
	
	for(int i=0; i<tam; i++){
		if(tem[i+1]<tem[i] || tem[i+1]==tem[i]){
			j=j+tem[i];
		}
		if(tem[i+1]>tem[i]){
			j=j-tem[i];
		}
	}
	
	return j;
}

main(){
	char a[10];
	int j;
	
	printf("Coloca un numero en romano: ");
	gets(a);
	
	j=conv(a);
	
	printf("%d", j);
}
