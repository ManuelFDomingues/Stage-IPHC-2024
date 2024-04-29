# Projet de Simulation de Particules

Ce projet consiste en un simulateur de particules utilisé pour étudier le comportement des neutrinos et la détection de photons via des photomultiplicateurs. Il simule le passage de particules à travers différents volumes et leur interaction avec des capteurs.

## Contributions

Les contributions au développement de ce projet ont été réparties comme suit entre les membres de l'équipe (elles ne concernent que le programme informatique et ne reflètent pas le travail fourni sur l'ensemble du stage) :

### Corentin Mary
#### Contributions globales
- recherches générales sur le fonctionnement des téléscopes à neutrinos, et sur leur simulations numériques.

#### fonctions du logiciel
- `genererPMs` : Cette fonction est responsable de la génération des photomultiplicateurs dans un cylindre spécifié par des paramètres. Elle place les PMs à intervalles réguliers et vérifie l'unicité de leur position à l'aide d'une structure de données optimisée.
- `emiphoton` : Gère l'émission des photons par les neutrinos.
- `photonmuon` : Calcule la trajectoire d'un photon émis par un muon.

### Manuel DOMINGUES
#### Contributions globales
- Recherches et documentations sur les téléscopes à neutrinos.
- Définition du domaine physique et mathématique.
- Fil rouge informatique et graphique.
#### fonctions du logiciel
- `disteucli` : Calcul de la distance euclidienne entre deux points dans l'espace.
- `dot` et `dotvec` : Fonctions pour calculer le produit scalaire entre deux vecteurs.
- `matripassage` et `multimatri` : Fonctions pour la création d'une matrice de passage et pour effectuer des produits matriciels, respectivement.
- `checkdir` : Vérifie si un muon passe bien dans un cylindre spécifié.
- `randposv` : Génère aléatoirement la position et la vitesse d'un neutrino.
- `basemuon` : Détermine une base pour les calculs relatifs au mouvement du muon.
- `photonmuon` : Calcule la trajectoire d'un photon émis par un muon.
- `vitesse` : Met à jour la position du neutrino en fonction de sa vitesse.
- `trajn` : Gère la trajectoire complète du neutrino.
- `checkPM` : Vérifie si les photons interagissent avec un photomultiplicateur.
- `emiphoton` : Gère l'émission des photons par les neutrinos.

## Installation et Utilisation

Le projet peut être compilé et exécuté en suivant ces étapes :
```bash
//se situer dans le bon répertoire est primordial
//executer au préalable cd [chemin vers Stage\ IPHC\ 2024v1.2/Logiciel]
make clean 
make run //les executer en deux temps, sinon une erreur ressort
```

### Fichier config.txt
Le fichier config.txt est sous la forme suivante :
```
step=0.00000001
//pas d'integration
//purement arbitraire pour l'instant, juste pour voir si ca fonctionne
frames=100000
maxPMs=500
tele_hauteur=200
tele_rayon=50
tele_centre_x=0
tele_centre_y=0
tele_centre_z=-100
```

Vous pouvez changer ces valeurs comme bon vous semble (il est cependant très important de surtout pas modifier les valeurs centre_x et centre_y, ainsis que de veiller à ce que centre_z soit égal à -hauteur/2)

### Production graphique
Si vous souhaitez avoir un aperçu graphique, c'est possible bien que très long avec la paramètres de base. Deux prévisualisations déjà faite est disponible dans le dossier ```Stage IPHC 2024``` sous le nom "visualisation1(2).gif".
Si vous désirez réellement essayer l'affichage direct, il vous suffit d'executer le programme python situé dans ```Logiciel/programs/visuels/``` nommé ```visus.py```. Il produira par défaut un fichier .gif que vous pouvez convertir en .mp4 (sur internet ou en utilisant FFMpeg par exemple). Par défaut le programme était censé produire un .mp4 mais sur les machines virtuel de l'unistra celà n'est pas possible (en tout cas je n'y suis pas parvenu).

### Précisions supplémentaires
#### Probabilité d'intéraction
Nos lectures étaient d'accords pour dire que nous devrions avoir en moyenne 330 photons émis par centimètre parcourus par le muon. Cette fonctionnalité (qui s'apparente à la probabilité d'émission du muon) est implémentée dans le programme mais n'a pour l'instant qu'une dimension qualitative, la valeur dépendant du nombre de frames ainsi que du pas d'intégration. Nous avons donc omis cette partie là mais elle est présente pour un possible futur développement de cet outil.

#### Outil de reconstruction
Par manque de temps et de connaissance en création d'interface, la partie reconstruction n'a pas été faite ici. Plusieurs pistes sont à voir, certaines ne nécessitant pas d'outil graphique. En allant du plus simple (regression linéaire) à des outils plus compliqués (méthode de Monte-Carlo sans doute). Elles sont elles aussi laissée pour un futur développement de l'outil.


## Remerciements
Des remerciements particuliers pour Arnault Albert, tuteur de stage et avant tout chercheur à l'IPHC et membre de l'équipe ANTARES/KM3NeT, qui nous à guidé tout au long de ce stage avec pédagogie et passion pour découvrir et reproduire les télescopes à neutrinos. Ainsi qu'à nos professeurs d'informatiques pour leur patience et leur aides pour les questions que nous avions sur ce projet.
