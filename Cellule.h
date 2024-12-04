#ifndef CELLULE_H
#define CELLULE_H

class Cellule {
public:
    virtual ~Cellule() = default;
    virtual bool status() const = 0; // M�thode virtuelle pure
    virtual bool nextStatus(int voisinsVivants) const = 0; // M�thode virtuelle pure
};

#endif // CELLULE_H
