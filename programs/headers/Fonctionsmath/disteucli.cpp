#include "../../functions.h"
#include <math.h>
#include <cmath>

///norme euclidienne
double disteucli(double * a,int dim){
    double dist = 0;
    for(int i=0;i<dim;i++){dist += pow(a[i],2);}
    return sqrt(dist);
}