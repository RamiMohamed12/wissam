#include "ModeConsole.h"
#include "FileService.h"
#include <stdexcept>
#include <string>


ModeConsole::ModeConsole(const std::string& inputFile, const std::string& outputDir)
    : inputFile(inputFile), outputDir(outputDir) {}

void ModeConsole::run() {
    Grille grille = FileService::ChargerDuFichier(inputFile);
    Jeu jeu(grille.getLargeur(), grille.getLongueur(), 10); // 10 itérations par défaut
    jeu.Simulation(outputDir);
}
