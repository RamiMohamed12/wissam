#include "CelluleVie.h"

bool CelluleVie::status() const {
    return true; // Cellule vivante
}

bool CelluleVie::nextStatus(int voisinsVivants) const {
    return (voisinsVivants == 2 || voisinsVivants == 3);
}
