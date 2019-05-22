#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int dato;
	struct nodo *izdo, *dcho;
};

typedef struct nodo Nodo;

Nodo* crearNodo(int dato);
void insertar(Nodo** raiz, int dato);
void eliminar(Nodo** raiz, int dato);
void reemplazar(Nodo** intermedio);
void buscar(Nodo** raiz, int dato);
int profundidad(Nodo** raiz);
/*Tipos de recorrido*/
void preorden(Nodo* raiz);
void posorden(Nodo* raiz);
void enorden(Nodo* raiz);

main(){
	int nd, pro;
	int opcion=0;
	Nodo* raiz = NULL;
	do{
		printf("Ingrese un dato al arbol: ");
		scanf("%d",&nd);
		insertar(&raiz,nd);
		opcion++;
	}while(opcion != 10);
	printf("\n");
	pro = profundidad(&raiz);
	printf("Profundidad: %d\n", pro);
	preorden(raiz);
	printf("\n");
	eliminar(&raiz, 10);
	preorden(raiz);
	printf("\n");
	buscar(&raiz, 5);



}

Nodo* crearNodo(int dato){
	Nodo* h;
	h = (Nodo*)malloc(sizeof(Nodo));
	h->dato = dato;
	h->izdo= NULL;
	h->dcho = NULL;
	return h;
}

void insertar(Nodo** raiz, int dato){
	if(!(*raiz))
		*raiz = crearNodo(dato);
	else if(dato < (*raiz)->dato)
		insertar(&(*raiz)->izdo,dato);
	else
		insertar(&(*raiz)->dcho,dato);
}

void eliminar(Nodo** raiz, int dato){
	if(!(*raiz)){
		printf("El nodo no se encuentra");
	}
	else if(dato < (*raiz)->dato){
		eliminar(&(*raiz)->izdo,dato);
	}
	else if(dato > (*raiz)->dato){
		eliminar(&(*raiz)->dcho,dato);
	}
	else{
		Nodo* h;
		h  = (*raiz);
		if(h->izdo == NULL){
			(*raiz) = h->dcho;
		}
		else if(h->dcho == NULL){
			(*raiz) = h->dcho;
		}
		else{
			reemplazar(&h);
		}
		free(h);
	}
}

void reemplazar(Nodo** intermedio){
	Nodo* a, *p;
	p = *intermedio;
	a = (*intermedio)->izdo;
	while(a->dcho){
		p=a;
		a=a->dcho;
	}
	(*intermedio)-> dato = a ->dato;
	if(p == (*intermedio)){
		p->izdo = a-> izdo;
	}
	else{
		p->dcho = a->dcho;
	}
	(*intermedio) = a;
}

void buscar(Nodo** raiz, int dato){
    if(!(*raiz)){
		printf("El nodo no se encuentra");
	}
	else if(dato < (*raiz)->dato){
		buscar(&(*raiz)->izdo,dato);
	}
	else if(dato > (*raiz)->dato){
		buscar(&(*raiz)->dcho,dato);
	}
	if((*raiz)->dato==dato){
            printf("El numero %d se ha encontrado", (*raiz)->dato);
    }
}
int k=0, n=0, j=0;

int profundidad(Nodo** raiz){
    if(!(*raiz))
        return 0;
    else{
        int profundidadI = profundidad(&(*raiz) -> izdo);
        int profundidadD = profundidad(&(*raiz) -> dcho);
        if(profundidadI > profundidadD)
            return profundidadI + 1;
        else
            return profundidadD + 1;
    }
}

void preorden(Nodo* raiz){
	if(raiz){
		printf("%d ",raiz->dato);
		preorden(raiz->izdo);
		preorden(raiz->dcho);
	}
}

void posorden(Nodo* raiz){
	if(raiz){
		posorden(raiz->izdo);
		posorden(raiz->dcho);
		printf("%d ",raiz->dato);
	}
}

void enorden(Nodo* raiz){
	if(raiz){
		posorden(raiz->izdo);
		printf("%d ",raiz->dato);
		posorden(raiz->dcho);
	}
}
