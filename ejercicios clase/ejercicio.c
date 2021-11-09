/* Curso EDA 2020-2021
   Autor: Javier Sánchez Soriano
   TAD: Conjuntos mediante el uso de Vectores

   TO-DO: Pendiente implementación de los métodos y main
*/


#include <stdio.h>
#include <string.h>

#define CORRECTO 0
#define ERR_INTRODUCIR 1
#define ERR_ELIMINAR 2
#define N 50



/* ZONA DE DECLARACIÓN DE TIPOS*/

typedef enum {FALSE, TRUE} tBoolean;

typedef struct {
    int Elementos[N];
    int Ultimo;
} tConjunto;

void cjtoVacio (tConjunto *C);
void initCjto (tConjunto *C, int elemento);
tBoolean esVacio (tConjunto C);

tBoolean  esta (tConjunto C, int elemento);
int aniadir (tConjunto *C, int elemento);
int quitar (tConjunto *C, int elemento);

void imprimeCjto (tConjunto C);
int cardinal (tConjunto C);

// TO-DO: Faltarian union(), interseccion() y diferencia()...

int main() {

    tConjunto cjto;
    tConjunto *conjunto = &cjto;

    printf("PROBANDO!");


     // Se crea conjunto vacío
     cjtoVacio(conjunto);
     printf("\nEs vacio: %d\n", esVacio(*conjunto));

     // Se crea conjunto con un elemento dentro...
     initCjto(conjunto, 34);
     printf("\nEs vacio: %d\n", esVacio(*conjunto));

}

void cjtoVacio (tConjunto *C){
    C->Ultimo=-1;
}

void initCjto (tConjunto *C, int elemento) {
    C->Ultimo = 0;
    C->Elementos[C->Ultimo] = elemento;
}

tBoolean esVacio (tConjunto C) {
    tBoolean vacio = FALSE;
    if (C.Ultimo == -1) {
        vacio = TRUE;
    }
    return vacio;
}

tBoolean  esta (tConjunto C, int elemento) {
    return FALSE;
}

int aniadir (tConjunto *C, int elemento) {
    return ERR_INTRODUCIR;
}

int quitar (tConjunto *C, int elemento){
    return ERR_ELIMINAR;
}

void imprimeCjto (tConjunto C) {

}

int cardinal (tConjunto C){
    return 0;
}
