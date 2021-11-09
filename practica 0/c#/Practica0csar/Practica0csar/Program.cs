using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practica0csar
{
    class Program
    {
        static void Main(string[] args)
        {
            Double[] vector1 = new double[3];
            Double[] vector2 = new double[3];
            Double[] vector3 = new double[3];
            Vec2DC eje1 = new Vec2DC();
            Vec3DC eje2 = new Vec3DC();
            Vec2DP eje3 = new Vec2DP();
            Vec3DE eje4 = new Vec3DE();


            int menu = 0;
            Console.WriteLine("Bienvenido al menu de la Practica 0\n");
            //hacemos un menu
            do
            {
                Console.WriteLine("1º Sumar dos vectores de 2 dimensiones en coordenadas cartesianas\n2º Sumar dos vectores de 3 dimensiones en coordenadas cartesianas\n3º Sumar dos vectores de 2 dimensiones en coordenadas polares\n4º Sumar dos vectores de 3 dimensiones en coordenadas esféricas\n5º Salir");
                menu= Convert.ToInt32(Console.ReadLine());
                //primer ejrcicio
                if (menu == 1)
                {
                    // invocamos funciones de leer
                    Console.WriteLine("Dame las cordenadas del primer vector.");
                    vector1 = eje1.LeerVector(ref vector1);
                    Console.WriteLine("Dame las cordenadas del segundo vector.");
                    vector2 = eje1.LeerVector(ref vector2);
                    //inicializamos en casa de presionar ejercicio 1. Al ponerlo aqui consumimos menos recuros
                    double[] suma = new double[2]; //la usamos para guardar el valor de la suma y pasarlo en el main a la siguiente funcion que imprimira por pantalla
                    suma = eje1.SumarVectores(vector1, vector2); // invocamos funciones de sumar
                    eje1.ImprimirPorPantalla(suma); // suma ya tiene guardado todo y le pasamos la info para que la imprima

                }
                else if (menu == 2)
                { //Similar al ejercicio 1
                    Console.WriteLine("Dame las cordenadas del primer vector.\n ");
                    vector1 = eje2.LeerVector(ref vector1);
                    Console.WriteLine("Dame las cordenadas del segundo vector.\n");
                    vector2 = eje2.LeerVector(ref vector2);
                    //inicializamos en casa de presionar ejercicio 1. Al ponerlo aqui consumimos menos recuros
                    double[] suma = new double[3];
                    suma = eje2.SumarVectores(vector1, vector2);
                    eje2.ImprimirPorPantalla(suma);
                }
                else if (menu == 3)
                {// similar al ejercicio 1
                    Console.WriteLine("Dame las cordenadas del primer vector.\n ");
                    vector1 = eje3.LeerVector(ref vector1);
                    Console.WriteLine("Dame las cordenadas del segundo vector.\n");
                    vector2 = eje3.LeerVector(ref vector2);
                    //inicializamos en casa de presionar ejercicio 1. Al ponerlo aqui consumimos menos recuros
                    double[] suma = new double[2];
                    suma = eje3.SumarVectores(vector1, vector2);
                    eje3.ImprimirPorPantalla(suma);
                }
                else if (menu ==4)
                {
                    //similar el ejercicio 1
                    Console.WriteLine("Dame las cordenadas del primer vector.\n ");
                    vector1 = eje4.LeerVector(ref vector1);
                    Console.WriteLine("Dame las cordenadas del segundo vector.\n");
                    vector2 = eje4.LeerVector(ref vector2);
                    //inicializamos en casa de presionar ejercicio 1. Al ponerlo aqui consumimos menos recuros
                    double[] suma = new double[3];
                    suma = eje4.SumarVectores(vector1, vector2);
                    eje4.ImprimirPorPantalla(suma);
                }
            } while (menu!=5);
            Console.WriteLine("asdasdadad");
            Console.ReadLine();
        }
    }
}
