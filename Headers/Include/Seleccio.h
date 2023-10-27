#ifndef UNTITLED_SELECCIO_H
#define UNTITLED_SELECCIO_H

#include <memory>
#include "Element.h"
using namespace std;
class Seleccio{
    private:
        static const int mida = 6;
        Element *array[mida];
        int premiFinal;
    public:
        Seleccio();
        bool afegir(Element*);
        bool eliminar3iguals();
        int getPremiFinal();
        void mostrar();
        void eliminarSimbol(char simbol);
};

#endif
