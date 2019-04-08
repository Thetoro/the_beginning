#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

int d=0;

typedef struct Agenda{
    int id;
    char nombre[30];
    char apellido[30];
    int edad;
    int telefono;
};

enum boolean{
    false,true
};

typedef struct Nodo{
    struct Agenda datos;
    struct Nodo *siguiente;
}Nodo;

Nodo* crearNodo(struct Agenda x){
    Nodo *p;
    p = (Nodo*)malloc(sizeof(Nodo));
    p-> datos = x;
    p->siguiente=NULL;
    return p;
}

int verificaLista(Nodo** cabeza){
    Nodo *ultimo;
    ultimo = *cabeza;
    if(ultimo == NULL){
        return false;
    }
    else{
        return true;
    }
}

void insertarPrimero(Nodo** cabeza, struct Agenda dato){
    Nodo *nuevo;
    nuevo = crearNodo(dato);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

/*void insertarUltimo(Nodo** cabeza, int entrada){
    Nodo *ultimo;
    ultimo = *cabeza;
    if(ultimo == NULL){
        *cabeza = crearNodo(entrada);
    }
    else{
        while(ultimo->siguiente){
            ultimo = ultimo->siguiente;
        }
        ultimo->siguiente = crearNodo(entrada);
    }
}

void insertar(Nodo** cabeza, int testigo, int entrada){
	Nodo *nuevo, *despues;

	nuevo =crearNodo(entrada);
	if(*cabeza == NULL){
		*cabeza = nuevo;
	}
	else{
		int encontrado = 0;
		despues = *cabeza;
		while((despues != NULL) && encontrado==0){
			if(despues -> dato != testigo){
				despues = despues ->siguiente;
			}
			else
				encontrado = 1;
		}

		if(encontrado==1)
        {
            nuevo -> siguiente = despues->siguiente;
            despues ->siguiente = nuevo;
        }
        else{
            insertarPrimero(cabeza, entrada);
            printf("No se encontro el elemento y fue colocado al principio\n");
        }
	}

}*/

void eliminar (Nodo** cabeza, int entrada){
	Nodo* actual, *anterior;
	int encontrado=0;

	//printf("Entre!!\n");

	actual = *cabeza; anterior = NULL;
	while((actual != NULL) && (encontrado==0)){
		if(actual->datos.id == entrada){
            encontrado=1;
		}
		if(encontrado==0){
			anterior = actual;
			actual = actual-> siguiente;
		}
		/*printf("%d\t", actual->dato);
		printf("%d\n", anterior->dato);*/
	}
	if(actual == NULL){
        printf("NO SE ENCONTRO EL ID\n");
	}
	if(actual != NULL){
		if(actual == *cabeza){
			*cabeza  = actual ->siguiente;
		}
		else{
			anterior-> siguiente =actual ->siguiente;
			printf("OBJETIVO ELIMINADO\n");
		}
	}

	free(actual);
	getch();
}

/*void localizar(Nodo** cabeza, int testigo){
    Nodo *despues;

    if(*cabeza == NULL){
		printf("Se encontro el elemento %d\n", testigo);
	}
	else{
        int encontrado = 0;
		despues = *cabeza;
		while((despues != NULL) && encontrado==0){
			if(despues -> dato != testigo){
				despues = despues ->siguiente;
			}
			else
				encontrado = 1;
		}

		if(encontrado==1)
        {
            printf("Se encontro el elemento %d\n", testigo);
        }
        else{
            printf("No se encontro el elemento %d\n", testigo);
        }
	}
}*/

void imprimirDatos(Nodo* cabeza){
    int i, j;
    Nodo* ptr;
    for(ptr = cabeza; ptr;){
        printf("id: %d\n", ptr->datos.id);
        printf("Nombre: ");
        for(i=0; i<strlen(ptr->datos.nombre);i++){
            printf("%c", ptr->datos.nombre[i]);
        }
        printf("\n");
        printf("Apellido: ");
        for(j=0; j<strlen(ptr->datos.apellido);j++){
            printf("%c", ptr->datos.apellido[j]);
        }
        printf("\n");
        printf("Edad: %d\n", ptr->datos.edad);
        printf("Num. Telefono: %d\n", ptr->datos.telefono);

        ptr = ptr->siguiente;
    }

    getch();
}

void insertarDatos(Nodo** cabeza){
    struct Agenda n;

    fflush(stdin);
    printf("Dame un nombre: ");
    gets(n.nombre);
    fflush(stdin);
    printf("Dame un apellido: ");
    gets(n.apellido);
    fflush(stdin);
    printf("Dame la edad: ");
    scanf("%d", &n.edad);
    printf("Dame el numero de telefono: ");
    scanf("%d", &n.telefono);
    n.id = d;

    insertarPrimero(cabeza, n);
    fflush(stdin);

}

main(){
    Nodo *cabeza, *ptr;
    int opcion, i;

	cabeza = NULL;

	do{
		system("cls");
		printf("-------------------------------------\n");
		printf("-------------------------------------\n");
		printf("            1.- Insertar Datos\n");
		printf("            2.- Mostrar\n");
		printf("            3.- Eliminar\n");
		/*printf("            4.- Consultar\n");
		printf("            5.- Listado\n");
		printf("            6.- Salir\n");*/
		printf("-------------------------------------\n");
		printf("-------------------------------------\n");
		printf("     ELIGE UNA OPCION: ");
		scanf("%d", &opcion);
		switch(opcion){

			case 1: insertarDatos(&cabeza);
                    d++;
					break;
			case 2: imprimirDatos(cabeza);
					break;
			case 3: printf("Dame el id: ");
                    scanf("%d", &i);
                    eliminar(&cabeza, i);
					break;
			/*case 4: Consultar();
					break;
			case 5: Listado();
					break;*/
		}
	}while(opcion!=4);

}
