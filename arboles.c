#include <stdio.h>
#include <stdlib.h>

struct arbol{
    int dato;
    struct arbol *izq;
    struct arbol *der;
};

int menu();
struct arbol* crearnodo();
struct arbol* insertar(struct arbol *raiz, struct arbol *nuevo);

int menu() {
    int opcion;

    printf("\nMENU\n");
    printf("1.- Insertar\n");
    printf("2.- Salir\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

struct arbol* crearnodo(){

    struct arbol *nuevo;

    nuevo = (struct arbol*)malloc(sizeof(struct arbol));

    if(nuevo != NULL){

        printf("Ingresa el dato: ");
        scanf("%d", &nuevo->dato);

        nuevo->izq = NULL;
        nuevo->der = NULL;
    }

    return nuevo;
}
struct arbol* insertar(struct arbol *raiz, struct arbol *nuevo){

    if(raiz == NULL){
        return nuevo;
    }

    if(nuevo->dato < raiz->dato){
        raiz->izq = insertar(raiz->izq, nuevo);
    }
    else if(nuevo->dato > raiz->dato){
        raiz->der = insertar(raiz->der, nuevo);
    }

    return raiz;
}

int main(){

    int opcion;

    struct arbol *raiz = NULL;
    struct arbol *ptrtemp;

    do{

        opcion = menu();

        switch(opcion){

            case 1:

                ptrtemp = crearnodo();

                if(ptrtemp == NULL){

                    printf("No se pudo crear el nodo\n");

                }else{

                    raiz = insertar(raiz, ptrtemp);

                    printf("Nodo insertado correctamente\n");
                }

                break;

            case 2:

                printf("Saliendo...\n");
                break;

            default:

                printf("Opcion invalida\n");
        }

    }while(opcion != 2);

    return 0;
}