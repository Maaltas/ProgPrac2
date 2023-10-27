#ifndef UNTITLED_LLETRA_H
#define UNTITLED_LLETRA_H

#include "Element.h"

class Lletra : public Element {
private:
    int premi;
    bool seleccionada;
public:
    Lletra() : Element('_') { this->premi = 0; }

    Lletra(int premi, char simbol) : Element(simbol) { this->premi = premi; }

    bool getSeleccionada();

    int getPremi() override { return this->premi; }
};

#endif
