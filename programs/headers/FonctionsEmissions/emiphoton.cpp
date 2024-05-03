#include "../../functions.h"
#include "../Misc/global.h"
#include <random>
#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>

//fonction qui gère l'émission du photon
void emiphoton(neutrino & n, Reseau & reseau, std::ofstream & photondata){
    nbrinterac=0;
    photonRAM.clear();
    std::uniform_real_distribution<double> rang(0,2*M_PI); //pour les angles
    std::uniform_real_distribution<double> rem(0.2,1); //pour l'émission
    std::random_device rd;
    std::default_random_engine generator(rd());
    //if(rem(generator)>n.proba){
        photon g;
        g.pos[0]=n.pos[0];
        g.pos[1]=n.pos[1];
        g.pos[2]=n.pos[2];
        g.theta =theta_c;
        g.phi = rang(generator);

        photonmuon(n,g);
        g.V = 0.75*n.V;
        checkPM(g,reseau);

        for(std::size_t i=0;i<photonRAM.size();i++){std::cout<<photonRAM[i]<<std::endl;photondata<<photonRAM[i]<<std::endl;}
        
        //}

}
