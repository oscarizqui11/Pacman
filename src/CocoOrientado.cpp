#include "NoEntiendo.hpp"
#include "CocoOrientado.hpp"
#include "Coco.hpp"
#include "Tablero.hpp"
#include "Pacman.hpp"

CocoOrientado::CocoOrientado(int px, int py, Direccion d, Tablero *t) : Coco(px, py, t)
{
    direccion = d;
}

void CocoOrientado::IntentaComer()
{
    if (!comido)
    {
        switch (direccion)
        {
        case DIRECCION_ABAJO:
            if (tablero->ObtenPacman()->ObtenDireccionPacman() == DIRECCION_ABAJO)
            {
                comido = true;
            }
            break;
        case DIRECCION_ARRIBA:
            if (tablero->ObtenPacman()->ObtenDireccionPacman() == DIRECCION_ARRIBA)
            {
                comido = true;
            }
            break;
        case DIRECCION_DERECHA:
            if (tablero->ObtenPacman()->ObtenDireccionPacman() == DIRECCION_DERECHA)
            {
                comido = true;
            }
            break;
        case DIRECCION_IZQUIERDA:
            if (tablero->ObtenPacman()->ObtenDireccionPacman() == DIRECCION_IZQUIERDA)
            {
                comido = true;
            }
            break;

        default:
            comido = true;
            break;
        }
    }
}

void CocoOrientado::Dibuja()
{
    switch (direccion)
    {
    case DIRECCION_ABAJO:
        NOE_PonTile(TILEMAP_COCOS, posX, posY, COCO_ORIENTADO_ABAJO);
        break;

    case DIRECCION_ARRIBA:
        NOE_PonTile(TILEMAP_COCOS, posX, posY, COCO_ORIENTADO_ARRIBA);
        break;

    case DIRECCION_DERECHA:
        NOE_PonTile(TILEMAP_COCOS, posX, posY, COCO_ORIENTADO_DERECHA);
        break;

    case DIRECCION_IZQUIERDA:
        NOE_PonTile(TILEMAP_COCOS, posX, posY, COCO_ORIENTADO_IZQUIERDA);
        break;

    default:
        comido = true;
        break;
    }
}

CocoOrientado::~CocoOrientado()
{
}