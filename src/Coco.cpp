#include "NoEntiendo.hpp"
#include "Coco.hpp"
#include "Tablero.hpp"

Coco::Coco(int px, int py, Tablero* t)
{
    posX = px;
    posY = py;
    comido = false;
    tablero = t;
}

void Coco::Actualiza()
{
    
}

int Coco::ObtenPosX()
{
    return posX;
}

int Coco::ObtenPosY()
{
    return posY;
}

bool Coco::EstaComido()
{
    return comido;
}

void Coco::IntentaComer()
{
    if(comido == false)
        comido = true;
}

void Coco::Dibuja()
{
    NOE_PonTile(TILEMAP_COCOS, posX, posY, 1);
}

Coco::~Coco()
{

}