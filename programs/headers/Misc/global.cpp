#include "global.h"
#include <vector>
#include <string>
#include <math.h>
int nbrinterac=0;  // Déclaration d'une variable globale
int nbrinteractot=0;
int photonemis=0;
double temps = 0; //permet de garder compte du temps (utile dans la suite)
double theta_c = 41.2 * M_PI / 180; /*angle de Tcherenkov en radian pour une vitesse réduite = 1*/
double step;
int frames;
int maxPMs;
double tele_hauteur;
double tele_rayon;
double tele_centre_x;
double tele_centre_y;
double tele_centre_z;

double emiphot_hauteur;
double emiphot_rayon;
double emiphot_centre_x;
double emiphot_centre_y;
double emiphot_centre_z;

double boite_hauteur;
double boite_rayon;
double boite_centre_x;
double boite_centre_y;
double boite_centre_z;

double bornes_hauteur;
double bornes_rayon;
double bornes_centre_x;
double bornes_centre_y;
double bornes_centre_z;