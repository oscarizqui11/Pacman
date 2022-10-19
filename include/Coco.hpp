#ifndef COCO_HPP
#define COCO_HPP

#define TILEMAP_COCOS 1

class Tablero;

class Coco
{
protected:
    int posX;
    int posY;
    bool comido;
    Tablero* tablero;

public:
    Coco(int px, int py, Tablero* t);
    void Actualiza();
    int ObtenPosX();
    int ObtenPosY();
    bool EstaComido();
    virtual void IntentaComer();
    virtual void Dibuja();
    virtual ~Coco();
};

#endif
