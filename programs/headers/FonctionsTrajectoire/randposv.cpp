#include "../../functions.h"
#include "../Misc/global.h"
#include <random>

//Fonction génératrice du muon

void randposv(neutrino & n, cylindre & c){/*coordonnées cylindriques converties ensuite*/
        std::uniform_real_distribution<double> rH(-c.hauteur/2.0,c.hauteur/2.0);
        std::uniform_real_distribution<double> rR(-c.rayon,c.rayon);
        std::uniform_real_distribution<double> rang(0,2*M_PI); //pour les angles
        std::random_device rd;
        std::default_random_engine generator(rd());

        double v = n.V;
        double theta = rang(generator);
        double r = rR (generator);

        n.pos[0] =  r*cos(theta); 
        n.pos[1] =  r*sin(theta);
        n.pos[2] =  rH(generator);

        double theta2 = rang(generator);
        double phi = rang(generator);

        n.v[0] = v * sin(phi) * cos(theta2);
        n.v[1] = v * sin(phi) * sin(theta2);
        n.v[2] = v * cos(phi);
}