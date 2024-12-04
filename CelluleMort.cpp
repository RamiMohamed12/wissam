#include "CelluleMort.h"

bool CelluleMort::status() const {
    return false; // Cellule morte
}

bool CelluleMort::nextStatus(int voisinsVivants) const {
    return (voisinsVivants == 3);
}
