// Alba Maset, Sergio // Andres Alvaréz
#include <stdio.h>
#include <math.h>

float MiPotencia(float base,int e);
float Serie(float x,int terminos);
void DibujarTriangulo(int h);
void DibujarLinea(int longitud);

int main()
{
    int altura=0,prueba=0,e=0;
    float base=0;

    printf("Bienvenido a la practica 0\n");
    do
    {
        printf("Elija: \n1º Programa 1\n2º Programa 2\n3º Programa 3\n4º Salir\n");
        scanf("%d",&prueba);
        if(prueba==1) {
            printf("A continuacion, vamos a calcular una potencia\nCual es su base?\n");
            scanf("%f",&base);
            do{
                printf("A continuacion, introduzca el exponente positivo\n");
                scanf("%d",&e);
                if (e<0)
                    printf("No es positivo\n");
            }while(e<0);
            printf("La solucion es: %f\n", MiPotencia(base,e));
        }
        else if (prueba==2) {
             printf("A continuacion, vamos a calcular una serie.\nIntroduzca el valor de x: ");
             scanf("%f",&base);
             do{
                printf("Ahora introduzca el numero de terminos a sumar (tiene que ser positivo): ");
                scanf("%d",&e);
                if (e<0)
                    printf("No es positivo\n");
            }while(e<0);
            printf("El total es: %f\n",Serie(base, e));
        }
        else if (prueba==3) {
                printf("Dame la altura del triangulo\n");
                scanf("%d",&altura);
                DibujarTriangulo(altura);



        }
    }while(prueba!=4);
}
    float MiPotencia(float base,int e)
    {
        float resultado=1;
        for (int i=0;i<e;i++)
            {
            resultado = base * resultado;
            }
        return resultado;
    }
    float Serie(float x, int terminos)
    {
        float total=1;
        for (int contador=1;contador<=terminos;contador++)
        {
            if(contador%2==0) {
                total += MiPotencia(x,contador);
            }
            else
            {
                total -= MiPotencia(x,contador);
            }
        }
        return total;
    }
    void DibujarTriangulo(int h)
    {
        for (int i=h; i>0;i--)
        {

            DibujarLinea(i);
            printf("\n");

        }
    }
    void DibujarLinea(int longitud)
    {
        for(int b=1;b<=longitud;b++){
             printf("*");
        }

    }
