#include "../../functions.h"

///création d'une matrice de passage
void matripassage(double A[3][3],double B[3][3], double Mpassage[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            Mpassage[i][j] = dot(A[j],B[i]);
        }
    }
}