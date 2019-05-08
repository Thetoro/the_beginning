#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

int eliminar_pila (Nodo** cabeza){
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
	return actual -> dato;
	free(actual);
}

int eliminar_cola (Nodo** cabeza){
	Nodo* actual, *anterior, *antes;

	actual = *cabeza;
	while(actual != NULL){
            antes = anterior;
			anterior = actual;
			actual = actual-> siguiente;
	}
	antes -> siguiente = NULL;
	return anterior -> dato;
	free(anterior);
}

main(){
    int n, i, j, d, pila, cola;
    Nodo *cabeza_pila, *cabeza_cola, *ptr1, *ptr2;
    cabeza_pila = NULL;
    cabeza_cola = NULL;
    ptr1 = NULL;
    ptr2 = NULL;
    
    printf("NUMERO CAPICUA\n");
    printf("Cuantos DIGITOS quieres ingresar? ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Ingresa el digito: ");
        scanf("%d", &d);
        insertar(&cabeza_pila, d);
        insertar(&cabeza_cola, d);
    }
    printf("PILA\n");
    for( ptr1 = cabeza_pila; ptr1;){
        printf("%d|", ptr1->dato);
        ptr1 = ptr1->siguiente;
    }
    printf("\n\n");
    printf("COLA\n");
    for( ptr2 = cabeza_cola; ptr2;){
        printf("%d|", ptr2->dato);
        ptr2 = ptr2->siguiente;
    }
    printf("\n\n");
    
    int arr_pila[n], arr_cola[n];
    
    for(j=0; j<n; j++){
        pila = eliminar_pila(&cabeza_pila);
    	cola = eliminar_cola(&cabeza_cola);
    	arr_pila[j] = pila;
    	arr_cola[j] = cola;
    }
    
    if(strcmp(arr_pila,arr_cola)==0)
    	printf("SON IGUALES!!");
    else
    	printf("SON DIFERENTES!!");
}
