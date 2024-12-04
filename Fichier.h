#ifndef FICHIER_H
#define FICHIER_H

#include "Grille.h"
#include <string>

class Fichier {
private:
    std::string nomFichier;

public:
    explicit Fichier(const std::string& nom);
    Grille LireFichier() const;
    void EcrireFichier(const Grille& grille, const std::string& fichierSortie) const;
};

#endif // FICHIER_H
