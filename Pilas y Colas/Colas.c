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
	Nodo* actual, *anterior, *antes;

	actual = *cabeza;
	while(actual != NULL){
            antes = anterior;
			anterior = actual;
			actual = actual-> siguiente;
	}
	antes -> siguiente = NULL;
	free(anterior);
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
		printf("tama%co de la Cola %d\n", 164, cont);
		//getch();
	}
	else{
        despues = *cabeza;
		while(despues != NULL){
				despues = despues ->siguiente;
				cont++;
        }
        printf("tama%co de la Cola %d\n", 164, cont);
        //getch();
	}
}

void frente(Nodo** cabeza){
    Nodo *despues, *anterior;

    if(*cabeza == NULL){
		printf("No hay Elementos\n");
		//getch();
	}
	else{
        despues = *cabeza;
        while(despues != NULL){
                anterior = despues;
            despues = despues ->siguiente;
        }
        printf("El elemento del Frente es %d\n", *anterior);
        //getch();
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
    tamanoLista(&cabeza);
    if(verificaLista(&cabeza)== false){
        printf("COLA VACIA\n");
    }
    if(verificaLista(&cabeza)== true){
        printf("COLA NO VACIA\n");
    }

    frente(&cabeza);

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
    printf("\n\n");
}
