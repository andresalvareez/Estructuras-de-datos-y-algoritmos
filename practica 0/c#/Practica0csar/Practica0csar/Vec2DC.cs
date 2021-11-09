using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practica0csar
{
    class Vec2DC : Vectores
    {
        public override double[] LeerVector(ref double[] vector)
        {
            for (int o= 0; o< vector.Length;o++)
            {//pedimos cordenadas 
                if (o == 0)
                {
                    Console.WriteLine("Dame la x");
                    vector[o] = Convert.ToDouble(Console.ReadLine());

                }
                else if  (o == 1)
                {
                    Console.WriteLine("Dame la y");
                    vector[o] = Convert.ToDouble(Console.ReadLine());
                }
            }
            return vector;
        }
        public override double[] SumarVectores(double[] vector1, double[] vector2)
        {
            for(int o= 0;o <2;o++)
            {//hacemos la suma
                vector1[o] += vector2[o];
            }

            return vector1;
        }
        public override void ImprimirPorPantalla(double[] vector)
        {
            for(int o=0; o <2;o++) 
            {//imrpimimos por pantalla
                if (o == 0)
                {
                    Console.Write("El resultado de X es: " + vector[o]);
                }
                else
                    Console.WriteLine(" y el de Y:  " + vector[o]+"\n");
                
            }
            
        }
    }
}
