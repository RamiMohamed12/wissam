#ifndef CELLULEMORT_H
#define CELLULEMORT_H

#include "Cellule.h"

class CelluleMort : public Cellule {
public:
    bool status() const override; // Implémentation dans CelluleMort.cpp
    bool nextStatus(int voisinsVivants) const override; // Implémentation dans CelluleMort.cpp
};

#endif // CELLULEMORT_H
