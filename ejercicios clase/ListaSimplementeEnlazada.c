/* LIBRERÍAS ESTÁNDAR*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


/* ZONA DE DECLARACIÓN DE CONSTANTES*/



#define MAX_NOMBRE 500
#define MAX_APELLIDO 500
#define MENSAJE_LISTA_VACIA "La lista esta vacia.\n"


/* ZONA DE DECLARACIÓN DE TIPOS*/

typedef enum {FALSE, TRUE} tBoolean;

typedef struct _pnodo {
int Elem; /* Variable para almacenar un elemento de la pila. */
struct _pnodo *Sig;
/* Puntero al siguiente nodo que contiene un elemento. */
} tNodo;
/* Tipo nodo. Cada nodo contiene un elemento de la pila. */


typedef tNodo * tPosicion;
/* Cada posicion se referencia con un puntero. */

typedef struct { /* Definimos el tipo lista con un puntero */
tPosicion Primero, Ultimo; /* al primero y ultimo nodos. */
} tLista;



/*
 *
 * Función: CrearLista
 * crea una lista vacía.
 * Parámetro de entrada/salida:
 *        No tiene.
 * Parámetro de salida:  Devuelve una cola vacía.
 *
 */

tLista *CrearLista() {

  tLista *l;

   l = (tLista *) malloc(sizeof(tLista)); /* Creamos una lista. */
   l->Primero = NULL;
   l->Ultimo = NULL;


return(l); /* Devolvemos un puntero a la lista creada. */
}


/*
 *
 * Función: InsertarOrdenado
 *
 * inserta e en la lista l de forma que queden los elementos ordenadados de menor a mayor.
 * Los elementos que estan a partir de la posición del nuevo elemento se desplazan una posición.
 * Parámetro de entrada:
 *     Elemento
 * Parámetro de entrada/salida:
 *     Lista.
 * Parámetro de salida:  Lista.
 *
 */

tLista *InsertarOrdenado(tLista *l, int e) {
    tBoolean colocado = FALSE;

    //printf("Entra funcion...\n");
    // Punteros auxiliares
    tPosicion aux = NULL;
    tPosicion aux_sig = NULL;

    // Reservamos espacio y creamos el nuevo nodo
    tNodo *nuevo;
    nuevo = (tNodo*) malloc(sizeof(tNodo));
    nuevo->Elem = e;
    nuevo->Sig = NULL;

    // Verificar si la lista está vacía
    if (l->Primero == NULL) { // Vacía
            printf("¡Lista vacia! Se mete el primer elemento...\n");
        l->Primero = nuevo;
        l->Ultimo = nuevo;
    }
    else {
        aux = l->Primero;
        aux_sig = l->Primero->Sig;

        while (aux != NULL & !colocado) {
            if (aux->Elem < e) { /* ¡¡SIGNO CAMBIADO!! > => < */ // e es MAYOR que aux->Elem

                /* ¡NUEVO! Estamos al final de la lista aux_sig == NULL*/
                if (aux_sig == NULL) {
                    aux->Sig = nuevo;
                    nuevo->Sig = NULL;
                    colocado = TRUE;
                }
                else if (aux_sig->Elem >=  e) {
                    // Hay que insertar entre aux y aux_sig
                    aux->Sig = nuevo;
                    nuevo->Sig = aux_sig;

                    colocado = TRUE; // Terminamos, asi no entra de nuevo bucle
                }
            }
            else { // e es menor que aux->Elem
               l->Primero = nuevo;
               nuevo->Sig = aux;
               colocado = TRUE;
            }

            if (colocado) {
                aux = NULL;
            }
            else {
                aux = aux_sig;
                aux_sig = aux->Sig;
            }
        }
    }

    return l;
}

/*
 *
 * Función: Insertar
 *
 * inserta e en la posición p+1 de la lista l. Los elementos que estan a partir de la posición p+1
 * se desplazan una posición.
 * Parámetro de entrada:
 * Elemento, Posicion
 * Parámetro de entrada/salida:
 *        Lista.
 * Parámetro de salida:  Lista.
 *
 */

