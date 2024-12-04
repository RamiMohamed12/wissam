#ifndef FILESERVICE_H
#define FILESERVICE_H

#include "Grille.h"
#include <string>
#include <vector>

class FileService {
public:
    static Grille ChargerDuFichier(const std::string& fichier);
    static void SauvegarderGrille(const Grille& grille, const std::string& fichier);
    static void SauvegarderIteration(const Grille& grille, const std::string& outputDir, int iteration);
    static std::vector<std::vector<int>> LireEtatGrille(const std::string& fichier);
};

#endif // FILESERVICE_H
