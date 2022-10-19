#include "NoEntiendo.hpp"
#include "Pared.hpp"

Pared::Pared(int px, int py)
{
    posX = px;
    posY = py;
}

void Pared::Actualiza()
{

}

void Pared::Dibuja()
{
    NOE_PonTile(TILEMAP_PAREDES, posX, posY, 17);
}

int Pared::ObtenPosX()
{
    return posX;
}

int Pared::ObtenPosY()
{
    return posY;
}

Pared::~Pared()
{

}
