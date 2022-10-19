#include <stdio.h>
#include "NoEntiendo.hpp"
#include "Common.hpp"
#include "Tablero.hpp"
#include "Pacman.hpp"
#include "Fantasma.hpp"
#include "Pared.hpp"
#include "Coco.hpp"

#define TIEMPO_PASO 0.1f

#define MUSICA 0
#define DECORADO_FONDO 0
#define DECORADO_FRENTE 1

float tiempoPaso;
Tablero* tablero;

int main()
{
	NOE_Inicia();

	NOE_ReproduceMusica(MUSICA, 100, 100);

	tiempoPaso = TIEMPO_PASO;
	tablero = new Tablero();

	while (!NOE_ObtenTeclaPulsada(NOE_TECLA_ESCAPE) && !tablero->TodosCocosComidos() && !tablero->ObtenPacman()->EstaMuerto())
	{

		NOE_Actualiza();

		tiempoPaso = tiempoPaso - NOE_ObtenTiempoDesdeActualizacion() / 1000.0f;

		if (tiempoPaso <= 0)
		{
			tablero->CompruebaChoques();
			
			tablero->Actualiza();

			tiempoPaso = TIEMPO_PASO;
		}

		// Dibujado

		NOE_LimpiaPantalla(0, 0, 0);

		NOE_DibujaDecorado(DECORADO_FONDO);

		NOE_DibujaDecorado(DECORADO_FRENTE);

		tablero->Dibuja();

		NOE_MuestraPantalla();
	}

	delete tablero;
	tablero = 0;

	NOE_ParaMusica();

	NOE_Finaliza();

	return 0;
}