#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void insertarPrimero(Nodo** cabeza, int entrada){
    Nodo *nuevo;
    nuevo = crearNodo(entrada);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

void insertarUltimo(Nodo** cabeza, int entrada){
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

void insertar(Nodo** cabeza, int entrada){
	Nodo *nuevo, *despues, *p;

	nuevo =crearNodo(entrada);
	if(*cabeza == NULL){
		*cabeza = nuevo;
	}
	else if(entrada < (*cabeza)->dato){
        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
	}
	else{
		despues = p =*cabeza;
		while((despues != NULL) && despues->dato<entrada){
            p = despues;
            despues = despues->siguiente;
		}
		if(entrada > p->dato){
            despues = p;
		}
		nuevo->siguiente = despues->siguiente;
		despues->siguiente = nuevo;

	}

}

main(){
    int d=1;
    Nodo *cabeza, *ptr;
    int k;

    cabeza = NULL;

    while(d != 0){
        insertar(&cabeza, d);
        printf("Dame un valor diferente de 0: ");
        scanf("%d", &d);
    }

    for( ptr = cabeza; ptr;){
        printf("%d|", ptr->dato);
        ptr = ptr->siguiente;
    }
    printf("\n\n");

}
