#include <iostream>

using namespace std;

#include "Contenidor.h"

Contenidor::Contenidor(int nRow, int nCol) {
    this->taula = new node *[nCol];
    this->nFiles = nRow;
    for (int i = 0; i < nCol; i++) {
        if (!afegirElement(new Element, i)) { // si no s'ha pogut afegir l'element, seguent columna
            break;
        }
    }
}

bool Contenidor::afegirElement(Element *element, int posicio) {
    /*if (this->taula[posicio]->continugt == nullptr) {
        this->taula[posicio]->continugt = element;
    } else if (this->taula[posicio]->seguent->continugt == nullptr) {
        this->taula[posicio]->seguent->continugt = element;
    } else if (this->taula[posicio]->seguent->seguent->continugt == nullptr) {
        this->taula[posicio]->seguent->seguent->continugt = element;
    } else if (this->taula[posicio]->seguent->seguent->seguent->continugt == nullptr) {
        this->taula[posicio]->seguent->seguent->seguent->continugt = element;
    }*/

    // fer el mateix amb un bucle
    node *posicioActual = this->taula[posicio];
    for (int i = 0; i < nFiles; i++) {
        if (posicioActual->continugt == nullptr) {
            posicioActual->continugt = element;
            return true;
        }
        posicioActual = posicioActual->seguent;
    }
    return false;
}

Element *Contenidor::eliminarPerColumna(int col) {
    this->taula[col]->seguent = nullptr;
    this->taula[col]->continugt = nullptr;
}

Element *Contenidor::eliminarComodi(int row, int col) {

}

int Contenidor::getQuants() {
    return 0;
}

void Contenidor::mostrar() {
    node **temp = new node*[nFiles];
    for (int x = 0; x < 2; x++) {
        if (x!=0){
            for (int j = 0; j < sizeof(taula); j++) {
                temp[j] = this->taula[j]->seguent;
            }
        } else {
            for (int k=0; k< sizeof(taula); k++){
                temp[k] = this->taula[k];
            }
        }
        for (int i = 0; i < sizeof(taula); i++) {
            if (temp[i]->continugt != nullptr) {
                cout << temp[i]->continugt->getSimbol();
            }
            cout << "   ";
        }

    }
}


