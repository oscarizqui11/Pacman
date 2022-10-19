#ifndef COCO_LETRA_HPP
#define COCO_LETRA_HPP

#define TILE_COCOLETRA_P 22
#define TILE_COCOLETRA_A1 23
#define TILE_COCOLETRA_C 24
#define TILE_COCOLETRA_M 25
#define TILE_COCOLETRA_A2 26
#define TILE_COCOLETRA_N 27

#include "Coco.hpp"
#include "Tablero.hpp"

class CocoLetra : public Coco
{
private:
    Letra letra;

public:
    CocoLetra(int px, int py, Letra l, Tablero* t);
    void IntentaComer();
    void Dibuja();
    ~CocoLetra();
};

#endif
