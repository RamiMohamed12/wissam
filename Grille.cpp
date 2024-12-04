#include "Grille.h"
#include "CelluleVie.h"
#include "CelluleMort.h"
#include <stdexcept>
#include <iostream>  // Include this for std::cout and std::endl

using namespace std;

Grille::Grille(int largeur, int longueur) : largeur(largeur), longueur(longueur) {
    grid.resize(longueur, std::vector<Cellule*>(largeur, nullptr));
}

Grille::~Grille() {
    for (auto& row : grid) {
        for (auto& cellule : row) {
            delete cellule;
        }
    }
}

void Grille::InitialisationGrille(const std::vector<std::vector<int>>& etatInitial) {
    for (int i = 0; i < longueur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            delete grid[i][j]; // Supprime toute cellule existante
            if (etatInitial[i][j] == 1) {
                grid[i][j] = new CelluleVie();
            }
            else {
                grid[i][j] = new CelluleMort();
            }
        }
    }

    // Debug: Print the initialized grid
    for (int i = 0; i < longueur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            std::cout << (grid[i][j]->status() ? "1 " : "0 ");
        }
        std::cout << std::endl;
    }
}

bool Grille::getEtat(int x, int y) const {
    if (x < 0 || x >= longueur || y < 0 || y >= largeur) {
        throw std::out_of_range("Indices hors limites dans Grille::getEtat");
    }

    if (!grid[x][y]) {
        throw std::runtime_error("Cellule non initialisée dans Grille::getEtat");
    }

    return grid[x][y]->status();
}

int Grille::wrapIndex(int index, int max) const {
    if (max <= 0) {
        throw std::invalid_argument("wrapIndex: max doit être supérieur à 0.");
    }

    if (index < 0) {
        return (index % max + max) % max; // Gestion des indices négatifs
    }
    if (index >= max) {
        return index % max; // Gestion des indices supérieurs à max - 1
    }
    return index; // Indice valide
}

int Grille::NombreVoisinsVivants(int x, int y) const {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (!(i == 0 && j == 0)) {
                int nx = wrapIndex(x + i, longueur);
                int ny = wrapIndex(y + j, largeur);
                if (grid[nx][ny]->status()) {
                    ++count;
                }
            }
        }
    }
    return count;
}

void Grille::SetCelluleEtat(int x, int y, bool etat) {
    delete grid[x][y];
    if (etat) {
        grid[x][y] = new CelluleVie();
    }
    else {
        grid[x][y] = new CelluleMort();
    }
}

Cellule* Grille::GetCelluleEtat(int x, int y) const {
    int wrappedX = wrapIndex(x, longueur);
    int wrappedY = wrapIndex(y, largeur);
    return grid[wrappedX][wrappedY];
}

void Grille::MiseAJourGrille() {
    std::vector<std::vector<bool>> prochainsEtats(longueur, std::vector<bool>(largeur));

    for (int i = 0; i < longueur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            int voisinsVivants = NombreVoisinsVivants(i, j);
            prochainsEtats[i][j] = grid[i][j]->status()
                ? (voisinsVivants == 2 || voisinsVivants == 3)
                : (voisinsVivants == 3);
        }
    }

    for (int i = 0; i < longueur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            SetCelluleEtat(i, j, prochainsEtats[i][j]);
        }
    }
}
