#include <stdio.h>
#include <stdlib.h>

// Estructura del árbol
struct arbol{
    int dato;
    struct arbol *izq, *der;
};

// Prototipos
int menu();
struct arbol* crearnodo();
struct arbol* insertar(struct arbol *raiz, struct arbol *nuevo);

// Menú
int menu() {

    int opcion;

    printf("\nMENU\n");
    printf("1.- Insertar\n");
    printf("2.- Salir\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

// Crear nodo
struct arbol* crearnodo(){

    struct arbol *ptrtemp;

    ptrtemp = (struct arbol*) malloc(sizeof(struct arbol));

    if(ptrtemp != NULL){

        printf("Ingrese el dato: ");
        scanf("%d", &ptrtemp->dato);

        ptrtemp->izq = NULL;
        ptrtemp->der = NULL;
    }

    return ptrtemp;
}

// Insertar nodo
struct arbol* insertar(struct arbol *raiz, struct arbol *nuevo){

    if(raiz == NULL){

        return nuevo;
    }

    if(nuevo->dato < raiz->dato){

        raiz->izq = insertar(raiz->izq, nuevo);

    }else if(nuevo->dato > raiz->dato){

        raiz->der = insertar(raiz->der, nuevo);
    }

    return raiz;
}

int main(void){

    struct arbol *raiz = NULL;
    struct arbol *ptrtemp;

    int opcion;

    do {

        opcion = menu();

        switch (opcion) {

            case 1:

                ptrtemp = crearnodo();

                if(ptrtemp == NULL){

                    printf("No se pudo crear el nodo\n");

                }else{

                    printf("El nodo fue creado exitosamente\n");

                    raiz = insertar(raiz, ptrtemp);
                }

                break;

            case 2:

                printf("Saliendo...\n");

                break;

            default:

                printf("Opcion no valida\n");
        }

    } while (opcion != 2);

    return 0;
}