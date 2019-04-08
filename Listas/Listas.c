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

}

void eliminar (Nodo** cabeza, int entrada){
	Nodo* actual, *anterior;
	int encontrado=0;

	actual = *cabeza; anterior = NULL;
	while((actual != NULL) && (encontrado==0)){
		if(actual->dato == entrada){
            encontrado=1;
		}
		if(encontrado==0){
			anterior = actual;
			actual = actual-> siguiente;
		}
		/*printf("%d\t", actual->dato);
		printf("%d\n", anterior->dato);*/
	}
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

void localizar(Nodo** cabeza, int testigo){
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
	}
	else{
        despues = *cabeza;
		while(despues != NULL){
				despues = despues ->siguiente;
				cont++;
        }
        printf("tama%co de la lista %d\n", 164, cont);
	}
}

main(){
    int d=1;
    Nodo *cabeza, *ptr;
    int k;

    cabeza = NULL;

    while(d != 0){
        insertar(&cabeza, 5, d);
        printf("Dame un valor diferente de 0: ");
        scanf("%d", &d);
    }
    localizar(&cabeza, 9);
    eliminar(&cabeza, 10);
    tamanoLista(&cabeza);
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

}
