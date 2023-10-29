#include "Element.h"

#ifndef UNTITLED_CONTENIDOR_H
#define UNTITLED_CONTENIDOR_H

class Contenidor {
private:
    int nFiles;
    struct node {
        Element *continugt;
        node *seguent;
    };
    node **taula;
public:
    Contenidor(int nRow, int nCol);

    bool afegirElement(Element *element, int posicio);

    Element *eliminarPerColumna(int col);

    Element *eliminarComodi(int row, int col);

    int getQuants();

    void mostrar();
};

#endif
