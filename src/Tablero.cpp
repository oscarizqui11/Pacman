#include <stdio.h>
#include "NoEntiendo.hpp"
#include "Common.hpp"
#include "Tablero.hpp"
#include "Pacman.hpp"
#include "Pared.hpp"
#include "Coco.hpp"
#include "CocoLetra.hpp"
#include "CocoOrientado.hpp"
#include "CocoEnfadador.hpp"
#include "Fantasma.hpp"

Tablero::Tablero()
{
    ancho = 8;
    alto = 8;
    offSet_X = 3;
    offSet_Y = 1;

    const int tileAncho = 12;
    const int tileAlto = 9;

    int tileMap[tileAlto][tileAncho] = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                        {-1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                        {-1, -1, -1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
                                        {-1, -1, -1, 0, 1, 0, 0, 1, 0, 0, 1, 0},
                                        {-1, -1, -1, 0, 1, 0, 0, 1, 0, 0, 1, 0},
                                        {-1, -1, -1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
                                        {-1, -1, -1, 0, 1, 0, 0, 1, 0, 0, 1, 0},
                                        {-1, -1, -1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
                                        {-1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Crear objetos
    // ...
    pacman = new Pacman(7, 5, this);
    fantasmas[0] = new Fantasma(4, 3, this);
    numFantasmas = 1;
    numParedes = 0;
    numCocos = 0;
    numCocosComidos = 0;

    for (int j = 0; j < tileAlto; j++)
    {
        for (int i = 0; i < tileAncho; i++)
        {
            if (tileMap[j][i] == TILEMAP_PAREDES)
            {
                paredes[numParedes] = new Pared(i, j);
                numParedes++;
            }
            else if (tileMap[j][i] == TILEMAP_COCOS)
            {
                if (i == 4 && j == 2)
                {
                    cocos[numCocos] = new CocoLetra(i, j, LETRA_P, this);
                    numCocos++;
                }
                else if (i == 7 && j == 2)
                {
                    cocos[numCocos] = new CocoLetra(i, j, LETRA_A1, this);
                    numCocos++;
                }
                else if (i == 10 && j == 2)
                {
                    cocos[numCocos] = new CocoLetra(i, j, LETRA_C, this);
                    numCocos++;
                }
                else if (i == 4 && j == 7)
                {
                    cocos[numCocos] = new CocoLetra(i, j, LETRA_M, this);
                    numCocos++;
                }
                else if (i == 7 && j == 7)
                {
                    cocos[numCocos] = new CocoLetra(i, j, LETRA_A2, this);
                    numCocos++;
                }
                else if (i == 10 && j == 7)
                {
                    cocos[numCocos] = new CocoLetra(i, j, LETRA_N, this);
                    numCocos++;
                }
                else if (i == 7 && j == 4)
                {
                    cocos[numCocos] = new CocoOrientado(i, j, DIRECCION_ABAJO, this);
                    numCocos++;
                }
                else if (i == 7 && j == 6)
                {
                    cocos[numCocos] = new CocoOrientado(i, j, DIRECCION_ARRIBA, this);
                    numCocos++;
                }
                else if (i == 5 && j == 5)
                {
                    cocos[numCocos] = new CocoOrientado(i, j, DIRECCION_DERECHA, this);
                    numCocos++;
                }
                else if (i == 9 && j == 5)
                {
                    cocos[numCocos] = new CocoOrientado(i, j, DIRECCION_IZQUIERDA, this);
                    numCocos++;
                }
                else if (i == 4 && j == 5)
                {
                    cocos[numCocos] = new CocoEnfadador(i, j, this);
                    numCocos++;
                }
                else if (i == 10 && j == 5)
                {
                    cocos[numCocos] = new CocoEnfadador(i, j, this);
                    numCocos++;
                }
                else
                {
                    cocos[numCocos] = new Coco(i, j, this);
                    numCocos++;
                }
            }
        }
    }
    /*for (int i = offSet_X; i <= ancho + offSet_X; i++)
    {
        for (int j = offSet_Y; j <= alto; j++)
        {
            if (i == 0 + offSet_X || j == 0 + offSet_Y || i == ancho + offSet_X || j == alto)
            {
                paredes[numParedes] = new Pared(i, j);
                numParedes++;
            }
            else if (i > offSet_X + 1 && i < ancho + offSet_X - 1 && j > offSet_Y + 1 && j < alto + offSet_Y - 2 && i != offSet_X + 4 && j != offSet_Y + 4)
            {
                paredes[numParedes] = new Pared(i, j);
                numParedes++;
            }
            else if(i == 1 + offSet_X && j == 1 + offSet_Y)
            {
                cocos[numCocos] = new CocoLetra(i, j, LETRA_P, this);
                numCocos++;
            }
            else if(i == 4 + offSet_X && j == 1 + offSet_Y)
            {
                cocos[numCocos] = new CocoLetra(i, j, LETRA_A1, this);
                numCocos++;
            }
            else if(i == 7 + offSet_X && j == 1 + offSet_Y)
            {
                cocos[numCocos] = new CocoLetra(i, j, LETRA_C, this);
                numCocos++;
            }
            else if(i == 1 + offSet_X && j == 6 + offSet_Y)
            {
                cocos[numCocos] = new CocoLetra(i, j, LETRA_M, this);
                numCocos++;
            }
            else if(i == 4 + offSet_X && j == 6 + offSet_Y)
            {
                cocos[numCocos] = new CocoLetra(i, j, LETRA_A2, this);
                numCocos++;
            }
            else if(i == 7 + offSet_X && j == 6 + offSet_Y)
            {
                cocos[numCocos] = new CocoLetra(i, j, LETRA_N, this);
                numCocos++;
            }
            else if(i == 4 + offSet_X && j == 3 + offSet_Y)
            {
                cocos[numCocos] = new CocoOrientado(i, j, DIRECCION_ABAJO, this);
                numCocos++;
            }
            else if(i == 4 + offSet_X && j == 5 + offSet_Y)
            {
                cocos[numCocos] = new CocoOrientado(i, j, DIRECCION_ARRIBA, this);
                numCocos++;
            }
            else if(i == 2 + offSet_X && j == 4 + offSet_Y)
            {
                cocos[numCocos] = new CocoOrientado(i, j, DIRECCION_DERECHA, this);
                numCocos++;
            }
            else if(i == 6 + offSet_X && j == 4 + offSet_Y)
            {
                cocos[numCocos] = new CocoOrientado(i, j, DIRECCION_IZQUIERDA, this);
                numCocos++;
            }
            else if(i == 1 + offSet_X && j == 4 + offSet_Y)
            {
                cocos[numCocos] = new CocoEnfadador(i, j, this);
                numCocos++;
            }
            else if(i == 7 + offSet_X && j == 4 + offSet_Y)
            {
                cocos[numCocos] = new CocoEnfadador(i, j, this);
                numCocos++;
            }
            else
            {
                cocos[numCocos] = new Coco(i, j, this);
                numCocos++;
            }
        }
    }*/
}

void Tablero::CompruebaChoques()
{
    // Actualizar física
    // ...
    fantasmas[0]->CompruebaChoques();
    pacman->CompruebaChoques();
}

void Tablero::Actualiza()
{
    // Actualizar lógica
    // ...
    for (int i = 0; i < numParedes; i++)
    {
        paredes[i]->Actualiza();
    }
    int auxCocos = 0;
    for (int i = 0; i < numCocos; i++)
    {
        cocos[i]->Actualiza();

        if (cocos[i]->EstaComido())
            auxCocos++;
        numCocosComidos = auxCocos;
    }
    fantasmas[0]->Actualiza();
    pacman->Actualiza();
}

void Tablero::Dibuja()
{
    // Limpiar tilemaps
    // ...
    NOE_LimpiaTilemap(TILEMAP_PACMAN, noe_tileVacio);
    NOE_LimpiaTilemap(TILEMAP_FANTASMAS, noe_tileVacio);
    NOE_LimpiaTilemap(TILEMAP_PAREDES, noe_tileVacio);
    NOE_LimpiaTilemap(TILEMAP_COCOS, noe_tileVacio);

    // Dibujar tilemaps
    // ...

    pacman->Dibuja();
    fantasmas[0]->Dibuja();
    for (int i = 0; i < numParedes; i++)
    {
        paredes[i]->Dibuja();
    }

    for (int i = 0; i < numCocos; i++)
    {
        if (!cocos[i]->EstaComido())
            cocos[i]->Dibuja();
    }

    NOE_DibujaTilemap(TILEMAP_COCOS);
    NOE_DibujaTilemap(TILEMAP_PAREDES);
    NOE_DibujaTilemap(TILEMAP_FANTASMAS);
    NOE_DibujaTilemap(TILEMAP_PACMAN);
}

Pacman *Tablero::ObtenPacman()
{
    return pacman;
}
Pared *Tablero::BuscaPared(int posX, int posY)
{
    Pared *ret;
    ret = 0;

    for (int i = 0; i < numParedes && ret == 0; i++)
    {
        if (posX == paredes[i]->ObtenPosX() && posY == paredes[i]->ObtenPosY())
        {
            ret = paredes[i];
        }
    }

    return ret;
}

Fantasma *Tablero::BuscaFantasma(int posX, int posY)
{
    Fantasma *ret;
    ret = 0;

    for (int i = 0; i < numFantasmas && ret == 0; i++)
    {
        if (posX == fantasmas[i]->ObtenPosX() && posY == fantasmas[i]->ObtenPosY())
        {
            ret = fantasmas[i];
        }
    }

    return ret;
}

Pacman *Tablero::BuscaPacman(int posX, int posY)
{
    Pacman *ret;
    ret = 0;

    if (posX == pacman->ObtenPosX() && posY == pacman->ObtenPosY())
    {
        ret = pacman;
    }

    return ret;
}

Pacman *Tablero::BuscaPacmanDireccion(int posX, int posY, int dirX, int dirY)
{
    Pacman *ret;
    ret = 0;
    int casillaX = posX;
    int casillaY = posY;

    while (ret == 0 && !BuscaPared(casillaX, casillaY))
    {
        ret = BuscaPacman(casillaX, casillaY);

        casillaX += dirX;
        casillaY += dirY;
    }

    return ret;
}

Coco *Tablero::BuscaCoco(int posX, int posY)
{
    Coco *ret;
    ret = 0;

    for (int i = 0; i < numCocos && ret == 0; i++)
    {
        if (posX == cocos[i]->ObtenPosX() && posY == cocos[i]->ObtenPosY())
        {
            ret = cocos[i];
        }
    }

    return ret;
}

bool Tablero::TodosCocosComidos()
{
    bool ret = false;

    if (numCocosComidos == numCocos)
    {
        ret = true;
    }

    return ret;
}

int Tablero::ObtenNumeroFantasmas()
{
    return numFantasmas;
}

Tablero::~Tablero()
{
    // Eliminar objetos
    delete pacman;
    pacman = 0;
    delete fantasmas[0];
    fantasmas[0] = 0;
    for (int i = numParedes; i >= 0; i--)
    {
        delete paredes[i];
        paredes[i] = 0;
        numParedes--;
    }
    for (int i = numCocos; i >= 0; i--)
    {
        delete cocos[i];
        cocos[i] = 0;
        numCocos--;
    }
}
