#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int d;
    struct Dato *ptrSig;
};

// prototipos
int menu(void);
int submenu(void);

struct Dato* crearDato(void);
void mostrarDato(struct Dato *ptr);
void liberarDato(struct Dato **ptr);
void liberarTodo(struct Dato **ptr);
void buscarDato(struct Dato *ptr);
void remplazarDato(struct Dato **ptr);
void ordenarnodo(struct Dato **ptr);

// menu principal
int menu(void){

    int opcion;

    printf("\n1.- Crear dato\n");
    printf("2.- Funciones\n");
    printf("3.- Liberar ultimo dato\n");
    printf("4.- Liberar TODOS los datos\n");
    printf("5.- Mostrar datos\n");
    printf("6.- Salir\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

// submenu
int submenu(void){

    int opcion;

    printf("\n--- SUBMENU ---\n");
    printf("1.- Buscar dato\n");
    printf("2.- Reemplazar dato\n");
    printf("3.- Ordenar nodos\n");
    printf("4.- Regresar\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int main(void){

    struct Dato *ptr = NULL;
    struct Dato *ptrTemp = NULL;
    struct Dato *ptrAux = NULL;

    int opcion;
    int subopcion;

    do{

        opcion = menu();

        switch(opcion){

            case 1:

                ptrTemp = crearDato();

                if(ptrTemp == NULL){

                    printf("No se pudo crear el dato.\n");

                }else{

                    if(ptr == NULL){

                        ptr = ptrTemp;

                    }else{

                        ptrAux = ptr;

                        while(ptrAux->ptrSig != NULL){
                            ptrAux = ptrAux->ptrSig;
                        }

                        ptrAux->ptrSig = ptrTemp;
                    }

                    printf("Dato creado exitosamente.\n");
                }

                break;

            case 2:

                do{

                    subopcion = submenu();

                    switch(subopcion){

                        case 1:
                            buscarDato(ptr);
                            break;

                        case 2:
                            remplazarDato(&ptr);
                            break;

                        case 3:
                            ordenarnodo(&ptr);
                            printf("Lista ordenada.\n");
                            break;

                        case 4:
                            printf("Regresando...\n");
                            break;

                        default:
                            printf("Opcion invalida.\n");
                    }

                }while(subopcion != 4);

                break;

            case 3:
                liberarDato(&ptr);
                break;

            case 4:
                liberarTodo(&ptr);
                break;

            case 5:
                mostrarDato(ptr);
                break;

            case 6:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }

    }while(opcion != 6);

    return 0;
}

// crear nodo
struct Dato* crearDato(void){

    struct Dato *ptrTemp;

    ptrTemp = (struct Dato*)malloc(sizeof(struct Dato));

    if(ptrTemp == NULL){

        printf("Error al asignar memoria.\n");
        return NULL;
    }

    printf("Ingrese un entero: ");
    scanf("%d", &ptrTemp->d);

    ptrTemp->ptrSig = NULL;

    return ptrTemp;
}

// mostrar datos
void mostrarDato(struct Dato *ptr){

    if(ptr == NULL){

        printf("No hay datos.\n");
        return;
    }

    printf("\nLista:\n");

    while(ptr != NULL){

        printf("%d -> ", ptr->d);
        ptr = ptr->ptrSig;
    }

    printf("NULL\n");
}

// liberar ultimo nodo
void liberarDato(struct Dato **ptr){

    struct Dato *ptrAux;

    if(*ptr == NULL){

        printf("No hay datos para liberar.\n");
        return;
    }

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

// liberar toda la lista
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

// buscar dato
void buscarDato(struct Dato *ptr){

    int valor;
    int encontrado = 0;

    printf("Ingrese el dato a buscar: ");
    scanf("%d", &valor);

    while(ptr != NULL){

        if(ptr->d == valor){

            printf("Dato encontrado: %d\n", ptr->d);
            encontrado = 1;
        }

        ptr = ptr->ptrSig;
    }

    if(encontrado == 0){
        printf("Dato no encontrado.\n");
    }
}

// reemplazar dato
void remplazarDato(struct Dato **ptr){

    int valor;
    int nuevo;

    struct Dato *aux = *ptr;

    printf("Ingrese el dato que quiere reemplazar: ");
    scanf("%d", &valor);

    printf("Ingrese el nuevo dato: ");
    scanf("%d", &nuevo);

    while(aux != NULL){

        if(aux->d == valor){

            aux->d = nuevo;

            printf("Dato reemplazado.\n");
            return;
        }

        aux = aux->ptrSig;
    }

    printf("Dato no encontrado.\n");
}

// ordenar nodos
void ordenarnodo(struct Dato **ptr){

    struct Dato *i;
    struct Dato *j;
    int temp;

    if(*ptr == NULL){
        return;
    }

    for(i = *ptr; i != NULL; i = i->ptrSig){

        for(j = i->ptrSig; j != NULL; j = j->ptrSig){

            if(i->d > j->d){

                temp = i->d;
                i->d = j->d;
                j->d = temp;
            }
        }
    }
}