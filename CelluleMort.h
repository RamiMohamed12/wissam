#ifndef CELLULEMORT_H
#define CELLULEMORT_H

#include "Cellule.h"

class CelluleMort : public Cellule {
public:
    bool status() const override; // Impl�mentation dans CelluleMort.cpp
    bool nextStatus(int voisinsVivants) const override; // Impl�mentation dans CelluleMort.cpp
};

#endif // CELLULEMORT_H
