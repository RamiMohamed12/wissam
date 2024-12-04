#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <filesystem> // Include for std::filesystem
#include "Jeu.h"
#include "FileService.h" // Include for FileService

namespace fs = std::filesystem; // Alias for easier usage

Jeu::Jeu(int largeur, int longueur, int iterations)
    : grille(largeur, longueur), iterations(iterations) {}

Jeu::Jeu(const Grille& grille, int iterations)
    : grille(grille), iterations(iterations) {}

void Jeu::Simulation(const std::string& outputDir) {
    // Create output directory if it doesn't exist
    fs::create_directories(outputDir);
    
    std::cout << "Début de la simulation pour " << iterations << " itérations" << std::endl;
    
    // Save initial state
    FileService::SauvegarderIteration(grille, outputDir, 0);
    
    // Run simulation
    for (int i = 1; i <= iterations; ++i) {
        std::cout << "Itération " << i << "/" << iterations << std::endl;
        
        // Update grid state
        MiseAJourGrille();
        
        // Save current state
        FileService::SauvegarderIteration(grille, outputDir, i);
    }
    
    std::cout << "Simulation terminée" << std::endl;
}

void Jeu::MiseAJourGrille() {
    std::vector<std::vector<bool>> prochainsEtats(grille.getLongueur(), std::vector<bool>(grille.getLargeur()));

    for (int x = 0; x < grille.getLongueur(); ++x) {
        for (int y = 0; y < grille.getLargeur(); ++y) {
            int voisinsVivants = grille.NombreVoisinsVivants(x, y);
            prochainsEtats[x][y] = grille.getEtat(x, y)
                ? (voisinsVivants == 2 || voisinsVivants == 3)
                : (voisinsVivants == 3);
        }
    }

    for (int x = 0; x < grille.getLongueur(); ++x) {
        for (int y = 0; y < grille.getLargeur(); ++y) {
            grille.SetCelluleEtat(x, y, prochainsEtats[x][y]);
        }
    }
}
