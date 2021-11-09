/* Curso EDA 2020-2021
   Autor: Javier Sánchez Soriano
   TAD: Colas estáticas mediante vector circular
   Fecha: 26/10/2021
*/

#include <stdio.h>
#include <string.h>

#define N 4



/* ZONA DE DECLARACIÓN DE TIPOS*/

typedef enum {FALSE, TRUE} tBoolean;

typedef struct {
    int Elementos[N];
    int Primero;
    int Ultimo;
    int Tamanio;
} tCola;

// Prototipos de funciones
int sig(int i);
tCola colaVacia ();
tBoolean esVacia (tCola C);
tCola encolar (tCola C, int elemento);
tCola desencolar (tCola C);
int primero(tCola C);


int main () {

    tCola cola = colaVacia();

    // Verificamos si está vacia
    printf("esVacia? %d \n", esVacia(cola));


    cola = encolar(cola, 3);
    cola = encolar(cola, 5);
    cola = encolar(cola, -6);
    cola = encolar(cola, 23);
    cola = encolar(cola, 0);

    // Verificamos si está vacia
    printf("esVacia? %d \n", esVacia(cola));

    // Consultamos el primero
    printf("Primero? %d \n", primero(cola));

    cola = desencolar(cola);
    cola = desencolar(cola);

    // Consultamos el primero
    printf("Primero? %d \n", primero(cola));

    cola = desencolar(cola);
    cola = desencolar(cola);
    cola = desencolar(cola);
    cola = desencolar(cola);
    cola = desencolar(cola);
    cola = desencolar(cola);
    cola = desencolar(cola);

    // Verificamos si está vacia
    printf("esVacia? %d \n", esVacia(cola));

    // Consultamos el primero
    printf("Primero? %d \n", primero(cola));
}

int sig(int i) {
    int resultado = 0;
    if (i<N-1) {
        resultado = i+1;
    }
    return resultado;


    //return (i%N) +1; // Pensar en esto y como corregirlo
}

tCola colaVacia () {
    tCola cola;

    cola.Primero = 0;
    cola.Ultimo = 0;
    cola.Tamanio = 0;

    return cola;
}

tBoolean esVacia (tCola C) {
    return C.Tamanio == 0;
}

tCola encolar (tCola C, int elemento) {
    if (C.Tamanio == N) {
        printf("ERROR. No se puede encolar, esta llena.\n");
    }
    else {
        C.Elementos[C.Ultimo] = elemento;
        C.Tamanio++;
        C.Ultimo = sig(C.Ultimo);
    }
    return C;
}
int primero(tCola C) {
    int valor = -1;

    if (esVacia(C)) {
        printf("ERROR. No se puede consultar el primer, esta vacia.\n");
    }
    else {
        valor = C.Elementos[C.Primero];
    }
    return valor;
}

tCola desencolar (tCola C) {
    if (esVacia(C)) {
        printf("ERROR. No se puede desencolar, esta vacia.\n");
    }
    else {
        C.Tamanio--;
        C.Primero = sig(C.Primero);
    }
    return C;
}
