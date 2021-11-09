using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practica0csar
{
    class Vec2DP : Vectores
    {
        public override double[] LeerVector(ref double[] vector)
        {
            for (int o = 0; o < vector.Length; o++)
            {
                if (o == 0)
                {
                    Console.WriteLine("Dame la x");
                    vector[o] = Convert.ToDouble(Console.ReadLine());

                }
                else if (o == 1)
                {
                    Console.WriteLine("Dame la y");
                    vector[o] = Convert.ToDouble(Console.ReadLine());
                }
            }
            return vector;
        }
        public override double[] SumarVectores(double[] vector1, double[] vector2)
        {
            double[] aux1 = new double[2];
            double[] final = new double[2];
            double x1, y1, x2, y2;

            //pasar a coordenadas cartesianas
            x1 = vector1[0] * Math.Cos(vector1[1]);
            y1 = vector1[0] * Math.Sin(vector1[1]);
            x2 = vector2[0] * Math.Cos(vector2[1]);
            y2 = vector2[0] * Math.Sin(vector2[1]);
            //sumar coordenadas
            aux1[0] = x1 + x2;
            aux1[1] = y2 + y2;
            final[0] = Math.Sqrt(Math.Pow(aux1[0], 2) + Math.Pow(aux1[1], 2));
            final[1] = Math.Atan(aux1[1] / aux1[0]);

            return final;
        }
        public override void ImprimirPorPantalla(double[] vector)
        {
            for (int o = 0; o < 2; o++)
            {
                if (o == 0)
                    //irmpirmosp or pantallla
                {
                    Console.Write("El resultado de R es: " + vector[o]);
                }
                else
                    Console.WriteLine(" y el de O:  " + vector[o] + "\n");
            }
        }
    }
}
