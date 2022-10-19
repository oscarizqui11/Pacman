#include <stdio.h>
#include "NoEntiendo.hpp"
#include "Common.hpp"
#include "Pacman.hpp"
#include "Pared.hpp"
#include "Coco.hpp"
#include "Fantasma.hpp"

Pacman::Pacman(int px, int py, Tablero *t)
{
    posX = px;
    posY = py;
    muerto = false;
    enfadado = false;
    ciclosEnfado = 0;
    tablero = t;

    direccion = DIRECCION_DERECHA;
    tilePacman = 3;
    ultimaLetraRecibida = LETRA_VACIA;
}

void Pacman::CompruebaChoques()
{
    CompruebaChoquesConParedes();
    CompruebaChoquesConFantasmas();
    CompruebaChoquesConCocos();
}

void Pacman::CompruebaChoquesConParedes()
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

void Pacman::CompruebaChoquesConCocos()
{
    Coco *hayCoco = tablero->BuscaCoco(posX, posY);
    if (hayCoco)
    {
        hayCoco->IntentaComer();
    }
}

void Pacman::CompruebaChoquesConFantasmas()
{
    Fantasma* fantasmaEnPos = tablero->BuscaFantasma(posX, posY);
    Fantasma* fantasmaEnPrevPos = SeHaCruzadoConFantasma();

    if (fantasmaEnPos)
    {
        if (!enfadado)
        {
            muerto = true;
        }
        else 
        {
            fantasmaEnPos->Ocultar();
        }
    }
    if (fantasmaEnPrevPos)
    {
        if (!enfadado)
        {
            muerto = true;
        }
        else 
        {
            fantasmaEnPrevPos->Ocultar();
        }
    }
}

Fantasma* Pacman::SeHaCruzadoConFantasma()
{
    Fantasma* fantasmaEnPrevPos = tablero->BuscaFantasma(previousPosition.x, previousPosition.y);

    return (fantasmaEnPrevPos && fantasmaEnPrevPos->ObtenPrevPos().x == posX && fantasmaEnPrevPos->ObtenPrevPos().y == posY) ? fantasmaEnPrevPos : 0;
}

void Pacman::Actualiza()
{
    if (NOE_ObtenTeclaPulsada(NOE_TECLA_W) && !chocaConParedArriba)
    {
        direccion = DIRECCION_ARRIBA;
    }
    else if (NOE_ObtenTeclaPulsada(NOE_TECLA_A) && !chocaConParedIzquierda)
    {
        direccion = DIRECCION_IZQUIERDA;
    }
    else if (NOE_ObtenTeclaPulsada(NOE_TECLA_S) && !chocaConParedAbajo)
    {
        direccion = DIRECCION_ABAJO;
    }
    else if (NOE_ObtenTeclaPulsada(NOE_TECLA_D) && !chocaConParedDerecha)
    {
        direccion = DIRECCION_DERECHA;
    }

    previousPosition.x = posX;
    previousPosition.y = posY;

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

    if (enfadado)
    {
        if (ciclosEnfado <= CICLOS_ENFADO_PACMAN)
        {
            ciclosEnfado++;
        }
        else
        {
            enfadado = false;
            ciclosEnfado = 0;
            Fantasma::Tranquilizar();
        }
    }

    ActualizaAnimacion();
}

int Pacman::ObtenPosX()
{
    return posX;
}

int Pacman::ObtenPosY()
{
    return posY;
}

Letra Pacman::ObtenUltimaLetra()
{
    return ultimaLetraRecibida;
}

void Pacman::RecibeLetra(Letra l)
{
    ultimaLetraRecibida = l;
}

Direccion Pacman::ObtenDireccionPacman()
{
    return direccion;
}

bool Pacman::EstaMuerto()
{
    return muerto;
}

void Pacman::Enfada()
{
    enfadado = true;
    ciclosEnfado = 0;
    Fantasma::Asustar();
}

void Pacman::Dibuja()
{
    NOE_PonTile(TILEMAP_PACMAN, posX, posY, tilePacman);
}

void Pacman::ActualizaAnimacion()
{
    int auxTileSum = 0;

    if (enfadado)
        auxTileSum = 9;

    if (tilePacman == 3 + auxTileSum)
    {
        switch (direccion)
        {
        case DIRECCION_ARRIBA:
            tilePacman = 4 + auxTileSum;
            break;

        case DIRECCION_IZQUIERDA:
            tilePacman = 6 + auxTileSum;
            break;

        case DIRECCION_ABAJO:
            tilePacman = 5 + auxTileSum;
            break;

        case DIRECCION_DERECHA:
            tilePacman = 7 + auxTileSum;
            break;

        default:
            break;
        }
    }
    else
    {
        tilePacman = 3 + auxTileSum;
    }
}

Pacman::~Pacman()
{
}