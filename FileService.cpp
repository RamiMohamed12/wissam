#include "FileService.h"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

Grille FileService::ChargerDuFichier(const std::string& fichier) {
    std::ifstream inFile(fichier);
    if (!inFile) {
        throw std::runtime_error("Erreur lors de l'ouverture du fichier : " + fichier);
    }

    int largeur, longueur;
    inFile >> largeur >> longueur;

    if (largeur <= 0 || longueur <= 0) {
        throw std::invalid_argument("Dimensions invalides dans le fichier : " + fichier);
    }

    std::vector<std::vector<int>> etatInitial = LireEtatGrille(fichier);
    Grille grille(largeur, longueur);
    grille.InitialisationGrille(etatInitial);
    
    std::cout << "Grille chargée avec succès. Dimensions: " << largeur << "x" << longueur << std::endl;
    return grille;
}

void FileService::SauvegarderGrille(const Grille& grille, const std::string& fichier) {
    std::ofstream outFile(fichier);
    if (!outFile) {
        throw std::runtime_error("Impossible de créer le fichier : " + fichier);
    }

    outFile << grille.getLargeur() << " " << grille.getLongueur() << "\n";
    for (int i = 0; i < grille.getLongueur(); ++i) {
        for (int j = 0; j < grille.getLargeur(); ++j) {
            outFile << (grille.getEtat(i, j) ? "1" : "0") << " ";
        }
        outFile << "\n";
    }
}

void FileService::SauvegarderIteration(const Grille& grille, const std::string& outputDir, int iteration) {
    fs::create_directories(outputDir);
    std::string fichier = outputDir + "/iteration_" + std::to_string(iteration) + ".txt";
    SauvegarderGrille(grille, fichier);
}

std::vector<std::vector<int>> FileService::LireEtatGrille(const std::string& fichier) {
    std::ifstream inFile(fichier);
    if (!inFile) {
        throw std::runtime_error("Erreur lors de l'ouverture du fichier : " + fichier);
    }

    int largeur, longueur;
    inFile >> largeur >> longueur;

    std::vector<std::vector<int>> etat(longueur, std::vector<int>(largeur));
    for (int i = 0; i < longueur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            if (!(inFile >> etat[i][j])) {
                throw std::runtime_error("Erreur lors de la lecture des données");
            }
        }
    }
    return etat;
}
