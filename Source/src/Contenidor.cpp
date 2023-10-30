#include <iostream>
#include <random>
#include "Contenidor.h"
#include "Element.h"
using namespace std;

Contenidor::Contenidor(int nRow, int nCol) {
    this->taula = new node *[nCol];
    this->nFiles = nRow;
    this->nCol = nCol;
    inicialitzarTaula();
    int random;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 4);
    for (int i = 0; i < this->nCol; i++) {
        for (int j = 0; j<this->nFiles; j++){
            random = dis(gen);
            Element *element;
            if (random == 4) {
                element = new Comodi();
            } else {
                element = new Lletra(25, 'A' + random);
            }
            if (!afegirElement(element, j)) {
                break;
            }
        }

    }
}

bool Contenidor::afegirElement(Element* element, int posicio) {
    if (posicio >= 0 && posicio < nCol){
        node* temp = new node();
        temp->contingut = element;
        temp->seguent = nullptr;
        if (this->taula[posicio]->contingut == nullptr){
            delete this->taula[posicio];
            this->taula[posicio] = temp;
        } else {
            node* nouNode = this->taula[posicio];
            while (nouNode->seguent != nullptr){
                nouNode = nouNode->seguent;
            }
            nouNode->seguent = temp;
        }
        return true;
    } else {
        return false;
    }
}


void Contenidor::eliminarPerColumna(int col) {
    this->taula[col]->seguent = nullptr;
    this->taula[col]->contingut = nullptr;
}

void Contenidor::eliminarComodi() {
    for (int k = 0; k < nCol; k++) {
        node *posicioActual = this->taula[k];
        for (int i = 0; i < nFiles; i++) {
            if (posicioActual->contingut->getSimbol() == '*') {
                posicioActual->contingut = nullptr;
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
            if (posicioActual->contingut != nullptr) {
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
                cout << temp[j]->contingut->getSimbol() << "\t";
            } else {
                cout << "\n";
            }
            temp[j] = temp[j]->seguent;
        }
        cout << "\n";
    }
    cout << "\n";
}


