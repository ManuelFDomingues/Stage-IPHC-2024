#include "../../functions.h"
#include "../Misc/global.h"
#include <cmath>
#include <math.h>

double (*basemuon(neutrino & n, photon & g))[3]{ //coordonnées sphériques en convention (r,theta,phi) (physique)
                                                 //la fonction retourne un pointeur vers un tableau de 3 éléments double
    
    double thmu = atan(n.v[1]/n.v[0]);
    double phimu = copysign(1.0,n.v[1])*acos(n.v[2]/n.V);

    double Xs[3] = {1.0 , thmu , phimu - M_PI/2.0}; //vecteur x en sphérique puis passage cartésien
    double Xc[3] = {Xs[0]*cos(Xs[1])*sin(Xs[2]) , Xs[0]*sin(Xs[1])*sin(Xs[2]) , Xs[0]*cos(Xs[2]) } ;
    double direct[3];
    for(int i=0;i<3;i++){direct[i]=n.v[i]/n.V;} //vecteur directeur de nv
    
    //produit vectoriel pour avoir le vecteur y
    double y[3] = {
        direct[1] * Xc[2] - direct[2] * Xc[1],
        direct[2] * Xc[0] - direct[0] * Xc[2],
        0
    };
    //pointeur vers un tableau de 3 éléments doubles.
    //new ici est obligatoire
    double (*basemu)[3] = new double[3][3]{
                       {Xc[0],Xc[1],Xc[2]},
                       {y[0],y[1],y[2]},
                       {direct[0],direct[1],direct[2]}
                       };
 
    return basemu;
}