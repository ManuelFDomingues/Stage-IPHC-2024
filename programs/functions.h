#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>
#include <fstream>

struct neutrino{
    char type;
    double eV, proba;
    double V;
    double pos[3];
    double v[3];
};

struct cylindre{
    double hauteur, rayon, centre[3];
};

struct photon{
    double V;
    double theta, phi;
    double pos[3];
    double v[3];
};

struct PM{
     double pos[3];
    double rayon;
};

struct Reseau {
    std::vector<PM> pms;
};

// Déclarations des fonctions
double (*basemuon(neutrino& n, photon& g))[3];
void lireConfiguration(const std::string& nomFichier, cylindre& tele,cylindre & bornes, cylindre & boite, cylindre & emiphot);
void emiphoton(neutrino& n, Reseau & reseau, std::ofstream & photondata);
void checkPM(photon& g, Reseau& reseau);
void genererPMs(Reseau & reseau, cylindre & tele);
bool checkdir(neutrino& n, cylindre& cyl);
void photonmuon(neutrino& n, photon& g);
void randposv(neutrino& n, cylindre& c);
double disteucli(double *a, int dim = 3);
void matripassage(double A[3][3],double B[3][3], double Mpassage[3][3]);
void multimatri(double a[3][3], double * b, double * c);
double dot(double * a, double * b);


#endif // FUNCTIONS_H
