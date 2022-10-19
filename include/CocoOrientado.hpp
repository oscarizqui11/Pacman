#ifndef COCO_ORIENTADO_HPP
#define COCO_ORIENTADO_HPP

#define COCO_ORIENTADO_ARRIBA 18
#define COCO_ORIENTADO_ABAJO 19
#define COCO_ORIENTADO_IZQUIERDA 20
#define COCO_ORIENTADO_DERECHA 21

#include "Coco.hpp"
#include "Tablero.hpp"

class CocoOrientado : public Coco
{
private:
    Direccion direccion;

public:
    CocoOrientado(int px, int py, Direccion d, Tablero* t);
    void IntentaComer();
    void Dibuja();
    ~CocoOrientado();
};

#endif
