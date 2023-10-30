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
    for (int i = 0; i < this->nFiles; i++) {
        for (int j = 0; j<this->nCol; j++){
            random = dis(gen);
            Element *element;
            if (random == 4) {
                element = new Comodi();
            } else {
                element = new Lletra(50, 'A' + random);
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


Element* Contenidor::eliminarPerColumna(int col) {
    if (col >= 0 && col < this->nCol) {
        if (this->taula[col]->contingut->getSimbol() == '*'){
            eliminarComodi();
            return nullptr;
        } else {
            Element *element = this->taula[col]->contingut;
            this->taula[col] = this->taula[col]->seguent;
            return element;
        }

    } else {
        throw runtime_error ("La columna no existeix o esta fora del limit");
    }
}

void Contenidor::eliminarComodi() {
    for (int i = 0; i < nCol; i++) {
        if (this->taula[i]->contingut->getSimbol()=='*'){
            node* temp = this->taula[i];
            this->taula[i] = this->taula[i]->seguent;
            delete temp;
            return;
        }
    }
    throw runtime_error ("Ho sento pero no hi ha cap comodí torna a intentar jugar");
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
    node **temp = new node *[nCol];
    int cont = 0;
    for (int i = 0; i < nCol; i++) {
        cout << i + 1 << "\t";
        temp[i] = taula[i];
    }
    cout << "\n";
    for (int j = 0; j < nFiles; j++) {
        for (int k = 0; k < nCol; k++) {
            if (temp[k] != nullptr) {
                cout << temp[k]->contingut->getSimbol() << "\t";
                temp[k] = temp[k]->seguent;
            } else {
                cout << "        ";
            }

        }
        cout << "\n";
    }
    cout << "\n";
}



