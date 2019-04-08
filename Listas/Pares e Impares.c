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

void localizar(Nodo** cabeza){
    Nodo *despues;
    Nodo *par, *impar, *ptr;

    par = impar = NULL;

    printf("ENTRE!!!\n");

    for(ptr = cabeza; ptr;){
        if(*cabeza == NULL){
            printf("No hay elementos\n");
        }
        else{
            int encontrado = 0;
            despues = *cabeza;
            while(despues != NULL){
                if(despues -> dato%2==0){
                    insertarPrimero(&par, despues->dato);
                    printf("ESTOY EN LA LISTA PAR!!!\n");
                }
                else{
                    insertarPrimero(&impar, despues -> dato);
                    printf("ESTOY EN LA LISTA IMPAR!!!\n");
                }
                despues = despues ->siguiente;
            }
        }
        ptr = ptr -> siguiente;
    }
        printf("\n");
    printf("Pares:\n");
    for( ptr = par; ptr;){
        printf("%d|", ptr->dato);
        ptr = ptr->siguiente;
    }
    printf("\n");
    printf("Impares:\n");
    for( ptr = impar; ptr;){
        printf("%d|", ptr->dato);
        ptr = ptr->siguiente;
    }
}

main(){
    int d=1;
    Nodo *cabeza, *par, *impar, *ptr;
    int k;

    cabeza = par = impar = NULL;
    while(d != 0){
        insertarPrimero(&cabeza, d);
        printf("Dame un valor diferente de 0: ");
        scanf("%d", &d);
    }
    localizar(&cabeza);
    printf("\n");
    printf("Lista\n");
    for( ptr = cabeza; ptr;){
        printf("%d|", ptr->dato);
        ptr = ptr->siguiente;
    }

    printf("\n\n");
}
