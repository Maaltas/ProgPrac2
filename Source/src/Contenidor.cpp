#include <iostream>

using namespace std;

#include "Contenidor.h"

Contenidor::Contenidor(int nRow, int nCol) {
    this->taula = new node *[nCol];
    for (int i = 0; i < nCol; i++) {
        for (int j = 0; j < nRow; j++){
            if (!afegirElement(new Element, i)){ // si no s'ha pogut afegir l'element, seguent columna
                break;
            }
        }
    }
}

bool Contenidor::afegirElement(Element *element, int posicio) {
    if (this->taula[posicio]->continugt == nullptr) {
        this->taula[posicio]->continugt = element;
    } else if (this->taula[posicio]->seguent->continugt == nullptr) {
        this->taula[posicio]->seguent->continugt = element;
    } else if (this->taula[posicio]->seguent->seguent->continugt == nullptr) {
        this->taula[posicio]->seguent->seguent->continugt = element;
    } else if (this->taula[posicio]->seguent->seguent->seguent->continugt == nullptr) {
        this->taula[posicio]->seguent->seguent->seguent->continugt = element;
    }

    // fer el mateix amb un bucle
    node *posicioActual = this->taula[posicio];
    while (posicioActual->continugt != element) { // diria que aquesta lògica fa que no puguin haver 2 elements iguals ???
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

Element *Contenidor::eliminarComodi() {

}

int Contenidor::getQuants() {
    return 0;
}

void Contenidor::mostrar() {
    node *po = new node *[sizeof(taula)];
    for (int x = 0; x < 2; x++) {
        for (int j = 0; j < sizeof(taula); j++) {

        }
        for (int i = 0; i < sizeof(taula); i++) {
            if (this->taula[i]->continugt != nullptr) {
                cout << this->taula[i]->continugt->getSimbol();
            }
            cout << "   ";
        }

    }
}



