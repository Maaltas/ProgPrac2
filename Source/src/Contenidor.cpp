#include <iostream>
using namespace std;
#include "Contenidor.h"

Contenidor::Contenidor(int nRow, int nCol) {
    this->nRow = nRow;
    this->nCol = nCol;
    this->taula = new node*[6];
}

void Contenidor::afegirElement(Element * element, int posicio) {
    if (this->taula[posicio]->continugt == nullptr){
        this->taula[posicio]->continugt = element;
    } else if (this->taula[posicio]->seguent->continugt == nullptr){
        this->taula[posicio]->seguent->continugt = element;
    } else if (this->taula[posicio]->seguent->seguent->continugt == nullptr){
        this->taula[posicio]->seguent->seguent->continugt = element;
    } else if (this->taula[posicio]->seguent->seguent->seguent->continugt == nullptr){
        this->taula[posicio]->seguent->seguent->seguent->continugt = element;
    }
}

Element *Contenidor::eliminarPerColumna(int col) {
    this->taula[col]->seguent= nullptr;
    this->taula[col]->continugt= nullptr;
}

Element *Contenidor::eliminarComodi() {

}

int Contenidor::getQuants() {
    return 0;
}

void Contenidor::mostrar() {
    node* po = new node*[sizeof(taula)];
    for (int x=0; x<2;x++){
        for (int j=0; j< sizeof(taula); j++){

        }
        for (int i=0; i<sizeof(taula); i++){
            if (this->taula[i]->continugt != nullptr){
                cout << this->taula[i]->continugt->getSimbol();
            }
            cout << "   ";
        }

    }
}



