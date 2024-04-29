#ifndef GLOBAL_H
#define GLOBAL_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

extern int nbrinterac;  // Déclaration d'une variable globale
extern int nbrinteractot;
extern int photonemis;
extern double temps;
extern double theta_c;
extern double step;
extern int frames;
extern int maxPMs;
extern double tele_hauteur;
extern double tele_rayon;
extern double tele_centre_x;
extern double tele_centre_y;
extern double tele_centre_z;

extern double emiphot_hauteur;
extern double emiphot_rayon;
extern double emiphot_centre_x;
extern double emiphot_centre_y;
extern double emiphot_centre_z;

extern double boite_hauteur;
extern double boite_rayon;
extern double boite_centre_x;
extern double boite_centre_y;
extern double boite_centre_z;

extern double bornes_hauteur;
extern double bornes_rayon;
extern double bornes_centre_x;
extern double bornes_centre_y;
extern double bornes_centre_z;

extern std::vector<std::string> photonRAM;
extern std::ofstream photondata;

#endif
