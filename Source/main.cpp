#include <iostream>

using namespace std;

#include "Contenidor.h"
#include "Seleccio.h"


int main() {
    cout << "Hello World\n";
    int dificultat = 0;
    int nCol, nRow, columna, fila;
    do {
        cout << "Escull el nivell de dificultat" << endl;
        cout << "1. Facil" << endl;
        cout << "2. Mitja" << endl;
        cout << "3. Dificil" << endl;
        cin >> dificultat;

        switch (dificultat) {
            case 1:
                nCol = 6;
                nRow = 4;
                break;
            case 2:
                nCol = 4;
                nRow = 6;
                break;
            case 3:
                nCol = 3;
                nRow = 8;
                break;
            default:
                break;
        }
    } while (dificultat > 3 || dificultat < 1);

    auto *selector = new Seleccio();
    auto *contenidor = new Contenidor(nRow, nCol);
    cout << "Seleccioneu 3 lletres iguals:\n";
    selector->mostrar();
    cout << "Lletres disponibles:\n";
    contenidor->mostrar();
    cout<<"\n";
    cout << "Especifica una columna dins de l'interval [1," << nCol << "] o 0 per seleccionar l'asterisc" << endl;
    cin >> columna;
}