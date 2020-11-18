#ifndef Mapa_h
#define Mapa_h

#include <iostream>
using namespace std;

const int TAMANHO = 5;

const char PAREDE = 'P';
const char VAZIO = '.';
const char QUEIJO = 'Q';
const char ENTRADA = 'E';
const char RATO = 'R';
const char VISITADO = 'X';

struct Mapa{
    char cenario[TAMANHO][TAMANHO] = {
        VAZIO, PAREDE,  PAREDE, VAZIO,  VAZIO,
        VAZIO, PAREDE,  PAREDE, VAZIO,  VAZIO,
        VAZIO, VAZIO,   VAZIO,  VAZIO,  QUEIJO,
        VAZIO, VAZIO,   VAZIO,  VAZIO,  VAZIO,
        VAZIO, VAZIO,   VAZIO,  VAZIO,  VAZIO
    };
};

void mostrarMapa(Mapa umMapa){
    for (int i=0; i<TAMANHO; i++) {
        for (int j=0; j<TAMANHO; j++) {
            cout <<umMapa.cenario[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

#endif
