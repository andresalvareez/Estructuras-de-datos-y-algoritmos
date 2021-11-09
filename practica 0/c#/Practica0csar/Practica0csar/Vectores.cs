using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practica0csar
{
     abstract class Vectores
    {
        public abstract void ImprimirPorPantalla(double[] vector);
        public abstract double[] SumarVectores(double[] vector1, double[]vector2);
        public abstract double[] LeerVector(ref double[] vector);
    }
}
