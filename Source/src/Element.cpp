#include <cctype>
#include "Element.h"
using namespace std;
Element::Element() {

}

char Element::getSimbol() {
    return simbol;
}

int Element::getPremi() {
    return 25;
}

bool Element::operator==(Element *other) {
    if (isalpha(other->simbol)&& other->simbol!='*'){
        return (simbol == other->simbol);
    }
    return true;
}

bool Element::operator!=(Element *other) {
    if (isalpha(other->simbol)&& other->simbol!='*'){
        return (simbol != other->simbol);
    }
    return false;
}
