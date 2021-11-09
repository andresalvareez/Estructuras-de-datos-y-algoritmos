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

/* ZONA DE DECLARACIÓN DE CONSTANTES*/


/*#define NE 100*/

#define CORRECTO 0
#define NUM_EMP 100
#define ERROR_LECT_FICHERO 1
#define FICH01 "fich01.csv"
#define FICH02 "fich02.csv"
#define MAX_CARACTERES 1000
#define MAX_TAM_LINEA 600

typedef struct{
    char Empresa [MAX_CARACTERES];
    double Ingresos;
    double Gastos;
    double Variacion;
 } Empresa;
struct Empresa *tEmpresa;
int main(void)
{
int prueba=0,elementos=0,num_empresa,indicestruct=0,menu=0;
    char *fichero =FICH01;


         //apuntamos al primer elemento del array
        elementos=contar_lineas(fichero/*,p_empresa*/);//contamos elementos para poder crear array de struc sabiendo cuantos vamos a necesitar

        //asignamos memoria dinamca
        tEmpresa =(Empresa*)malloc(elementos*sizeof(Empresa));
        /*
        printf("Los elementos son:%d\n",elementos);*/    //Si se quiere ver cuantos elementos he contado
        do
        {
            printf("Elija: \n1. Leer informacion de entrada.\n2. Calcular el numero de empresas que tuvieron perdidas durante el ejercicio 2020.\n3. Calcular el numero de empresas tuvieron beneficios durante el ejercicio 2020.\n4. Almacenar los ingresos estimados para todas las empresas en el ejercicio 2021.\n5. Salir del programa.\n");
            scanf("%d",&prueba);
            if (prueba==1 && menu==0){//menu se usa para ver si se ha abierto ya ntes el programa
                    leerfichero(tEmpresa,elementos);
                    printf("Se ha leido el fichero correctamente\n");
                    menu=1;} //para poder abrir las otras partes del menu
            else if(prueba==1 && menu==1){//en caso de que ya se ha leido, ahorrarse leerse y guardar todo otra vez
                printf("Ya se ha leido\n");}

            else if(prueba==2 &&menu==1){
                 printf("\nEl numero de empresas con perdidas es de: -%d-\n\n",contarperdidas(tEmpresa,elementos));}
            else if (prueba==2 &&menu==0){ //mensaje de errror en caso de que no se haya abierto el eje 1
                    printf("\n-ERROR-\nPrimero habre el apartado 1 para poder ejcutar este apartado\n\n");}

            else if(prueba==3 && menu ==1){
                    printf("\nEl numero de empresas con ganancias es de: -%d-\n\n",contarganacias(tEmpresa,elementos));}
            else if (prueba==3 &&menu==0){ //mensaje de errror en caso de que no se haya abierto el eje 1
                    printf("\n-ERROR-\nPrimero habre el apartado 1 para poder ejcutar este apartado\n\n");}

            else if (prueba==4 && menu ==1) {
                    guardardatos(tEmpresa,elementos);
                    printf("Guardado correctamente\n");}
            else if (prueba==4 &&menu==0){ //mensaje de errror en caso de que no se haya abierto el eje 1
                    printf("\n-ERROR-\nPrimero habre el apartado 1 para poder ejcutar este apartado\n\n");}

        }while(prueba!=5);
        printf("\nAdios");
}
int contar_lineas(char *fichero/*,tEmpresa *p_empresa*/){
    int ctrl; /* Valor devuelto por fscanf */
    FILE *pfich; /* Puntero al archivo */
    char *dato; /* dato leído del fichero */
    int contador=0; /* Contador  */
    int i=0;
        pfich = fopen("fich01.csv", "r");
        if (pfich == NULL) {  //si no lo abre que no ejecute nada
            printf("Error: No se puede abrir el fichero \"fich01.csv\"\n"); }
        else {          //si lo abre, adelante con el contado de lienas
            contador = 0; /* Inic. de suma antes de entrar en el bucle */
           while((dato = fgetc(pfich)) != EOF) //simpre que no detecte el final del archivo siga
            {
                if (dato == '\n')//cada vez que encuentre un salto de linea suma el contador
                    contador++;
            }
            rewind(pfich); // vuelve al comienzo del archivo

           /* while (fscanf(pfich, "%[^,],%Lf,%Lf,%d", p_empresa->Empresa, p_empresa->Ingresos, p_empresa->Gastos,p_empresa->Variacion)!='\n')
                    {
                             printf("Funciona");
                             "a" contiene la informacion del nodo leido, se procesa en alguna forma ...
                            printf("%s\n%Lf\n%Lf\n%d\n\n", p_empresa->Empresa, p_empresa->Ingresos, p_empresa->Gastos,p_empresa->Variacion);
                            p_empresa++;
                    }*/
            if( fclose(pfich) != 0) { //si no cierra da error
            printf("Error al cerrar el fichero\n"); }
            }

return contador; //devolvemos el numero de lineas contadas
 }
 void leerfichero(Empresa *tEmpresa,int elementos){
                char temporal[MAX_CARACTERES];
                FILE *pfich;  //declaramos puntero de tipo archivo
                pfich = fopen(FICH01, "r");//procedemos a guardar la informacion, abrimos el archivo
                if (pfich == NULL) {  //si no lo abre que no ejecute nada
                        printf("Error: No se puede abrir el fichero \"fich01.csv\"\n"); }
                else {          //si lo abre, adelante con el guardado de la inforamcacion
                            int indice=0; //indice para saber donde guardar la inforamcion
                            int index=0; //indice de las lienas, por tanto de las 100 empresas
                            for (int i =0; index <elementos;i++){ //hasta que haya hecho todas las lineas
                                    //creo en indice para saber  donde tiene que guardar los datos
                                    char aux='0';//inicializamos
                                    limpiado(temporal,elementos); //vaciamos la variable para que este todo vacio
                                    //detecta por fragmentos de lineas
                                    for (int j=0; (aux !=';') && (aux !='\n')&& (aux!= EOF); j++){ //mientras que detecte el ; que guarda los caracterres del ficheroe en un char temporal
                                        aux = fgetc(pfich);                           //eof es para que cuando coja que esta vacio, EOf, pues que no lo haga porque sino se hace un bucle infinito
                                        if (aux != ';'){ //pasamos los datos de aux al array temporal
                                            temporal[j]= aux;
                                        }
                                    }
                                    //como lo he hecho por caracteres vamos a tener 100 lineas * 4 secciones por linea,
                                    //cada 4 huecos valdra una linea
                                    if(i==4){
                                        index++;
                                        i=0;
                                    }
                                    if (indice ==4)//si ya ha llegado a la ultima seccion que reinice
                                    indice=0;
                                    if(index<elementos){//siemprey cuando el indice de las filas sea menor de 100 que ejecute el programa
                                        if( indice==0){
                                            indice++;
                                            strcpy(tEmpresa[index].Empresa, temporal); //copiamos el string en el array tEmpresa
                                        }
                                            //ahora lo hacemos para ingresos
                                        else if(indice==1){
                                        indice++;
                                        tEmpresa[index].Ingresos= atof(temporal); //atof pasa una cadena a un float
                                        }
                                        else if (indice==2){
                                            indice++;
                                            tEmpresa[index].Gastos=atof(temporal); //atof pasa una cadena a un float
                                        }
                                        else if (indice==3){
                                            indice++;
                                            tEmpresa[index].Variacion=atoi(temporal); //atof pasa una cadena a un float
                                        }
                                        //si quiero imprimir toda la informacion recogida por pantalla
                                        /*
                                        if(indice==4){//sera cuando ya halla recorrido lostres campos
                                            printf("Num empresa: %d --Nombre: %s Ingresos: %f Gastos: %f Variacion: %f-- \n\n\n",index,tEmpresa[index].Empresa, tEmpresa[index].Ingresos, tEmpresa[index].Gastos, tEmpresa[index].Variacion);
                                        }*/
                                    }
                            }
                    }
                    if(fclose(pfich) != 0){ //si no cierra da error
                            printf("Error al cerrar el fichero\n");}
 }
 void limpiado(char temporal[],int elementos){
     for (int i=0;i< elementos;i++ ){
        temporal[i]='\0';
     }

 }
