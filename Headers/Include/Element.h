#ifndef UNTITLED_ELEMENT_H
#define UNTITLED_ELEMENT_H

class Element {
private:
    char simbol;
public:
    Element();

    Element(char simbol) { this->simbol = simbol; }

    char getSimbol();

    virtual int getPremi();

    bool operator==(Element *other);

    bool operator!=(Element *other);
};

#endif
