#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int d;
    struct Dato *ptrSig;
};

//prototipos
int menu(void);
int submenu(void);

struct Dato* crearDato(void);
void mostrarDato(struct Dato *ptr);
void liberarDato(struct Dato **ptr);
void liberarTodo(struct Dato **ptr);
void buscardato(struct Dato *ptr);
void apuntardato(struct Dato **ptr);

//meun principal 
int menu(void){
    int opcion;
    printf("1.- Crear dato\n");
    printf("2.- funciones\n");
    printf("3.- Liberar ultimo dato\n");
    printf("4.- Liberar TODOS los datos \n"); // NUEVA OPCION EN CLASE
    printf("5.- Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

//submenu
int submenu(void){
    int opcion;

    printf("submenu de funciones \n");
    printf("1.- buscar dato\n");
    printf("2.- apuntar dato\n");
    printf("3.- regresar\n");
    scanf("%d",&opcion);

    return opcion;
}

int main(void){

    struct Dato *ptr = NULL, *ptrTemp = NULL, *ptrAux = NULL;
    int opcion, subopcion;

    do{
        opcion = menu();

        switch(opcion){

            case 1:
                ptrTemp = crearDato();

                if(ptrTemp == NULL){
                    printf("No se pudo crear el dato.\n");
                }else{
                    printf("Dato creado exitosamente.\n");

                    if(ptr == NULL){
                        ptr = ptrTemp;
                    }else{
                        ptrAux = ptr;

                        while(ptrAux->ptrSig != NULL){
                            ptrAux = ptrAux->ptrSig;
                        }

                        ptrAux->ptrSig = ptrTemp;
                    }
                }
                break;

            case 2:
                do{
                    subopcion = submenu();

                    switch(subopcion){

                        case 1:
                            printf("caso one");
                            break;

                        case 2:
                            printf("caso two");
                            break;

                        case 3:
                            printf("Regresando al menu principal...\n");
                            break;

                    }

                }while(subopcion != 3);
                break;

            case 3:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }

    }while(opcion != 3);

    return 0;
}

//funciones 

struct Dato* crearDato(void){

    struct Dato *ptrTemp;

    ptrTemp = (struct Dato*)malloc(sizeof(struct Dato));

    if(ptrTemp == NULL){
        printf("Error al asignar memoria.\n");
        return NULL;
    }

    printf("Ingrese un entero: ");
    scanf("%d",&ptrTemp->d);

    ptrTemp->ptrSig = NULL;

    return ptrTemp;
}

void mostrarDato(struct Dato *ptr){

    if(ptr == NULL){
        printf("No hay datos.\n");
        return;
    }

    while(ptr != NULL){
        printf("%d\n",ptr->d);
        ptr = ptr->ptrSig;
    }
}

void liberarDato(struct Dato **ptr){

    struct Dato *ptrAux;

    if(*ptr == NULL){
        printf("No hay datos para liberar.\n");
    }else{

        if((*ptr)->ptrSig == NULL){
            free(*ptr);
            *ptr = NULL;
        }else{

            ptrAux = *ptr;

            while(ptrAux->ptrSig->ptrSig != NULL){
                ptrAux = ptrAux->ptrSig;
            }

            free(ptrAux->ptrSig);
            ptrAux->ptrSig = NULL;
        }

        printf("Ultimo dato liberado.\n");
    }
}

void liberarTodo(struct Dato **ptr){

    struct Dato *ptrAux;

    if(*ptr == NULL){
        printf("No hay datos para liberar.\n");
        return;
    }

    while(*ptr != NULL){
        ptrAux = *ptr;
        *ptr = (*ptr)->ptrSig;
        free(ptrAux);
    }

    printf("Todos los datos fueron liberados.\n");
}