tLista *Insertar(tLista *l, int e, tPosicion p) {

tPosicion q;
q = p->Sig; /* Dejamos q apuntando al nodo que se desplaza. */
p->Sig = (tNodo *) malloc(sizeof(tNodo));
/* Creamos un nodo. */

p->Sig->Elem = e; /* Guardamos el elemento. */
p->Sig->Sig = q;
/* El sucesor del nuevo nodo esta apuntado por q. */
/* Si el nodo insertado ha pasaso a ser el ultimo, */
if (p == l->Ultimo)
  l->Ultimo = p->Sig; /* actualizamos ultimo. */
return(l);
/* Devolvemos un puntero a la lista modificada. */
}
/*
 *
 * Función: Borrar
 *
 * Borra el elemento de la posición p de la lista l.
 * Parámetro de entrada:
 * Elemento, Posicion
 * Parámetro de entrada/salida:
 *        Lista.
 * Parámetro de salida:  Lista.
 *
 */


tLista *Borrar(tLista *l, tPosicion p) {

tPosicion q;
if (p->Sig == l->Ultimo)
/* Si el nodo que borramos es el ultimo, */
  l->Ultimo = p; /* actualizamos ultimo. */
 q = p->Sig; /* Dejamos q apuntando al nodo a borrar. */
 p->Sig = p->Sig->Sig; /* p->sig apuntara a su sucesor. */
 free(q);
/* Liberamos la memoria ocupada por el nodo a borrar. */
return(l);
/* Devolvemos un puntero a la lista modificada. */
}


/*
 *
 * Función: Recuperar
 *
 * Devuelve el elemento de la posicion p de la lista l.
 * Parámetro de entrada:
 *  Posicion
 * Parámetro de entrada/salida:
 *        Lista.
 * Parámetro de salida:  Elemento.
 *
 */

int Recuperar(tLista *l, tPosicion p) {
return(p->Sig->Elem);
/* Devolvemos el elemento que hay en la posicion p. */
}

/*
 *
 * Función: EsListaVacia
 *
 * Devuelve el elemento de la posicion p de la lista l.
 * Parámetro de entrada:
 *  Lista
 * Parámetro de entrada/salida:
 *        Lista.
 * Parámetro de salida: TRUE/FALSE.
 *
 */
tBoolean EsListaVacia (tLista *l) {
if (l->Primero == NULL) //(l->Primero->Sig == NULL)
  return TRUE;
else
  return FALSE;

/* Devolvemos FALSE si la lista */
/* no esta vacia, y TRUE en caso contrario. */
}
/*
 *
 * Función: ConseguirPosicionFin
 *
 * Devuelve un puntero al último elemento de la lista.
 * Parámetro de entrada:
 *  Lista
 * Parámetro de entrada/salida:
 *  No tiene.
 * Parámetro de salida:  Puntero al ultimo elemento de la lista
 *
 */
tPosicion ConseguirPosicionFin(tLista *l) {
return(l->Ultimo); /* Devolvemos la ultima posicion. */
}

/*
 *
 * Función: ConseguirPosicionPrincipio
 *
 * Devuelve un puntero al último elemento de la lista.
 * Parámetro de entrada:
 *  Lista
 * Parámetro de entrada/salida:
 *  No tiene.
 * Parámetro de salida:  Puntero al primer elemento de la lista
 *
 */
tPosicion ConseguirPosicionPrincipio(tLista *l) {
return(l->Primero); /* Devolvemos la primera posicion. */
}
/*
 *
 * Función: ConseguirPosicionPrincipio
 *
 * Devuelve un puntero al elemento de la lista que sigue al que se le pasa como parametro.
 * Parámetro de entrada:
 *  Lista
 *   Elemento de la Lista
 * Parámetro de entrada/salida:
 *  No tiene.
 * Parámetro de salida:  puntero al elemento de la lista que sigue al que se le pasa como parametro.
 *
 */
