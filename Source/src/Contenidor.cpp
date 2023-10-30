#include <iostream>

using namespace std;

#include "Contenidor.h"
#include "Element.h"

Contenidor::Contenidor(int nRow, int nCol) {
    this->taula = new node *[nCol];
    this->nFiles = nRow;
    this->nCol = nCol;
    for (int i = 0; i < nCol; i++) {
        int random = rand() % 5;
        Element *element;
        if (random == 4) {
            element = new Comodi();
        } else {
            element = new Lletra(25, 'A' + random);
        }
        if (!afegirElement(element, i)) { // si no s'ha pogut afegir l'element, seguent columna
            break;
        }
    }
}

bool Contenidor::afegirElement(Element *element, int posicio) {
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
    /*if (this->taula[row]->continugt->getSimbol() == '*') {
        this->taula[row]->continugt = nullptr;
    } else if (this->taula[row]->seguent->continugt->getSimbol() == '*') {
        this->taula[row]->seguent->continugt = nullptr;
    } else {
        this->taula[row]->seguent->seguent->continugt = nullptr;
    } */

    node *posicioActual = this->taula[col];
    for (int i = 0; i < nFiles; i++) {
        if (posicioActual->continugt->getSimbol() == '*') {
            posicioActual->continugt = nullptr;
            break;
        }
        posicioActual = posicioActual->seguent;
    }
}

int Contenidor::getQuants() {
    int count = 0;
    for (int i = 0; i < nCol; i++) {
        node *posicioActual = this->taula[i];
        for (int j = 0; j < nFiles; j++) {
            if (posicioActual->continugt != nullptr) {
                count++;
            }
            posicioActual = posicioActual->seguent;
        }
    }
    return count;
}

void Contenidor::mostrar() {
    node **temp = new node *[nFiles];
    for (int x = 0; x < 2; x++) {
        if (x != 0) {
            for (int j = 0; j < sizeof(taula); j++) {
                temp[j] = this->taula[j]->seguent;
            }
        } else {
            for (int k = 0; k < sizeof(taula); k++) {
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


