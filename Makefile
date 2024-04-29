CC = g++
CFLAGS = -Wall -g
LDFLAGS =




# Chemins d'inclusion des en-têtes
INCLUDES = -I./programs \
           -I./Logiciel/programs/headers/Misc \
           -I./Logiciel/programs/headers/FonctionsEmissions \
           -I./Logiciel/programs/headers/Fonctionsmath \
           -I./Logiciel/programs/headers/FonctionsTrajectoire

# Tous les fichiers sources
SOURCES = programs/main.cpp \
          programs/headers/Misc/global.cpp \
          programs/headers/Misc/lireConfiguration.cpp \
          programs/headers/FonctionsEmissions/basemuon.cpp \
          programs/headers/FonctionsEmissions/checkPM.cpp \
          programs/headers/FonctionsEmissions/genererPMs.cpp \
          programs/headers/FonctionsEmissions/photonmuon.cpp \
          programs/headers/FonctionsEmissions/emiphoton.cpp \
          programs/headers/Fonctionsmath/disteucli.cpp \
          programs/headers/Fonctionsmath/dot.cpp \
          programs/headers/Fonctionsmath/matripassage.cpp \
          programs/headers/Fonctionsmath/multimatri.cpp \
          programs/headers/FonctionsTrajectoire/randposv.cpp \
          programs/headers/FonctionsTrajectoire/checkdir.cpp

# Nom du fichier exécutable à générer
EXECUTABLE = main

#nom du fichier python que gère l'affichage graphique
#PYTHON_SCRIPT = programs/visuels/visus.py
#Retirer les commentaires, normalement ça devrait fonctionner, mais sur mon ordinateur (machine virtuelle de l'université) python semble être mal installé
#le programme refuse donc de lancer python. Vous pouvez cependant lancer l'executable qui se trouve dans le fichier programs/visuels, cela fonctionnera
# Règle par défaut
all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@ $(LDFLAGS)

run: $(EXECUTABLE)
	clear
	./$(EXECUTABLE)
#	python $(PYTHON_SCRIPT)

clean:
	rm -f $(EXECUTABLE)
	rm -f output.gif
	clear

.PHONY: all run clean