tPosicion ConseguirPosicionSiguiente(tLista *l, tPosicion p) {
return(p->Sig);
/* Devolvemos la posicion siguiente a la posicion p. */
}
/*
 *
 * Función: Menu
 *
 * Presenta el menu de opciones
 * Parámetro de entrada:
 *
 *  No tiene
 * Parámetro de entrada/salida:
 *  No tiene.
 * Parámetro de salida:  opcion escogida por el usuario.
 *
 */


int menu (void);


/*
 *
 * Función: VisualizarLista
 *
 * Imprime los elementos de la Lista
 * Parámetro de entrada:
 *
 *  Lista
 * Parámetro de entrada/salida:
 *  No tiene.
 * Parámetro de salida:  No tiene.
 *
 */
void VisualizarLista(tLista *p) {

 tNodo * pAux;

  //pAux = p->Primero->Sig;
  pAux = p->Primero;

 printf("Contenido de la cola:\n");
 while (pAux != NULL) {
   printf("%d\n", pAux->Elem);
   pAux = pAux->Sig;
 }


}

/*
 *
 * Función: VisualizarLista
 *
 * Imprime los elementos de la Lista
 * Parámetro de entrada:
 *
 *  Lista
 * Parámetro de entrada/salida:
 *  No tiene.
 * Parámetro de salida:  Número de elementos.
 *
 */
int CalcularNumeroElementosLista(tLista *p) {

 tNodo * pAux;
 int NumElem;
  NumElem=0;
  pAux = p->Primero->Sig;
 printf("Contenido de la cola:\n");
 while (pAux != NULL)
 {
   printf("%d\n", pAux->Elem);
   NumElem++;
   pAux = pAux->Sig;
 }
 return NumElem;

}

/* PROGRAMA PRINCIPAL */

int main() {

int Opcion, Pos;

tLista *pLista;
int Elemento;
int i;

pLista= (tLista *) malloc(sizeof(tLista)); /* Reservamos memoria para pLista. */

pLista = CrearLista();

tPosicion pPos;
pPos = (tNodo*) malloc(sizeof(tNodo)); /* Reservamos memoria para Pos. */

/* PRUEBAS */
//pLista = InsertarOrdenado(pLista, 1);
//pLista = InsertarOrdenado(pLista, 10);
//pLista = InsertarOrdenado(pLista, 3);
/* PRUEBAS */

do
{
  Opcion=menu();
  switch (Opcion)
  {
     case 1: printf("Teclee elemento: \n");
             scanf("%d",&Elemento);
             pLista = InsertarOrdenado(pLista, Elemento);
             // Hemos modificado todo el apartado 1.
             break;

     case 2: if (!EsListaVacia (pLista))
             {
                printf("Teclee posicion: \n");
                scanf("%d",&Pos);
                if (Pos<= CalcularNumeroElementosLista(pLista))
                {
                  pPos = pLista->Primero;
                  for (i=2;i<=Pos;i++)
                    pPos = pPos->Sig;
                  pLista = Borrar(pLista, pPos);
                 }
                 else
                   printf("La posicion es incorrecta\n");
             }
             else
               printf("%s\n", MENSAJE_LISTA_VACIA);
             break;

      case 3: if (!EsListaVacia (pLista))
                VisualizarLista(pLista);
              else
                printf("%s\n", MENSAJE_LISTA_VACIA);
              break;

     case 4:  break;


     default: printf ("\nNo es una opcion correcta. Por favor, introduzca un numero entre 1 y 4");
   }
 }while (Opcion!= 4);

}

int menu (void)
{
	int opcion;

	printf ("\n  ***************************** Opciones ********************************");
	printf ("\n  *   1. Poner elemento en la lista                                     *");
	printf ("\n  *   2. Sacar elemento de la lista                                     *");
	printf ("\n  *   3. Visualizar contenido de la lista                               *");
  printf ("\n  *   4. Salir                                                          *");
	printf ("\n  ***********************************************************************");

	printf ( "\nElija opcion: ");
        scanf("%d", &opcion);

    return opcion;
} /*fin menu*/
