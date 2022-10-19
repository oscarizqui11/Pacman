#include "NoEntiendo.hpp"
#include "CocoEnfadador.hpp"
#include "Coco.hpp"
#include "Tablero.hpp"
#include "Pacman.hpp"
#include <stdio.h>

CocoEnfadador::CocoEnfadador(int px, int py, Tablero *t) : Coco(px, py, t)
{
}

void CocoEnfadador::IntentaComer()
{
    if (!comido)
    {
        comido = true;
        tablero->ObtenPacman()->Enfada();
    }
}

void CocoEnfadador::Dibuja()
{
    NOE_PonTile(TILEMAP_COCOS, posX, posY, TILE_COCOENFADADOR);
}

CocoEnfadador::~CocoEnfadador()
{
}