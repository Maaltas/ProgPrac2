#include <iostream>
#include <random>

using namespace std;

#include "Contenidor.h"
#include "Element.h"

Contenidor::Contenidor(int nRow, int nCol) {
    this->taula = new node *[nCol];
    this->nFiles = nRow;
    this->nCol = nCol;
    for (int i = 0; i < nCol; i++) {
        this->taula[i] = new node();
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 4);
        int random = dis(gen);
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

    if (posicioActual == nullptr) {
        return false;
    }
    for (int i = 0; i < nFiles; i++) {
        if (posicioActual->continugt == nullptr) {
            posicioActual->continugt = element;
            return true;
        } else
            posicioActual = posicioActual->seguent;
    }
    return false;
}


void Contenidor::eliminarPerColumna(int col) {
    this->taula[col]->seguent = nullptr;
    this->taula[col]->continugt = nullptr;
}

void Contenidor::eliminarComodi() {
    for (int k = 0; k < nCol; k++) {
        node *posicioActual = this->taula[k];
        for (int i = 0; i < nFiles; i++) {
            if (posicioActual->continugt->getSimbol() == '*') {
                posicioActual->continugt = nullptr;
                break;
            }
            posicioActual = posicioActual->seguent;
        }
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
    int cont = 0;
    for (int i = 0; i < nCol; i++) {
        cout << i + 1 << "\t";
        temp[i] = taula[i];
    }
    cout << "\n";
    for (int j = 0; j < nFiles; j++) {
        for (int k = 0; k < nCol; k++) {
            if (temp[j] != nullptr) {
                cout << temp[j]->continugt->getSimbol() << "\t";
            } else {
                cout << "\t";
                temp[j] = temp[j]->seguent;
            }
        }
        cout << "\n";
    }
    cout << "\n";
}