int contarperdidas( Empresa *tEmpresa,int elementos)
{
    int contador=0;
    for(int i=0;i<elementos;i++){
        if (tEmpresa[i].Ingresos<tEmpresa[i].Gastos){
            contador++;
        }
    }
return contador;
}
int contarganacias( Empresa *tEmpresa,int elementos)
{
    int contador=0,esp=0;

    for(int i=0;i<elementos;i++){
        if (tEmpresa[i].Gastos<tEmpresa[i].Ingresos)
            contador++;
    }
return contador;
}
void guardardatos( Empresa *tEmpresa,int elementos){
     FILE *pfich;  //declaramos puntero de tipo archivo
     pfich = fopen(FICH02, "w"); //para escritura, si existe lo destrue, si no lo crea
     double ingresosestimados=0;
     if (pfich == NULL){
        printf("\n Error al crear el fichero");
     }
     else {
        for(int i=0;i<elementos;i++){
                ingresosestimados=((tEmpresa[i].Variacion/100)*tEmpresa[i].Ingresos)+tEmpresa[i].Ingresos; //Esto es temporal
        fprintf(pfich,"Nombre de empresa: %s -Valores Estimados 2022: %f\n",tEmpresa[i].Empresa,ingresosestimados);
        }
        if (fclose(pfich) != 0) {
            printf("\n Error al cerrar el fichero ");
        }
    }
}




