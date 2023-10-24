#include "Element.h"
#ifndef UNTITLED_CONTENIDOR_H
#define UNTITLED_CONTENIDOR_H

class Contenidor{
private:
    struct node{
        Element *continugt;
        node *seguent;
    };
    node* *taula;
public:
    Contenidor(int nRow, int nCol);
    void afegirElement(Element *);
    Element* eliminarPerColumna(int col);
    Element* eliminarComodi();
    int getQuants();
    void mostrar();
};

#endif
