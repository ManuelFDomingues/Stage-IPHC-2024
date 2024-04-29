#include "../../functions.h"

///produit matriciel fonctionnel uniquement pour matrice 3X3 et vecteur 3D
void multimatri(double a[3][3], double * b, double * c){
    for(int i=0;i<3;i++){
        c[i]=0;
            for(int k=0;k<3;k++){
                c[i] += a[i][k] * b[k];
            }
        }
    }