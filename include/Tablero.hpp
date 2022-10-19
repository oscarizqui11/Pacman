#ifndef TABLERO_HPP
#define TABLERO_HPP

#define MAX_FANTASMAS 8
#define MAX_PAREDES 64
#define MAX_COCOS 64

class Pacman;
class Fantasma;
class Pared;
class Coco;

enum Direccion
{
    DIRECCION_IZQUIERDA,
    DIRECCION_DERECHA,
    DIRECCION_ARRIBA,
    DIRECCION_ABAJO
};

enum Letra
{
    LETRA_VACIA,
    LETRA_P,
    LETRA_A1,
    LETRA_C,
    LETRA_M,
    LETRA_A2,
    LETRA_N
};

class Tablero
{
private:
    Pacman *pacman;
    Fantasma *fantasmas[MAX_FANTASMAS];
    int numFantasmas;
    Pared *paredes[MAX_PAREDES];
    int numParedes;
    Coco *cocos[MAX_COCOS];
    int numCocos;
    int numCocosComidos;
    int ancho;
    int alto;

    int offSet_X;
    int offSet_Y;

public:
    Tablero();
    void CompruebaChoques();
    void Actualiza();
    void Dibuja();
    Pacman *ObtenPacman();
    Pared *BuscaPared(int posX, int posY);
    Fantasma *BuscaFantasma(int posX, int posY);
    Pacman *BuscaPacman(int posX, int posY);
    Pacman *BuscaPacmanDireccion(int posX, int posY, int dirX, int dirY);
    Coco *BuscaCoco(int posX, int posY);
    bool TodosCocosComidos();
    int ObtenNumeroFantasmas();
    ~Tablero();
};

#endif