#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct dato {
int d;
struct dato *ptrsig;
};

// Prototipos
int menu();
void creardato(struct dato **ptr);
void mostrarDatos(struct dato *ptr);
void liberardato(struct dato **ptr);

int main(void) {
struct dato *ptr = NULL;
int opcion;

srand(time(NULL));

do {
    opcion = menu();
        switch (opcion) {
    case 1:
        creardato(&ptr);
    break;
    case 2:
        mostrarDatos(ptr);
    break;
    case 3:
        liberardato(&ptr);
    break;
    case 4:
    break;
    default:
        printf("no valido \n");
}
} while (opcion != 4);

return 0;
}

int menu() {
int opcion;
printf("\nMenu\n");
printf("1.- Crear dato\n");
printf("2.- Mostrar datos\n");
printf("3.- Liberar\n");
printf("4.- Salir\n");
scanf("%d", &opcion);
return opcion;
}

void creardato(struct dato **ptr) {
     struct Dato *ptrtemp;
    ptrtemp = (struct Dato *)malloc(sizeof(struct Dato));

    if(ptrtemp == NULL){
        printf("Error de memoria\n");
        return;
    }

    printf("Ingrese un valor entero: ");
    scanf("%d", &nuevo->d);

    nuevo->ptrSig = *ptr; // Insertar al inicio
    *ptr = nuevo;

    printf("Dato creado correctamente\n");
}



void mostrarDatos(struct dato *ptr) {
}


void liberardato(struct dato **ptr) {

}