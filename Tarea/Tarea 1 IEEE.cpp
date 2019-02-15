//Tarea 1 Estandar IEEE-754

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>

void voltear(int cad[], int i, int j){
	
	int temp;
	while (i < j) 
   {
      temp = cad[i];
      cad[i] = cad[j];
      cad[j] = temp;
      i++;             
      j--;         
   }
}


void realBinario(){
	float n, f;
	float res;
	int bin[18], bin2[18], expbin[18];
	int x=0,y=0,z=0,d=0, k, exp;
	
	printf("Coloca el numero que quieres en binario: ");
	scanf("%f", &n);
	
	f= n-floor(n);
	n= n-f;
	
	if(n<0){
		n=n*(-1);
		k=1;
	}
	else{
		k=0;
	}
	
	for(int i=0; n!=0; i++){
		bin[i]=fmod(n,2);
		n=(int) n/2;
		//printf("%d , %f\n", bin[i],n);
		x++;
	}
	//printf("-------------------------------------\n");
	for(int i=0; i<10; i++){
		res=f*2;
		f=res-floor(res);
		bin2[i]=res-f;
		//printf("%d , %f\n", bin2[i], res);
		y++;
	}
	
	
	voltear(bin,0,x-1);
	voltear(bin2,0,y-1);
	
	printf("\n");
	printf("Tu numero en binario es: ");
	for(int i=0; i<x; i++){
		printf("%d", bin[i]);
	}
	printf(".");
	for(int i=0; i<y; i++){
		printf("%d", bin2[i]);
	}
	
	exp=(x-1)+127;
	
	for(int i=0; exp!=0; i++){
		expbin[i]=fmod(exp,2);
		exp= (int) exp/2;
		//printf("\n%d , %d", expbin[i], exp);
		z++;
	}
	
	voltear(expbin,0,z-1);
	printf("\n");
	printf("\nEstandar IEEE-754: ");
	printf("\n1bit(+/-) | 8bits(exponente) | 23bits(matisa)");
	printf("\n %d | ", k);
	for(int i=0; i<z; i++){
		printf("%d", expbin[i]);
	}
	printf(" | ");
	for(int i=1; i<x; i++){
		printf("%d", bin[i]);
	}
	for(int i=0; i<y; i++){
		printf("%d", bin2[i]);
	}
	
	getch();
}

void IEEE(){
	int exp[18], mat[23], ent[23], dec[23];
	int d=0, k, j=0, n, a=1;
	float c=0, b=0, x;
	
	printf("Coloca el Estandar IEEE-754:\n");
	printf("\n");
	printf("Quieres que sea negativo o positivo?\n");
	printf("Positivo 0 , Negativo 1: ");
	scanf("%d", &k);
	
	printf("\n");
	printf("Escribe el exponente dijito por dijito: \n");
	for(int i=0; i<8; i++){
		scanf("%d", &exp[i]);
	}
		
	printf("\nEscribe la matiza: ");
	for(int i=0; i<23; i++){
		scanf("%d", &mat[i]);
	}
	
	printf("\nEstandar IEEE-754: ");
	printf("\n1bit(+/-) | 8bits(exponente) | 23bits(matisa)");
	printf("\n %d | ", k);
	for(int i=0; i<8; i++){
		printf("%d", exp[i]);
	}
	printf(" | ");
	for(int i=1; i<23; i++){
		printf("%d", mat[i]);
	}
	
	printf("\n");
	for(int i=0; i<8; i++){
		d=exp[i]+(2*d);
		//printf("\nd=%d", d);
	}
	
	n=d-127;
	
	for(int i=0; i<n+1; i++){
		ent[i]=mat[i];
	}
	for(int i=(n+1); i<23; i++){
		dec[j]=mat[i];
		j++;
	}
	
	printf("\nTu numero en binario es: \n");
	for(int i=0; i<n+1; i++){
		printf("%d", ent[i]);
	}
	printf(".");
	for(int i=0; i<j; i++){
		printf("%d", dec[i]);
	}
	
	for(int i=0; i<8; i++){
		b=ent[i]+(2*b);
		//printf("\nb=%f", b);
	}
	for(int i=0; i<j; i++){
		c=(dec[i]*pow(0.5,a))+c;
		//printf("\nc=%f", c);
		a++;
	}
	
	x=b+c;
	printf("\n");
	if(k==1){
		x=x*(-1);
		printf("\nTu numero decimal es: %f", x);
	}
	if(k==0){
		printf("\nTu numero decimal es: %f", x);
	}
	
	getch();
}

main(){
	
	int opcion;
	
	do{
		system("cls");
		printf("-------------------------------------\n");
		printf("-------------------------------------\n");
		printf("            1.- Real a Estandar\n");
		printf("            2.- Estandar IEEE-754 a Real\n");
		printf("            3.- Salir\n");
		printf("-------------------------------------\n");
		printf("-------------------------------------\n");
		printf("     ELIGE UNA OPCION: ");
		scanf("%d", &opcion);
		switch(opcion){
			
			case 1: realBinario();
					break;
			case 2: IEEE();
					break;
		}
	}while(opcion!=3);
}
