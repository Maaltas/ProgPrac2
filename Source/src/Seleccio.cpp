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
    for (Element *& i: array) {
        if (i == nullptr) {
            i = element;
            return true;
        }
    }
    return false;
}


bool Seleccio::eliminar3iguals() {
    int countA = 0, countB = 0, countC = 0, countD = 0;
    for (Element  *i: array) {
        if (*i == nullptr){
            break;
        }else if (i->getSimbol() == 'A') {
            if (countA >= 3) {
                eliminarSimbol('A');
                premiFinal += i->getPremi() * 3;
                return true;
            }
            countA++;
        }else if (i->getSimbol() == 'B') {
            if (countB >= 3) {
                eliminarSimbol('B');
                premiFinal += i->getPremi() * 3;
                return true;
            }
            countB++;
        }else if (i->getSimbol() == 'C') {
            if (countC >= 3) {
                eliminarSimbol('C');
                premiFinal += i->getPremi() * 3;
                return true;
            }
            countC++;
        }
        else if (i->getSimbol() == 'D') {
            if (countD >= 3) {
                eliminarSimbol('D');
                premiFinal += i->getPremi() * 3;
                return true;
            }
            countD++;
        }
        else if (i->getSimbol() == '*') {
            countA++;
            countB++;
            countC++;
            countD++;
            if(premiFinal >= 50)
                premiFinal -= 50;
        }
    }
    return false;
}

void Seleccio::eliminarSimbol(char simbol) {
    for (auto &i: array) {
        if (*i == nullptr)
            break;
        if (i->getSimbol() == simbol) {
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
        if (i == nullptr){cout << "_ ";}
        else{cout << i->getSimbol() << " ";}
    }
    cout << endl;
}

