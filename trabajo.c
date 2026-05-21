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
	printf("3.- Liberar dato\n");
	printf("4.- Salir\n");
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
						ptrAux = ptr;
						while(ptrAux->ptrSig != NULL){ 
							ptrAux = ptrAux->ptrSig; 
						}
						ptrAux->ptrSig = ptrTemp; 
					}
				}
				break;
			case 2:
				// Mostrar dato
				break;
			case 3:
				liberarDato(&ptr);
				 	
				break;
			case 4:
				// Salir
				break;
			default:
				printf("Opcion invalida\n");
		}
	} while(opcion != 4);

}

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
}
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
			while(ptrAux->ptrSig != NULL){ 
				ptrAux = ptrAux->ptrSig; 
			}
			free(ptrAux); 
			*ptr = NULL;
		}
	}
}