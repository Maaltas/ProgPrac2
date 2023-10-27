#include "Contenidor.h"

Contenidor::Contenidor(int nRow, int nCol) {
    this->nRow = nRow;
    this->nCol = nCol;
    this->array = new Element*[nRow];
    for (int i = 0; i < nRow; i++) {
        this->array[i] = new Element[nCol];
    }
}

void Contenidor::afegirElement(Element *) {

}

Element *Contenidor::eliminarPerColumna(int col) {

}

Element *Contenidor::eliminarComodi() {
    return nullptr;
}

int Contenidor::getQuants() {
    return 0;
}

void Contenidor::mostrar() {
    
}



