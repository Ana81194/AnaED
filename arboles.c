#include <stdio.h>
struct arbol{
    int dato;
    struct arbol *izq , *der;
    raiz=NULL;
}
int menu() {
    int opcion;
    printf("\nMenú\n");
    printf("1.- insertar\n");
    printf("2.- salir\n");
    scanf("%d", &opcion);
    return opcion;
}

int main(void){
    struct *raiz;
    do {
        opcion = menu();
        switch (opcion) {
            case 1:
            ptrtemp= crearnodo();
            if(ptrtemp=NULL){
                printf("no se pudo crear el nodo\n");
            }else{
                printf("el nodo fue creado exitosamente\n");
                if(raiz==NULL)
                    raiz= ptrtemp;
            }
                while{
                    if(nuevo->dato < raiz->dato){
                    raiz->izq = insertar(raiz->izq, nuevo);
                }
                     else if(nuevo->dato > raiz->dato){
                        raiz->der = insertar(raiz->der, nuevo);
                     }

                     return raiz;
                }
                break;
            case 2:
                salir
                break;
        }
    } while (opcion != 2);

    return 0;
}  este es mi codigo 