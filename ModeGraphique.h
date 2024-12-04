#ifndef MODEGRAPHIQUE_H
#define MODEGRAPHIQUE_H

#include <SFML/Graphics.hpp>
#include "Grille.h"

class ModeGraphique {
private:
    Grille grille;
    sf::RenderWindow window;
    int largeurCellule;
    int longueurCellule;
    int refreshRate;

    void drawGrid();

public:
    ModeGraphique(const Grille& initialGrille, int refreshRate = 500);
    void run();
};

#endif // MODEGRAPHIQUE_H
