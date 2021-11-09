// ejercicio 6
/*
comprobar si ya esta metido
tiene un hueco según su id
*/

/*EDA Curso 2021-2022
 * PRACTICA 1 PARTE 1
 */

/* LIBRERÍAS ESTÁNDAR*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>

#define MAX_CARACTERES 1000
#define N 50
#define FICH01 "fich01.txt"
/* ZONA DE DECLARACIÓN DE CONSTANTES*/

typedef enum {FALSE, TRUE} tBoolean;

typedef struct Conjunto{
    char Nombre[MAX_CARACTERES];
    int Elementos[N];
    int Ultimo;
};




int main(void)         /* funcion o programa principal */
{
    int elementos=0,indice;
    struct Conjunto tConjunto1;
    struct Conjunto tConjunto2;
    struct Conjunto tConjunto3;

    elementos = ConjuntosLeer(tConjunto1,tConjunto2,tConjunto3);
    do{
        indice=menu();
        switch (indice)
        {
            case 1:
                printf("Teclee elemento: \n");
                break;
            case 2:printf("Teclee posicion: \n");
                break;
            case 3:
                break;

            case 4:  break;
            case 5:  break;
            case 6:  printf("Adios");
                break;



            default: printf ("\nNo es una opcion correcta. Por favor, introduzca un numero entre 1 y 6");
        }
    }while (indice!= 6);
}

int menu (void)
{
	int opcion;
    printf ("\n  ***************************** Opciones ********************************");
	  printf ("\n  *   1. Mostrar conjuntos 1, 2, y 3.                                   *");
	  printf ("\n  *   2. Unir conjuntos 1, 2 y 3.                                       *");
	  printf ("\n  *   3. Intersección de conjuntos 2 y 3.                               *");
    printf ("\n  *   4. Diferencia de conjuntos 2 y 3                                  *");
    printf ("\n  *   5. Eliminar ciudades con espacios en blanco.                      *");
    printf ("\n  *   6. Salir                                                          *");
    printf ("\n  ***********************************************************************");
    printf ( "\nElija opcion: ");
    scanf("%d", &opcion);
    return opcion;
} /*fin menu*/

int ConjuntosLeer(struct Conjunto tConjunto1, struct Conjunto tConjunto2, struct Conjunto tConjunto3){
    FILE *pfich; /* Puntero al archivo */
    char *dato; /* dato leído del fichero */
    int contador=0;  /* Contador  */
    char temporal[MAX_CARACTERES];
        pfich = fopen(FICH01, "r");
        if (pfich == NULL) {  //si no lo abre que no ejecute nada
            printf("Error: No se puede abrir el fichero \"fich01.csv\"\n"); }
        else {          //si lo abre, adelante con el contado de lienas
            contador = 0; /* Inic. de suma antes de entrar en el bucle */

           while((dato = fgetc(pfich)) != EOF) //simpre que no detecte el final del archivo siga
            {
                    int contadorletras=0;
                    char aux='0';//inicializamos
                    limpiado(temporal); //vaciamos la variable para que este todo vacio
                    //detecta por fragmentos de lineas
                    for (int j=0; (aux !='\n')&& (aux!= EOF); j++){ //mientras que detecte el espacio que guarda los caracterres del ficheroe en un char temporal
                        aux = fgetc(pfich);                           //eof es para que cuando coja que esta vacio, EOf, pues que no lo haga porque sino se hace un bucle infinito
                        if (aux != '\n'){ //pasamos los datos de aux al array temporal
                        temporal[j]= aux;
                        contadorletras++;
                        }
                    }
                    printf("%d\n",contadorletras);
                    if(contadorletras<=4){
                    }
                    if(contadorletras<=6){

                    }
                    if(contadorletras>6)

            contador++;
            }
            rewind(pfich); // vuelve al comienzo del archivo
            if( fclose(pfich) != 0) { //si no cierra da error
                printf("Error al cerrar el fichero\n"); }
            }

            return contador; //devolvemos el numero de lineas contadas

}
void limpiado(char temporal[]){ //para vaciar la variable
     for (int i=0;i<N;i++ ){
        temporal[i]='\0';
     }

 }
