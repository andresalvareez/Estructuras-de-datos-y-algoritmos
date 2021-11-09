/*
   EDA - Ejercicios sobre ficheros. Enunciado al final del tema
   Autor: Javier Sánchez Soriano
   Fecha modificación: 06/10/2021

   PENDIENTE: Ejercicio 2, lo dejamos como tarea para casa
*/

#include <stdio.h>
#include <stdlib.h>

//  Recibe array y el tamaño (numero de elementos) del mismo.
//  Pinta por consola el array con este aspecto: {X,Y, ... K}
void visualizarArray(float *numeros, int size) {
    int i; // para el bucle

    if (size>0) {    // El array tiene algún valor dentro
        printf("{");
        for (i=0; i<size; i++) {
            if (i<size-1) {
                printf("% f , ", numeros[i]);
            }
            else { // último elemento, no pone coma y cierra la }
                printf("% f}\n\n", numeros[i]);
            }
        }
    }
    else {
        printf("Array vacio, nada que mostrar");
    }
}

//  Recibe array, su tamaño (nº elementos) y ruta del fichero a escribir.
//  Devuelve el número de elementos escritos.
int escribir_array_fichero (float numeros[], int size, char *ruta) {
    int i = 0;
    FILE *pfich;
	pfich = fopen(ruta,"w");
    //-- Verifica que el fichero se haya podido abrir --//
	if (pfich == NULL) {
        printf("\n Error al abrir el fichero");
        exit(1);
    }
    //-- Se emplea el fichero para escritura --//
    for (i=0; i<size; i++) {
        fprintf(pfich,"%f\n", numeros[i]); // Escribe cada valor del array en una línea
    }
    //-- Al acabar de usar el archivo --//
    if (fclose(pfich) != 0) {
        printf("\n Error al cerrar el fichero ");
        exit(1);
    }
    return size;
}

int contar_datos (char *ruta) {
    int ctrl;       /* Valor devuelto por fscanf */
    FILE *pfich;    /* Puntero al archivo */
    double dato;    /* dato leído del fichero */
    int numero = -1;/* contador del número de datos del fichero */

    pfich = fopen(ruta, "r");
    if (pfich == NULL) {
        printf("Error: No se puede abrir el fichero \"%s\"\n", ruta);
    }
    else {
        numero = 0; /* Inic. de suma antes de entrar en el bucle */
        do {
            ctrl = fscanf(pfich, " %lf ", &dato);
            if (ctrl==1) {
                numero++;
            }
        }
        while(ctrl==1);
    }

    //-- Al acabar de usar el archivo --//
    if (fclose(pfich) != 0) {
        printf("\n Error al cerrar el fichero ");
        exit(1);
    }

    return numero;
}

int leer_fichero_array (char *ruta, float *datos) { //&, int elementos) {
    int ctrl;       /* Valor devuelto por fscanf */
    FILE *pfich;    /* Puntero al archivo */
    double dato;    /* dato leído del fichero */
    int i = 0;      /* para ir recorriendo array (lectura) */

    pfich = fopen(ruta, "r");
    if (pfich == NULL) {
        printf("Error: No se puede abrir el fichero \"%s\"\n", ruta);
    }
    else {
        do {
            ctrl = fscanf(pfich, " %lf ", &dato);
            if (ctrl==1) {
                datos[i] = dato;
                i++;
            }
        }
        while(ctrl==1);
    }

    //-- Al acabar de usar el archivo --//
    if (fclose(pfich) != 0) {
        printf("\n Error al cerrar el fichero ");
        exit(1);
    }

    return i;
}


int main() {

    float numeros[] = {233, 4, 43.6, 3.3434, 345.46546, 565.56, -65.34, 133};  //Creación de un array */
    size_t  size = (sizeof (numeros) /sizeof (numeros[0])); // Consulta del número de elementos del array
    char *ruta = "info.txt";    // Fichero de trabajo

    int numero_datos = 0;   // Para contar los datos del fichero
    float *lectura;         // Para almacenar la lectura del fichero


    // EJ0: Se llama a la función para visualizar el array
    visualizarArray(numeros, size);

    // EJ1: Escritura del array en el fichero
    escribir_array_fichero(numeros, size, ruta);

    // EJ2: Lectura del fichero en un array
    // Contar el numero de elementos del fichero
    numero_datos = contar_datos(ruta);
    printf("N datos fichero: %d \n", numero_datos);

    // Rersevar espacio para los datos
    lectura = (float*) malloc(numero_datos * sizeof(float));
    if (lectura != NULL) {
        // Leer datos del fichero guardando en el espacio reservado
        leer_fichero_array(ruta, lectura);

        visualizarArray(lectura, numero_datos);

    }
    else {
        printf ("Error en la reserva de memoria");
    }

    printf("\n FIN! ");
    return 0;
}
