#ifndef CELLULEVIE_H
#define CELLULEVIE_H

#include "Cellule.h"

class CelluleVie : public Cellule {
public:
    bool status() const override; // Impl�mentation dans CelluleVie.cpp
    bool nextStatus(int voisinsVivants) const override; // Impl�mentation dans CelluleVie.cpp
};

#endif // CELLULEVIE_H
