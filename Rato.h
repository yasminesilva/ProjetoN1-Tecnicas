#ifndef Rato_h
#define Rato_h

#include "Mapa.h"

const char CIMA = 'C';
const char BAIXO = 'B';
const char DIREITA = 'D';
const char ESQUERDA = 'E';

struct Rato{
    int posX;
    int posY;
    bool temQueijo;
    char deOndeVeio;
};

bool procuraQueijo(Mapa mapa, int posX, int posY, int deOndeVeio) {
  if (posX < 0 || posY < 0 || posX >= TAMANHO || posY >= TAMANHO) {
    return false;
  }  else if (mapa.cenario[posX][posY] == PAREDE || mapa.cenario[posX][posY] == RATO) {
    return false;
  } else if (mapa.cenario[posX][posY] == QUEIJO ){
    mapa.cenario[posX][posY] = VISITADO;
    mostrarMapa(mapa);
    return true;
  } else {
    mapa.cenario[posX][posY] = RATO;
    mostrarMapa(mapa);

    if (deOndeVeio != DIREITA && procuraQueijo(mapa, posX, posY+1, ESQUERDA)) {
      mapa.cenario[posX][posY] = VISITADO;
      mostrarMapa(mapa);
      return true;
    } else if (deOndeVeio != BAIXO && procuraQueijo(mapa, posX+1, posY, CIMA)) {
      mapa.cenario[posX][posY] = VISITADO;
      mostrarMapa(mapa);
      return true;
    } else if (deOndeVeio != ESQUERDA && procuraQueijo(mapa, posX, posY-1, DIREITA)) {
      mapa.cenario[posX][posY] = VISITADO;
      mostrarMapa(mapa);
      return true;
    } else if (deOndeVeio != CIMA && procuraQueijo(mapa, posX-1, posY, BAIXO)) {
      mapa.cenario[posX][posY] = VISITADO;
      mostrarMapa(mapa);
      return true;
    }

    mostrarMapa(mapa);
  }
  return false;
}

#endif
