#include "../../functions.h"
#include "../Misc/global.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <cmath>
void checkPM(photon & g, Reseau & reseau){
    PM pm={{},0.45};
 
    /*ici on va vérifier si la traj du photon passe par un PM*/
    /*deux conditions : 
    distance entre g.pos(t=0) et le PM <=60m (distance avant absorption)
    angle cherenkov inclut dans l'angle d'observation */

    for(int i=0;i<maxPMs;i++){
        double r[3];
        for(int j=0;j<3;j++){
            r[j] = reseau.pms[i].pos[j];}
            double gpm[3] = {{r[0] - g.pos[0]},{r[1] - g.pos[1]},{r[2] - g.pos[2]}}; //vecteurs du photon au PM
            double dist = disteucli(gpm);
            if(dist<60){
                double scal = dot(gpm,g.v); //pdt scalaire entre Photon et Photon-PM
                double theta = atan(pm.rayon/dist); //angle apparent PM
                double thetap = acos(scal/(dist*g.V)); //angle entre déplacement photon et pm
                if(abs(thetap)<theta){
                    nbrinteractot+=1;
                    nbrinterac+=1;
                    std::ostringstream strg;
                    strg<<temps<<" "<<r[0]<<" "<<r[1]<<" "<<r[2];
                    std::string var = strg.str();
                    photonRAM.push_back(var);
                    }
            }
        }
}