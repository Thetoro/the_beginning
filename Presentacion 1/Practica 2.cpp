//Practica 2 Palindromo

#include <stdio.h>
#include <string.h>

void Palindromo(char* c){
	int tam;
	char *p1, *p2;
	
	tam= strlen(c);
	
	p1=c;
	
	while(*p1!= NULL){
		p1++;
	}
	p1--;
	
	for(int i=0; i<tam; i++){
		if(*p1==*p2){
			p1--;
			p2++;
		}
		else{
			break;
		}
	}
	if(p2>p1){
		printf("SI es palindromo");
	}
	else{
		printf("NO es palindromo");
	}
}

main(){
	char c[]="anitalavalatina";
	
	printf("%s\n", c);
	Palindromo(c);
	
	
}
