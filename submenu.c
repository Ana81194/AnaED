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
void contardato(struct Dato **ptr);
void remplazarDato(struct Dato **ptr);
void ordenarDato(struct Dato **ptr);

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
    printf("2.- contar dato\n");
    printf("3.- remplazar dato\n");
    printf("4.- ordenar dato\n");
    printf("5.- regresar\n");
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
                            buscarDato(ptr);
                            break;

                        case 2:
                            remplazarDato(&ptr);
                            break;

                        case 3:
                            contarnodo(&ptr);
                            break;

                        case 4:
                            printf("Regresando al menu principal...\n");
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
                liberarTodo(&ptr); // NUEVA FUNCION CLASE
                break;
            case 5:
                break;
            default:
                printf("Opcion invalida.\n");
        }

    }while(opcion != 5);

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

void buscarDato(struct Dato *ptr){
    int valor, encontrado = 0 // esta en una bandera e inica en cero 

    printf("Ingrese el dato a buscar: ");
    scanf("%d", &valor);

    while(ptr != NULL){ }// aqui se recorre la lista el siclo sigue no importa que tenga nodos 

        if(ptr->d == valor){ // aqui es donde se compara el dato del nodo (ptr ->d) con el valor que se esta buscando 
            printf("Dato encontrado: %d\n", ptr->d);
            encontrado = 1;  // si son iguales cambia el encontado a 1
        }
        
        ptr = ptr->ptrSig; // este es para avanzar al sigiente nodos 
    }

    if(encontrado == 0){
        printf("Dato no encontrado.\n");
    }

void remplazarDato(struct Dato **ptr){
    int valor, nuevo; // nuevo es para el nuevo valor del que vamos a remplazar 

    struct Dato *aux = *ptr;

    printf("Ingrese el dato que quiere reemplazar: ");
    scanf("%d", &valor);

    printf("Ingrese el nuevo dato: ");
    scanf("%d", &nuevo);

    while(aux != NULL){  }  //recorremo la lista  
        if(aux->d == valor){ // se selecciona al nodo de el valor que vamos a cambiar 
            aux->d = nuevo; // remplazamos por el nuevo 
            printf("Dato reemplazado.\n");
            return;
        }
        aux = aux->ptrSig; // avanzamos al siguiente nodo 
    }

    printf("Dato no encontrado.\n");


