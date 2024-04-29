#include "../../functions.h"
#include "../Misc/global.h"

#include <math.h>
#include <cmath>
bool checkdir(neutrino & n,cylindre & cyl){
    double dot(double*,double*); //fonctionnera pour n.pos en entrée car n.pos est une adresse ! donc pas besoin d'affecter un pointeur
    double a,b,c,h[]={0,0,1};
    double w[3];for(int i=0;i<3;i++){w[i]=n.pos[i]-cyl.centre[i];/*cout<<w[i]<<endl*/;};

    a=dot(n.v,n.v) - pow(dot(n.v,h),2);
    b=2 * (dot(n.v,w) - (dot(n.v,h) * dot(w,h)));
    c=dot(w,w) - pow(dot(w,h),2) - cyl.rayon*cyl.rayon;
    
    double delta = b*b-4*a*c;

    if((delta > 0) & (dot(n.pos,n.v) < 0)){
       return true; 
    }

    else if(delta<=0){
        return false;
    }
    return false;
}

