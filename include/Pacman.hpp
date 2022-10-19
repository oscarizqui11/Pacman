#ifndef PACMAN_HPP
#define PACMAN_HPP

#define TILEMAP_PACMAN 3
#define CICLOS_ENFADO_PACMAN 20

#include "Tablero.hpp"
#include "Common.hpp"
#include "Fantasma.hpp"

class Pared;
class Coco;
class Fantasma;
class Tablero;

class Pacman
{
private:
    bool muerto;
    Direccion direccion;
    int posX;
    int posY;
    bool chocaConParedArriba;
    bool chocaConParedAbajo;
    bool chocaConParedIzquierda;
    bool chocaConParedDerecha;
    int tilePacman;
    bool enfadado;
    int ciclosEnfado;
    Tablero* tablero;
    Position previousPosition;
    Letra ultimaLetraRecibida;

public:
    Pacman(int px, int py, Tablero* t);
    void CompruebaChoques();
    void CompruebaChoquesConParedes();
    void CompruebaChoquesConCocos();
    void CompruebaChoquesConFantasmas();
    Fantasma* SeHaCruzadoConFantasma();
    void Actualiza();
    int ObtenPosX();
    int ObtenPosY();
    Letra ObtenUltimaLetra();
    void RecibeLetra(Letra l);
    Direccion ObtenDireccionPacman();
    bool EstaMuerto();
    void Enfada();
    void Dibuja();
    void ActualizaAnimacion();
    ~Pacman();
};

#endif
