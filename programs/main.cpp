#include "functions.h"
#include "headers/Misc/global.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <math.h>
#include <cstdio>
#include <string>

#include <chrono>
using namespace std;

//=======================================================================================================================
//=============================================== DÉFINITION DES STRUCTURES =============================================
//=======================================================================================================================

// Création du réseau
Reseau reseau;

//=======================================================================================================================
//============================================ DEFINITION DES ÉLÉMENTS DONNÉS ===========================================
//=======================================================================================================================




cylindre bornes; // zone génération du neutrino
cylindre emiphot; // zone d'émission de photon
cylindre boite; //boite
cylindre tele; //cylindre où se trouve le téléscope
neutrino n = {'m',0,1/(2*M_PI),300000,{},{}}; //vitesse à déterminer plus tard en fonciton de l'énergie du neutrino

vector<string> photonRAM;
ofstream photondata;



//=======================================================================================================================
//====================================== CALCULS LIÉS À LA TRAJECTOIRE DE LA PARTICULE ==================================
//=======================================================================================================================


void vitesse(neutrino & n){
    for(int i=0; i<3;i++){
        n.pos[i]+=step*n.v[i];
    }
}

//trajectoire du neutrino ()
void trajn(neutrino & n, ofstream & data){
        randposv(n,bornes);
    while(checkdir(n,boite) == false){
        randposv(n,bornes);
    }
    double posinit[3] = {n.pos[0],n.pos[1],n.pos[2]};
    void emiphoton(neutrino &, Reseau &, ofstream &); //prototype de la fonction car définie plus loin
    int i=0;
    while(i<frames && (disteucli(n.pos,2)<=disteucli(posinit))){
    //for(int i=0;i<frames;i++){
        temps = step*i;
        data<<temps<<"\t"<<n.pos[0]<<"\t"<<n.pos[1]<<"\t"<<n.pos[2]<<endl;
        if(disteucli(n.pos,2)<=emiphot.rayon){
        emiphoton(n, reseau,photondata);
        photonemis+=1;
        }
        vitesse(n);
        i++;
    }
}


//=======================================================================================================================
//=======================================================================================================================



int main(){

    auto start = std::chrono::high_resolution_clock::now();
    lireConfiguration("programs/config.txt",tele,bornes,boite,emiphot);
    genererPMs(reseau,tele);
    ofstream data;
    data.open("data/muon");
    photondata.open("data/photonstxt");

    trajn(n,data);

    photondata.close();
    data.close();

    cout<<"On a "<<nbrinteractot<<" intéractions pour "<<photonemis<<" photons émis."<<endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cout<<"Temps d'execution de "<<elapsed.count()*1e-9<<"secondes."<<endl;
    
    return 0;
}
 

//=======================================================================================================================
//=======================================================================================================================
//=======================================================================================================================
