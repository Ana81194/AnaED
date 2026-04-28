#include <stdio.h>
#include <stdlib.h>

struct Dato{
	int d;
	struct Dato *ptrSig;
};
int menu(void){
    int opcion;
    printf("1.- Crear dato\n");
    printf("2.- Mostrar dato\n");
    printf("3.- Liberar ultimo dato\n");
    printf("4.- Liberar TODOS los datos\n"); // NUEVA OPCION EN CLASE
    printf("5.- Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
struct Dato* crearDato(void);
void mostrarDato(struct Dato *ptr);
void liberarDato(struct Dato **ptr);

int main (void){
	struct Dato *ptr = NULL, *ptrTemp = NULL, *ptrAux = NULL;
	int opcion;
do{
    opcion = menu();
    switch(opcion){
        case 1:
            ptrTemp = crearDato();
            if(ptrTemp == NULL){
                printf("No se pudo crear el dato.\n");
            } else {
                printf("Dato creado exitosamente.\n");
                if(ptr == NULL){
                    ptr = ptrTemp;
                } else {
                    ptrAux = ptr; // Se crea un apuntador auxiliar para recorrer la lista enlazada
                    while(ptrAux->ptrSig != NULL){// Se recorre la lista enlazada hasta llegar al último nodo, el cual apunta a NULL
                        ptrAux = ptrAux->ptrSig; // Se actualiza el apuntador auxiliar para que apunte al siguiente nodo, hasta llegar al último nodo de la lista enlazada
                    }
                    ptrAux->ptrSig = ptrTemp;// Se enlaza el nuevo nodo al final de la lista enlazada, haciendo que el último nodo apunte al nuevo nodo creado
                }
            }
            break;

        case 2:
            mostrarDato(ptr);
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
            printf("Opcion invalida\n");
    }
} while(opcion != 5);
	
}

  //Hay dos formas de crear un dato:
  //1.- La funcion crea el nuevo modulo y retorna la nueva direccion de memoria de ese modulo de tal forma como ptr = crearDato(ptr);
  // 2.- La direccion de la variable ptr e implementa doble apuntador para modificar ptr desde la funcion, es decir, crearDato(&ptr);
 
struct Dato * crearDato(void){
	
	struct Dato *ptrTemp;
	ptrTemp = (struct Dato *)malloc(sizeof(struct Dato)); 
	if(ptrTemp == NULL){
		printf("Error al asignar memoria.\n");
		return NULL;
	} else {
		printf("Ingrese un entero: ");
		scanf("%d", &ptrTemp->d); 
		ptrTemp->ptrSig = NULL; 
		return ptrTemp; 
	}
}

void mostrarDato(struct Dato *ptr){
	// Mostrar dato
	while(ptr != NULL){
		printf("%d\n", ptr->d); 
		ptr = ptr->ptrSig; 
	}
}


  //Pa sos para liberar un dato(nodo):
   //1.- Verificar el penultimo nodo de la estructura tipo pila

void liberarDato(struct Dato **ptr){
	struct Dato *ptrAux; 
	if(*ptr == NULL){
		printf("No hay datos para liberar.\n");
	} else {
		if((*ptr)->ptrSig == NULL){ 
			free(*ptr); 
			*ptr = NULL; 
		} else {
			ptrAux = *ptr; 
			while(ptrAux->ptrSig->ptrSig != NULL){ 
				ptrAux = ptrAux->ptrSig; 
			}
			free(ptrAux->ptrSig); 
			ptrAux->ptrSig = NULL; 
		}
	}
}
void liberarTodo(struct Dato **ptr){
    struct Dato *ptrAux;

    if(*ptr == NULL){
        printf("No hay datos para liberar.\n");
        return;
    }

    while(*ptr != NULL){
        ptrAux = *ptr;          // Guardamos el nodo actual 
        *ptr = (*ptr)->ptrSig;  // Avanzamos al siguiente nodo
        free(ptrAux);           // Liberamos el nodo
    }

    printf("Todos los datos han sido liberados.\n");
}
