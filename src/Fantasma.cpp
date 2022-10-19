#include <stdio.h>
#include "Common.hpp"
#include "NoEntiendo.hpp"
#include "Fantasma.hpp"
#include "Pared.hpp"
#include "Tablero.hpp"

Fantasma::Fantasma(int px, int py, Tablero *t)
{
    posX = px;
    posY = py;
    previousPos.x = px;
    previousPos.y = py;
    enPersecucion = false;
    oculto = false;

    tablero = t;

    direccion = DIRECCION_DERECHA;
}

bool Fantasma::asustados = false;

void Fantasma::CompruebaChoques()
{
    CompruebaChoquesConParedes();
}

void Fantasma::CompruebaChoquesConParedes()
{
    chocaConParedAbajo = false;
    chocaConParedArriba = false;
    chocaConParedIzquierda = false;
    chocaConParedDerecha = false;

    if (tablero->BuscaPared(posX + 1, posY))
    {
        chocaConParedDerecha = true;
    }
    if (tablero->BuscaPared(posX - 1, posY))
    {
        chocaConParedIzquierda = true;
    }
    if (tablero->BuscaPared(posX, posY + 1))
    {
        chocaConParedAbajo = true;
    }
    if (tablero->BuscaPared(posX, posY - 1))
    {
        chocaConParedArriba = true;
    }
}

void Fantasma::Actualiza()
{
    if (HasReachedIntersection())
    {
        int direccionApacman = BuscaPacman();

        if ((NOE_ObtenNumeroAleatorio(0, 1) || enPersecucion) && direccionApacman >= 0 && !asustados)
        {
            direccion = (Direccion)direccionApacman;
            enPersecucion = true;
            printf("Persiguiendo al bicho amarilo %d ", direccion);
        }
        else
        {
            do
            {
                ChangeDirection();
            } while (asustados && direccion == direccionApacman);

            enPersecucion = false;
        }
    }

    previousPos.x = posX;
    previousPos.y = posY;

    switch (direccion)
    {
    case DIRECCION_ARRIBA:
        if (!chocaConParedArriba)
        {
            posY = posY - 1;
        }
        break;

    case DIRECCION_IZQUIERDA:
        if (!chocaConParedIzquierda)
        {
            posX = posX - 1;
        }
        break;

    case DIRECCION_ABAJO:
        if (!chocaConParedAbajo)
        {
            posY = posY + 1;
        }
        break;

    case DIRECCION_DERECHA:
        if (!chocaConParedDerecha)
        {
            posX = posX + 1;
        }
        break;

    default:
        break;
    }
    
    if(oculto && !asustados)
    {
        oculto = false;
    }

}

int Fantasma::ObtenPosX()
{
    return posX;
}

int Fantasma::ObtenPosY()
{
    return posY;
}

Position Fantasma::ObtenPrevPos()
{
    return previousPos;
}

void Fantasma::Asustar()
{
    asustados = true;
}

void Fantasma::Tranquilizar()
{
    asustados = false;
}

void Fantasma::Ocultar()
{
    oculto = true;
}

void Fantasma::Dibuja()
{
    if (asustados && !oculto)
    {
        NOE_PonTile(TILEMAP_FANTASMAS, posX, posY, 11);
    }
    else if (!oculto)
    {
        NOE_PonTile(TILEMAP_FANTASMAS, posX, posY, 8);
    }
}

bool Fantasma::HasReachedIntersection()
{
    bool ret = false;
    int dirCount = 0;

    if (!chocaConParedAbajo && previousPos.y != posY + 1)
        dirCount++;
    if (!chocaConParedArriba && previousPos.y != posY - 1)
        dirCount++;
    if (!chocaConParedDerecha && previousPos.x != posX + 1)
        dirCount++;
    if (!chocaConParedIzquierda && previousPos.x != posX - 1)
        dirCount++;

    if (dirCount > 1)
        ret = true;

    return ret;
}

void Fantasma::ChangeDirection()
{
    int random;
    bool hasChosenDirection = false;

    while (!hasChosenDirection)
    {
        random = NOE_ObtenNumeroAleatorio(0, 3);

        if (random == 0 && !chocaConParedArriba && (posY + 1 != previousPos.y || asustados))
        {
            direccion = DIRECCION_ARRIBA;
            hasChosenDirection = true;
        }
        else if (random == 1 && !chocaConParedIzquierda && (posX - 1 != previousPos.x || asustados))
        {
            direccion = DIRECCION_IZQUIERDA;
            hasChosenDirection = true;
        }
        else if (random == 2 && !chocaConParedAbajo && (posY - 1 != previousPos.y || asustados))
        {
            direccion = DIRECCION_ABAJO;
            hasChosenDirection = true;
        }
        else if (random == 3 && !chocaConParedDerecha && (posX + 1 != previousPos.x || asustados))
        {
            direccion = DIRECCION_DERECHA;
            hasChosenDirection = true;
        }
    }
}

int Fantasma::BuscaPacman()
{
    int ret = -1;

    if (tablero->BuscaPacmanDireccion(posX, posY, 0, 1))
    {
        ret = DIRECCION_ABAJO;
    }
    else if (tablero->BuscaPacmanDireccion(posX, posY, -1, 0))
    {
        ret = DIRECCION_IZQUIERDA;
    }
    else if (tablero->BuscaPacmanDireccion(posX, posY, 1, 0))
    {
        ret = DIRECCION_DERECHA;
    }
    else if (tablero->BuscaPacmanDireccion(posX, posY, 0, -1))
    {
        ret = DIRECCION_ARRIBA;
    }

    return ret;
}

Fantasma::~Fantasma()
{
}
