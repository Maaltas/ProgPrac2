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

class Lletra : public Element {
private:
    int premi;
public:
    Lletra(int premi, char simbol) : Element(simbol) {
        this->premi = premi;
    }

    int getPremi() override {
        return premi;
    }
    //void nomFuncio(){cout<<"implementacio"<< end1;}
};

class Comodi : public Element {
public:
    Comodi() : Element('*') {}

    int getPremi() override {
        return 0;
    }
};