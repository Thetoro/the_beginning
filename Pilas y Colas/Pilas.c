#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define false 1
#define true 0

typedef struct Elemento{
    int dato;
    struct Elemento* siguiente;
}Nodo;

Nodo* crearNodo(int x){
    Nodo *p;
    p = (Nodo*)malloc(sizeof(Nodo));
    p->dato=x;
    p->siguiente=NULL;
    return p;
}

void insertar(Nodo** cabeza, int entrada){
    Nodo *nuevo;
    nuevo = crearNodo(entrada);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

void eliminar (Nodo** cabeza){
	Nodo* actual, *anterior;
	int encontrado=0;

	actual = *cabeza; anterior = NULL;
	if(actual != NULL){
		if(actual == *cabeza){
			*cabeza  = actual ->siguiente;
		}
		else{
			anterior-> siguiente =actual ->siguiente;
		}
	}

	free(actual);
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

void tamanoLista(Nodo** cabeza){
    Nodo *despues;
    int cont = 0;

    if(*cabeza == NULL){
		printf("tama%co de la lista %d\n", 164, cont);
		getch();
	}
	else{
        despues = *cabeza;
		while(despues != NULL){
				despues = despues ->siguiente;
				cont++;
        }
        printf("tama%co de la lista %d\n", 164, cont);
        getch();
	}
}

void cima(Nodo** cabeza){
    Nodo *despues;

    if(*cabeza == NULL){
		printf("No hay Elementos\n");
		getch();
	}
	else{
        printf("El elemento de la cima es %d\n", **cabeza);
        getch();
	}
}


main(){
    int d=1;
    Nodo *cabeza, *ptr;
    int c,k,n;

    cabeza = NULL;

    int opcion;

	do{
		system("cls");
		printf("-------------------------------------\n");
		printf("-------------------------------------\n");
		printf("            1.- CrearPila\n");
		printf("            2.- Push\n");
		printf("            3.- Pop\n");
		printf("            4.- Verificar pila\n");
		printf("            5.- Cima\n");
		printf("            6.- Tama%co de la pila\n",164);
		printf("            7.- Salir\n");
		printf("LISTA: ");
		for( ptr = cabeza; ptr;){
            printf("%d|", ptr->dato);
            ptr = ptr->siguiente;
        }
        printf("\n");
		printf("-------------------------------------\n");
		printf("-------------------------------------\n");
		printf("     ELIGE UNA OPCION: ");
		scanf("%d", &opcion);
		switch(opcion){

			case 1: printf("Dame el tama%co de la pila: ", 164);
                    scanf("%d", &c);
                    for(k=0; k<c; k++){
                        printf("Dame un valor: ");
                        scanf("%d", &n);
                        insertar(&cabeza, n);
                    }
					break;
			case 2: printf("Dame un valor: ");
                    scanf("%d", &n);
                    insertar(&cabeza, n);
					break;
			case 3: eliminar(&cabeza);
					break;
			case 4: if(verificaLista(&cabeza)== false){
                        printf("PILA VACIA\n");
                        getch();
                    }
                    if(verificaLista(&cabeza)== true){
                        printf("PILA LLENA\n");
                        getch();
                    }
					break;
			case 5: cima(&cabeza);
					break;
            case 6: tamanoLista(&cabeza);
                    break;
		}
	}while(opcion!=7);

    /*while(d != 0){
        insertar(&cabeza, d);
        printf("Dame un valor diferente de 0: ");
        scanf("%d", &d);
    }
    tamanoLista(&cabeza);
    cima(&cabeza);
    if(verificaLista(&cabeza)== false){
        printf("LISTA VACIA\n");
    }
    if(verificaLista(&cabeza)== true){
        printf("LISTA NO VACIA\n");
    }

    for( ptr = cabeza; ptr;){
        printf("%d|", ptr->dato);
        ptr = ptr->siguiente;
    }
    printf("\n\n");

    eliminar(&cabeza);

    for( ptr = cabeza; ptr;){
        printf("%d|", ptr->dato);
        ptr = ptr->siguiente;
    }
    printf("\n\n");*/


}
