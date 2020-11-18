#include <iostream>
#include <ctime>
#include "Mapa.h"
#include "Rato.h"

int main() {
  Mapa mapa;
  Rato rato;
    
  cout << "Inicia Mapa" << endl;
  mostrarMapa(mapa);
  
  bool adicionouEntrada = false;

  srand(time(NULL));
  do {
    int entradaX = rand() % 5;
    int entradaY = rand() % 5;

    if (mapa.cenario[entradaX][entradaY] != PAREDE && mapa.cenario[entradaX][entradaY] != QUEIJO) {
      mapa.cenario[entradaX][entradaY] = ENTRADA;
      adicionouEntrada = true;
      rato.posX = entradaX;
      rato.posY = entradaY;
    }
  } while (!adicionouEntrada);

  cout << "Definir Entrada" << endl;
  mostrarMapa(mapa);

  cout << "Inicia Busca" << endl;
  procuraQueijo(mapa, rato.posX, rato.posY, CIMA);

}
