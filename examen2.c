#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int d;
    struct Dato *ptrSig;
    struct Dato *ptrAnt;
};

// prototipos
int menu(void);

struct Dato* crearDato(void);

void insertarDato(struct Dato **ptr);
void mostrarDato(struct Dato *ptr);
void liberarDato(struct Dato **ptr);

int menu(void){

    int opcion;

    printf("\nMENU PRINCIPAL\n");
    printf("1.- Insertar dato\n");
    printf("2.- Mostrar datos\n");
    printf("3.- Eliminar dato\n");
    printf("4.- Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int main(void){

    struct Dato *ptr = NULL;

    int opcion;

    do{

        opcion = menu();

        switch(opcion){

            case 1:

                insertarDato(&ptr);

            break;

            case 2:

                mostrarDato(ptr);

            break;

            case 3:

                liberarDato(&ptr);

            break;

            case 4:

                printf("Saliendo...\n");

            break;

            default:

                printf("Opcion invalida.\n");
        }

    }while(opcion != 4);

    return 0;
}

// crear nodo
struct Dato* crearDato(void){

    struct Dato *ptrTemp;

    ptrTemp = (struct Dato*)malloc(sizeof(struct Dato));

    if(ptrTemp == NULL){

        printf("Error de memoria.\n");
        return NULL;
    }

    printf("Ingrese un numero: ");
    scanf("%d",&ptrTemp->d);

    ptrTemp->ptrSig = NULL;
    ptrTemp->ptrAnt = NULL;

    return ptrTemp;
}

// insertar nodo
void insertarDato(struct Dato **ptr){

    struct Dato *ptrTemp;
    struct Dato *ptrAux;

    ptrTemp = crearDato();

    if(ptrTemp == NULL){

        return;
    }

    if(*ptr == NULL){

        *ptr = ptrTemp;

        ptrTemp->ptrSig = ptrTemp;
        ptrTemp->ptrAnt = ptrTemp;

    }else{

        ptrAux = (*ptr)->ptrAnt;

        ptrTemp->ptrSig = *ptr;
        ptrTemp->ptrAnt = ptrAux;

        ptrAux->ptrSig = ptrTemp;
        (*ptr)->ptrAnt = ptrTemp;
    }

    printf("Dato insertado.\n");
}

// mostrar lista
void mostrarDato(struct Dato *ptr){

    struct Dato *ptrAux;

    if(ptr == NULL){

        printf("No hay datos.\n");
        return;
    }

    ptrAux = ptr;

    printf("\nLista:\n");

    do{

        printf("%d -> ",ptrAux->d);
        ptrAux = ptrAux->ptrSig;

    }while(ptrAux != ptr);

    printf("INICIO\n");
}

// eliminar ultimo nodo
void liberarDato(struct Dato **ptr){

    struct Dato *ptrAux;

    if(*ptr == NULL){

        printf("No hay datos.\n");
        return;
    }

    if((*ptr)->ptrSig == *ptr){

        free(*ptr);
        *ptr = NULL;

    }else{

        ptrAux = (*ptr)->ptrAnt;

        ptrAux->ptrAnt->ptrSig = *ptr;
        (*ptr)->ptrAnt = ptrAux->ptrAnt;

        free(ptrAux);
    }

    printf("Dato eliminado.\n");
}
