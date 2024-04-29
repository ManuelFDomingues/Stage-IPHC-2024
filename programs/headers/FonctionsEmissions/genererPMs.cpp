#include "../../functions.h"
#include "../Misc/global.h"
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <tuple>
#include <math.h>
#include <cmath>


//=======================================================================================================================
// Generation du téléscope avec les paramètres donnés
void genererPMs(Reseau & reseau, cylindre & tele) {
std::vector<std::vector<double>> pmCoordinates;



// Fonction de hachage pour les positions (permet de vérifier si une positions de pm existe déja dans le réseau de façon la plus rapide (i guess))
//Pour ne pas avoir de doublons
struct hash_fn
{
    std::size_t operator() (const std::tuple<double, double, double>& tuple) const
    {
        std::size_t h1 = std::hash<double>{}(std::get<0>(tuple));
        std::size_t h2 = std::hash<double>{}(std::get<1>(tuple));
        std::size_t h3 = std::hash<double>{}(std::get<2>(tuple));
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};

std::unordered_set<std::tuple<double, double, double>, hash_fn> positions;


// Generer les PMs dans le cylindre par intervalles réguliers
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            for (int k = -1; k <= 1; k += 2) {
                for (double x = 0; x <= tele.rayon; x += 20.0) {
                    for (double y = 0; y <= tele.rayon; y += 20.0) {
                        for (double z = 0; z <= (tele.hauteur)/2; z += 9.0) {

                        double posx = i*x + tele.centre[0];
                        double posy = j*y + tele.centre[1];
                        double posz = k*z + tele.centre[2] + 100; //car le cylindre commence à -100
                        
                        // Regarde si le pm est dans le cylindre
                        double distance = sqrt(pow(x, 2) + pow(y, 2));
                        if (distance <= tele.rayon) {
                            
                            // Regarde si la position du pm existe déjà dans le réseau ou non
                            if (positions.find(std::make_tuple(posx, posy, posz)) == positions.end()) {
                                PM pm = {{posx, posy, posz}};
                                // Ajoute le PM au réseau
                                reseau.pms.push_back(pm);
                                // ajoute la position du PM au tableau
                                pmCoordinates.push_back({pm.pos[0], pm.pos[1], pm.pos[2]});
                                // Ajoute la position du PM à l'ensemble des positions  
                                positions.insert(std::make_tuple(posx, posy, posz));
                                // Si le nombre de PMs dépasse le nombre maximum de PMs : stop
                                if (reseau.pms.size() >= (std::size_t)maxPMs) {
                                    return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
