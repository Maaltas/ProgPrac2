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

class Lletra : public Element {
private:
    int premi;
public:
    Lletra(int premi, char simbol);

    int getPremi();
};

class Comodi : public Element {
    public:
    Comodi();

    int getPremi();
};

#endif
