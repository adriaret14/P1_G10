#pragma once
#include "Input.h"
#include "Map.h"
#include "CoinManager.h"


class Player
{
public:
	Player(Map &m, CoinManager &c);
	void updatePlayer(Input::Key k);		//A esta función se le pasan como parametros un puntero a la matriz y la tecla pulsada
	/*void prueba(char array[][5]);*/							//Método de prueba de matrices dinamicas y paso y acceso de matrices por funciones
	int getScore();												//Getter de score
	int getX();													//Getter de x
	int getY();													//Getter de y

private:
	int x;
	int y;
	int score;
	Map &m;
	CoinManager &c;
};

