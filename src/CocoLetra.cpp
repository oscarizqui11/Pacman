#include "NoEntiendo.hpp"
#include "CocoLetra.hpp"
#include "Coco.hpp"
#include "Tablero.hpp"
#include "Pacman.hpp"
#include <stdio.h>

CocoLetra::CocoLetra(int px, int py, Letra l, Tablero *t) : Coco(px, py, t)
{
    letra = l;
}

void CocoLetra::IntentaComer()
{
    if (!comido)
    {
        switch (letra)
        {
        case LETRA_P:
            if (tablero->ObtenPacman()->ObtenUltimaLetra() == LETRA_VACIA)
            {
                tablero->ObtenPacman()->RecibeLetra(letra);
                comido = true;
            }
            break;
        case LETRA_A1:
            if (tablero->ObtenPacman()->ObtenUltimaLetra() == LETRA_P)
            {
                tablero->ObtenPacman()->RecibeLetra(letra);
                comido = true;
            }
            break;
        case LETRA_C:
            if (tablero->ObtenPacman()->ObtenUltimaLetra() == LETRA_A1)
            {
                tablero->ObtenPacman()->RecibeLetra(letra);
                comido = true;
            }
            break;
        case LETRA_M:
            if (tablero->ObtenPacman()->ObtenUltimaLetra() == LETRA_C)
            {
                tablero->ObtenPacman()->RecibeLetra(letra);
                comido = true;
            }
            break;
        case LETRA_A2:
            if (tablero->ObtenPacman()->ObtenUltimaLetra() == LETRA_M)
            {
                tablero->ObtenPacman()->RecibeLetra(letra);
                comido = true;
            }
            break;
        case LETRA_N:
            if (tablero->ObtenPacman()->ObtenUltimaLetra() == LETRA_A2)
            {
                tablero->ObtenPacman()->RecibeLetra(letra);
                comido = true;
            }
            break;

        default:
            comido = true;
            break;
        }
    }
}

void CocoLetra::Dibuja()
{
    switch (letra)
    {
    case LETRA_P:
        if (tablero->ObtenPacman()->ObtenUltimaLetra() == LETRA_VACIA)
        {
            NOE_PonTile(TILEMAP_COCOS, posX, posY, TILE_COCOLETRA_P);
        }
        else
        {
            NOE_PonTile(TILEMAP_COCOS, posX, posY, 1);
        }
        break;
    case LETRA_A1:
        if (tablero->ObtenPacman()->ObtenUltimaLetra() == LETRA_P)
        {
            NOE_PonTile(TILEMAP_COCOS, posX, posY, TILE_COCOLETRA_A1);
        }
        else
        {
            NOE_PonTile(TILEMAP_COCOS, posX, posY, 1);
        }
        break;
    case LETRA_C:
        if (tablero->ObtenPacman()->ObtenUltimaLetra() == LETRA_A1)
        {
            NOE_PonTile(TILEMAP_COCOS, posX, posY, TILE_COCOLETRA_C);
        }
        else
        {
            NOE_PonTile(TILEMAP_COCOS, posX, posY, 1);
        }
        break;
    case LETRA_M:
        if (tablero->ObtenPacman()->ObtenUltimaLetra() == LETRA_C)
        {
            NOE_PonTile(TILEMAP_COCOS, posX, posY, TILE_COCOLETRA_M);
        }
        else
        {
            NOE_PonTile(TILEMAP_COCOS, posX, posY, 1);
        }
        break;
    case LETRA_A2:
        if (tablero->ObtenPacman()->ObtenUltimaLetra() == LETRA_M)
        {
            NOE_PonTile(TILEMAP_COCOS, posX, posY, TILE_COCOLETRA_A2);
        }
        else
        {
            NOE_PonTile(TILEMAP_COCOS, posX, posY, 1);
        }
        break;
    case LETRA_N:
        if (tablero->ObtenPacman()->ObtenUltimaLetra() == LETRA_A2)
        {
            NOE_PonTile(TILEMAP_COCOS, posX, posY, TILE_COCOLETRA_N);
        }
        else
        {
            NOE_PonTile(TILEMAP_COCOS, posX, posY, 1);
        }
        break;

    default:
        comido = true;
        break;
    }
}

CocoLetra::~CocoLetra()
{
}
