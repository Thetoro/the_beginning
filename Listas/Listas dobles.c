#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct N{
    int dato;
    struct Nodo *delante;
    struct Nodo *atras;
}Nodo;

Nodo* crearNodo(int x){
    Nodo *p;
    p = (Nodo*)malloc(sizeof(Nodo));
    p->dato = x;
    p->delante = NULL;
    p->atras = NULL;
    return p;
}

void insertarDelante(Nodo** anterior, int entrada){
    Nodo *nuevo;
    nuevo = crearNodo(entrada);
    nuevo->delante = *anterior;
    nuevo->atras = NULL;
    /*if(*anterior != NULL){
        (*anterior)->atras = nuevo;
    }*/
    *anterior = nuevo;
}

void insertarAtras(Nodo** cabeza, int entrada){
    Nodo *nuevo;
    nuevo = crearNodo(entrada);
    nuevo->atras = *cabeza;
    nuevo->delante = NULL ;
    *cabeza = nuevo;
}

void insertar(Nodo** cabeza, int testigo, int entrada){
	Nodo *nuevo, *anterior, *p;

	nuevo =crearNodo(entrada);
	if(*cabeza == NULL){
		*cabeza = nuevo;
	}
	else{
		int encontrado = 0;
		anterior = *cabeza;
		while((anterior != NULL) && encontrado==0){
			if(anterior -> dato != testigo && p -> dato != NULL){
				anterior = anterior ->delante;
				p = anterior -> delante;
			}
			else
				encontrado = 1;
		}

		if(encontrado==1)
        {
            nuevo -> delante = anterior->delante;
            nuevo ->atras = anterior;
            anterior -> delante = nuevo;

            p = nuevo->delante;
            p->atras = nuevo;
        }
        else{
            insertarDelante(cabeza, entrada);
            printf("No se encontro el elemento y fue colocado al principio\n");
        }
	}

}

main(){
    int d=1;
    Nodo *cabeza, *ptr;
    int k;

    cabeza = NULL;

    while(d != 0){
        insertarDelante(&cabeza, d);
        printf("Dame un valor diferente de 0: ");
        scanf("%d", &d);
    }
    insertar(&cabeza, 5, 10);

    for( ptr = cabeza; ptr;){
        printf("%d|", ptr->dato);
        ptr = ptr->delante;
    }
    printf("\n\n");

}
