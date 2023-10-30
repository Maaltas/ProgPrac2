#include <cctype>
#include <iostream>
#include "Element.h"

using namespace std;

Element::Element() {

}

char Element::getSimbol() {
    return simbol;
}

int Element::getPremi() {
    cout << "Enhorabona has guanyat!";
}

bool Element::operator==(Element *other) {
    if (isalpha(other->simbol) && other->simbol != '*') {
        return (simbol == other->simbol);
    }
    return true;
}

bool Element::operator!=(Element *other) {
    if (isalpha(other->simbol) && other->simbol != '*') {
        return (simbol != other->simbol);
    }
    return false;
}

Lletra::Lletra(int premi, char simbol) : Element(simbol) {
    this->premi = premi;

}

int Lletra::getPremi() {
    return premi;
}

Comodi::Comodi() : Element('*') {}

int getPremi() {
    return 0;
}