
#include "../../Headers/Include/Seleccio.h"

Seleccio::Seleccio() {

}

bool Seleccio::afegir(Element *element) {
    if (*array[5] != nullptr)
        return false;
    for(auto & i : array){
        if(*i == nullptr){
            *i = *element;
            break;
        }
    }
    return true;
}

bool Seleccio::eliminar3iguals() {
    return false;
    for(auto & i : array){

    }
}

int Seleccio::getPremiFinal() {
    return premiFinal;
}

void Seleccio::mostrar() {

}

