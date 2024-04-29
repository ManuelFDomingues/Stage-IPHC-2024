#include "../../functions.h"
#include "global.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>


//fonction de lecture du fichier config.txt
void lireConfiguration(const std::string& nomFichier, cylindre& tele,cylindre & bornes, cylindre & boite, cylindre & emiphot) {
    std::ifstream fichierConfig(nomFichier);
    std::string ligne;

    if (!fichierConfig) {
        std::cerr << "Erreur lors de l'ouverture du fichier de configuration." << std::endl;
        exit(1);
    }

    while (std::getline(fichierConfig, ligne)) {
        size_t commentIndex = ligne.find("//");  // Recherche du début d'un commentaire
        if (commentIndex != std::string::npos) {
            ligne = ligne.substr(0, commentIndex);  // Coupe la ligne au début du commentaire
        }

        if (ligne.empty()) continue;  // Ignore les lignes vides ou devenu vides après la coupe
        
        std::stringstream ss(ligne);
        std::string cle;
        double valeur;
        if (std::getline(ss, cle, '=') && ss >> valeur) {
            if (cle == "step") step = valeur;
            else if (cle == "frames") frames = static_cast<int>(valeur);
            else if (cle == "maxPMs") maxPMs = static_cast<int>(valeur);
            else if (cle == "tele_hauteur") tele.hauteur = valeur;
            else if (cle == "tele_rayon") tele.rayon = valeur;
            else if (cle == "tele_centre_x") tele.centre[0] = valeur;
            else if (cle == "tele_centre_y") tele.centre[1] = valeur;
            else if (cle == "tele_centre_z") tele.centre[2] = valeur;

            else if (cle == "emiphot_hauteur") emiphot.hauteur = valeur;
            else if (cle == "emiphot_rayon") emiphot.rayon = valeur;
            else if (cle == "emiphot_centre_x") emiphot.centre[0] = valeur;
            else if (cle == "emiphot_centre_y") emiphot.centre[1] = valeur;
            else if (cle == "emiphot_centre_z") emiphot.centre[2] = valeur;

            else if (cle == "boite_hauteur") boite.hauteur = valeur;
            else if (cle == "boite_rayon") boite.rayon = valeur;
            else if (cle == "boite_centre_x") boite.centre[0] = valeur;
            else if (cle == "boite_centre_y") boite.centre[1] = valeur;
            else if (cle == "boite_centre_z") boite.centre[2] = valeur;

            else if (cle == "bornes_hauteur") bornes.hauteur = valeur;
            else if (cle == "bornes_rayon") bornes.rayon = valeur;
            else if (cle == "bornes_centre_x") bornes.centre[0] = valeur;
            else if (cle == "bornes_centre_y") bornes.centre[1] = valeur;
            else if (cle == "bornes_centre_z") bornes.centre[2] = valeur;
        }
    }
}