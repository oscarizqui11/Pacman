#ifndef PARED_HPP
#define PARED_HPP

#define TILEMAP_PAREDES 0

class Pared
{
private:
    int posX;
    int posY;

public:
    Pared(int px, int py);
    void Actualiza();
    void Dibuja();
    int ObtenPosX();
    int ObtenPosY();
    ~Pared();
};

#endif
