#include "../../functions.h"
#include "../Misc/global.h"
#include <math.h>
#include <cmath>

//fonction qui fait passer les coordonnées du photon dans la base du muon
void photonmuon(neutrino & n, photon & g){
    double(*basemu)[3] = basemuon(n,g); 
    double bT[3][3] = {{1,0,0},{0,1,0},{0,0,1}}; //base du téléscope est cartésienne orthonormée
    // convertir les coordonnées du photon dans le x, y et z du muon
    double xPhotonMuon = g.V * sin(g.theta) * cos(g.phi);
    double yPhotonMuon = g.V * sin(g.theta) * sin(g.phi);
    double zPhotonMuon = g.V * cos(g.theta);

    // on obtient un vecteur 3D pour le photon
    double photonMuon[3] = {xPhotonMuon, yPhotonMuon, zPhotonMuon};
    double Mpassage[3][3];//matrice de passage entre repère muon et repère téléscope
    double photonTelescope[3];
    
    matripassage(basemu,bT,Mpassage);
    multimatri(Mpassage,photonMuon,photonTelescope);

    for(int i=0;i<3;i++){g.v[i] = photonTelescope[i];}

    delete[] basemu;
}

