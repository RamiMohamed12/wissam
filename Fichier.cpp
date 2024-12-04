#include "Fichier.h"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <string>


Fichier::Fichier(const std::string& nom) : nomFichier(nom) {}

Grille Fichier::LireFichier() const {
    std::ifstream inFile(nomFichier);
    if (!inFile) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + nomFichier);
    }

    int longueur, largeur;
    inFile >> longueur >> largeur;

    std::vector<std::vector<int>> etatInitial(longueur, std::vector<int>(largeur));
    for (int i = 0; i < longueur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            inFile >> etatInitial[i][j];
        }
    }

    Grille grille(largeur, longueur);
    grille.InitialisationGrille(etatInitial);
    return grille;
}

void Fichier::EcrireFichier(const Grille& grille, const std::string& fichierSortie) const {
    std::ofstream outFile(fichierSortie);
    if (!outFile) {
        throw std::runtime_error("Impossible d'écrire dans le fichier : " + fichierSortie);
    }

    outFile << grille.getLongueur() << " " << grille.getLargeur() << "\n";
    for (int i = 0; i < grille.getLongueur(); ++i) {
        for (int j = 0; j < grille.getLargeur(); ++j) {
            outFile << grille.GetCelluleEtat(i, j) << " ";
        }
        outFile << "\n";
    }
}
