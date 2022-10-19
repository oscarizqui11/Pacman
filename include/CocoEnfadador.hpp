#ifndef COCO_ENFADADOR_HPP
#define COCO_ENFADADOR_HPP

#define TILE_COCOENFADADOR 2

#include "Coco.hpp"
#include "Tablero.hpp"

class CocoEnfadador : public Coco
{
public:
    CocoEnfadador(int px, int py, Tablero* t);
    void IntentaComer();
    void Dibuja();
    ~CocoEnfadador();
};

#endif
