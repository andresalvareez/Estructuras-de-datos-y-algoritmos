using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practica0csar
{
    class Vec3DC : Vectores
    {

        //Esta clase es igual que la del ejercicio uno pero ampliando un hueco mas en el arry ya que hay una dimension mas
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
                else if (o == 2)
                {
                    Console.WriteLine("Dame la z");
                    vector[o] = Convert.ToDouble(Console.ReadLine());
                }
            }          
            return vector;
        }
        public override double[] SumarVectores(double[] vector1, double[] vector2)
        {
            for (int o = 0; o < 3; o++)
            {
                vector1[o] += vector2[o];
            }

            return vector1;
        }
        public override void ImprimirPorPantalla(double[] vector)
        {
            for (int o = 0; o < 3; o++)
            {
                if (o == 0)
                {
                    Console.Write("El resultado de X es: " + vector[o]);
                }
                else if (o == 1)
                    Console.Write(", el de Y:  " + vector[o]);
                else
                    Console.WriteLine(" y el de Z: " + vector[o]+"\n");

            }
        }
    }
}
