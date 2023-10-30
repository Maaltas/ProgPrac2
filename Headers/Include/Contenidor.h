#include "Element.h"

#ifndef UNTITLED_CONTENIDOR_H
#define UNTITLED_CONTENIDOR_H

class Contenidor {
private:
    int nFiles;
    int nCol;
    struct node {
        Element *contingut;
        node *seguent;
    };
    node **taula;
    void inicialitzarTaula(){
        for (int i=0; i<nCol;i++){
            this->taula[i] = new node();
        }
    }
public:
    Contenidor(int nRow, int nCol);

    bool afegirElement(Element* element, int posicio);

    Element* eliminarPerColumna(int col);

    void eliminarComodi();

    int getQuants();

    void mostrar();
};

#endif
