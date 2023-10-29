#include "Seleccio.h"
#include <iostream>

using namespace std;

Seleccio::Seleccio() {
    premiFinal = 0;
    for (auto &i: array) {
        i = nullptr;
    }
}

bool Seleccio::afegir(Element *element) {
    if (*array[5] != nullptr)
        return false;
    for (auto &i: array) {
        if (*i == nullptr) {
            *i = *element;
            break;
        }
    }
    return true;
}

bool Seleccio::eliminar3iguals() {
    int countA = 0, countB = 0, countC = 0, countD = 0;
    for (auto &i: array) {
        if (*i == nullptr)
            break;
        if (i->getSimbol() == 'A') {
            if (countA >= 3) {
                eliminarSimbol('A');
                break;
            }
            countA++;
        }
        if (i->getSimbol() == 'B') {
            if (countB >= 3) {
                eliminarSimbol('B');
                break;
            }
            countB++;
        }
        if (i->getSimbol() == 'C') {
            if (countC >= 3) {
                eliminarSimbol('C');
                break;
            }
            countC++;
        }
        if (i->getSimbol() == 'D') {
            if (countD >= 3) {
                eliminarSimbol('D');
                break;
            }
            countD++;
        }
        if (i->getSimbol() == '*') {
            countA++;
            countB++;
            countC++;
            countD++;
        }
    }
    return false;
}

void Seleccio::eliminarSimbol(char simbol) {
    for (auto &i: array) {
        if (*i == nullptr)
            break;
        if (i->getSimbol() == simbol) {
            premiFinal += i->getPremi();
            delete i;
            i = nullptr;
            break;
        }
    }
}

int Seleccio::getPremiFinal() {
    return premiFinal;
}

void Seleccio::mostrar() {
    for (auto &i: array) {
        if (*i == nullptr)
            cout << "_" << " ";
        cout << i->getSimbol() << " ";
    }
    cout << endl;
}

