using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practica0csar
{
    class Vec3DE : Vectores
    {
        public override double[] LeerVector(ref double[] vector)
        {
            for (int o = 0; o < vector.Length; o++)
            {
                if (o == 0)
                {
                    Console.WriteLine("Dame la p");
                    vector[o] = Convert.ToDouble(Console.ReadLine());

                }
                else if (o == 1)
                {
                    Console.WriteLine("Dame la O");
                    vector[o] = Convert.ToDouble(Console.ReadLine());
                }
                else if (o == 2)
                {
                    Console.WriteLine("Dame la Q");
                    vector[o] = Convert.ToDouble(Console.ReadLine());
                }
            }
            return vector;
        }
        public override double[] SumarVectores(double[] vector1, double[] vector2)
        {
            double[] cartesiana1 = new double[3];
            double[] cartesiana2 = new double[3];
            //pasar priemr vector de esfericas a cartesianas
            for (int o = 0; o < vector1.Length; o++)
            {
                if (o == 0)
                {
                    cartesiana1[o] = vector1[0] * Math.Sin(vector1[1])* Math.Cos(vector1[2]);

                }
                else if (o == 1)
                {
                    cartesiana1[o] = vector1[0] * Math.Sin(vector1[1]) * Math.Sin(vector1[2]);
                }
                else if (o ==2)
                {
                    cartesiana1[o] = vector1[0] * Math.Cos(vector1[1]);
                }
                //segundo vector
                if (o == 0)
                {
                    cartesiana2[o] = vector2[0] * Math.Sin(vector2[1]) * Math.Cos(vector2[2]);
                }
                else if (o == 1)
                {
                    cartesiana2[o] = vector2[0] * Math.Sin(vector2[1]) * Math.Sin(vector2[2]);
                }
                else if (o == 2)
                {
                    cartesiana2[o] = vector2[0] * Math.Cos(vector2[1]);
                }
            }
            // sumamos cordenaas cartesianas
            for (int o = 0; o < 3; o++)
            {
                cartesiana1[o] += cartesiana2[o];
            }
            //pasamos ya sumado el vector a esfericas
            for (int o = 0; o < vector1.Length; o++)
            {
                if (o == 0)
                {
                    //esto es para calcular la p
                    cartesiana2[o] = Math.Sqrt(Math.Pow(cartesiana1[0],2) + Math.Pow(cartesiana1[1],2)+ Math.Pow(cartesiana1[2],2));
                }
                else if (o == 1)
                {//sacamos la o
                    cartesiana2[o] = Math.Acos(cartesiana1[2] / cartesiana2[0]);
                   
                }
                else if (o == 2)
                {
                    //sacamos el angulo 
                    cartesiana2[o] = Math.Atan((cartesiana1[1] / cartesiana1[0]));
                }
            }
            return cartesiana2;
        }
        public override void ImprimirPorPantalla(double[] vector)
        {

            for (int o = 0; o < 3; o++)
            {
                if (o == 0)
                {
                    Console.Write("El resultado de P es: " + vector[o]);
                }
                else if (o == 1)
                    Console.Write(", el de O:  " + vector[o]);
                else
                    Console.WriteLine(" y el de Q: " + vector[o] + "\n");
            }
        }
    
    }
}
