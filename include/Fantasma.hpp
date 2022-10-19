#ifndef FANTASMA_HPP
#define FANTASMA_HPP

#define TILEMAP_FANTASMAS 2

#include "Tablero.hpp"

class Pared;
class Tablero;

class Fantasma
{
private:
    Direccion direccion;
    int posX;
    int posY;
    bool chocaConParedArriba;
    bool chocaConParedAbajo;
    bool chocaConParedIzquierda;
    bool chocaConParedDerecha;
    bool enPersecucion;
    static bool asustados;
    bool oculto;
    Position previousPos;
    Tablero* tablero;

public:
    Fantasma(int px, int py, Tablero* t);
    void CompruebaChoques();
    void CompruebaChoquesConParedes();
    void Actualiza();
    int ObtenPosX();
    int ObtenPosY();
    Position ObtenPrevPos();
    static void Asustar();
    static void Tranquilizar();
    void Ocultar();
    void Dibuja();
    bool HasReachedIntersection();
    void ChangeDirection();
    int BuscaPacman();
    ~Fantasma();
};

#endif
