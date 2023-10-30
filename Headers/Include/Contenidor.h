#include "Element.h"

#ifndef UNTITLED_CONTENIDOR_H
#define UNTITLED_CONTENIDOR_H

class Contenidor {
private:
    int nFiles;
    int nCol;
    struct node {
        Element *continugt;
        node *seguent;
    };
    node **taula;
public:
    Contenidor(int nRow, int nCol);

    bool afegirElement(Element *element, int posicio);

    void eliminarPerColumna(int col);

    void eliminarComodi(int row, int col);

    int getQuants();

    void mostrar();
};

#endif
