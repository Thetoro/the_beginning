//Estructuras y apuntadores

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

struct fechaRegistro{
	unsigned int dia;
	unsigned int mes;
	unsigned int anio;
};

struct producto{
	char nombre[30];
	char desarrolladora[30];
	char categoria[20];
	char clasificaion;
	fechaRegistro fecha;
	float precio;
};

int items=0;
producto juego[10];
void Altas(){
	
	char resp;
	
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
	
	do{
		printf("El total de productos es de %d\n", items);
		fflush(stdin);
		
		printf("Registra el titulo del juego: ");
		gets(juego[items].nombre);
		fflush(stdin);
		
		printf("Compa%cia desarrolladora: ",164);
		gets(juego[items].desarrolladora);
		fflush(stdin);
		
		printf("Categoria: ");
		gets(juego[items].categoria);
		fflush(stdin);
		
		printf("Clasificaci%cn: ",162);
		scanf("%c", &juego[items].clasificaion);
		fflush(stdin);
		
		printf("Precio: ");
		scanf("%f", &juego[items].precio);
		fflush(stdin);
		
		juego[items].fecha.anio = tm.tm_year+1900;
        juego[items].fecha.mes = tm.tm_mon + 1;
        juego[items].fecha.dia = tm.tm_mday;
		
		printf("Desea continuar registrando juegos? (s/n): ");
		scanf("%c", &resp);
		fflush(stdin);
		
			items++;
		
		printf("--------------------------------------------\n");
	}while(resp == 's');
	
	system("cls");
}

void Listado(){
	system("cls");
	printf("---------------PRODUCTOS REGISTRADOS---------------\n");
	printf("\n");
	
	for(int i=0; i<items; i++){
		printf("Titulo: %s\n", juego[i].nombre);
		printf("Compa%cia desarrolladora: %s\n", 164, juego[i].desarrolladora);
		printf("Categoria: %s\n", juego[i].categoria);
		printf("Clasificaci%cn: %c\n",162, juego[i].clasificaion);
		printf("Precio: %f\n",juego[i].precio);
		printf("\n");
		printf("La fecha de registro fue %d/%d/%d\n", juego[i].fecha.dia, juego[i].fecha.mes, juego[i].fecha.anio);
		printf("--------------------------------------------------\n");
	}
	
	getch();
}

main(){
	int opcion;
	
	do{
		system("cls");
		printf("-------------------------------------\n");
		printf("-------------------------------------\n");
		printf("            1.- Agregar producto\n");
		printf("            2.- Listado de productos\n");
		printf("            3.- Salir\n");
		printf("-------------------------------------\n");
		printf("-------------------------------------\n");
		printf("     ELIGE UNA OPCION: ");
		scanf("%d", &opcion);
		switch(opcion){
			
			case 1: Altas();
					break;
			case 2: Listado();
					break;
		}
	}while(opcion!=3);
}
