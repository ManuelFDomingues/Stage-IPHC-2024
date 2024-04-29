#include "../../functions.h"

///produit scalaire
double dot(double * a, double * b){
    double psc=0;
    for(int i=0;i<3;i++){
        psc+=( a[i] * b[i] );
    }
    return psc;
}