#pragma once
#include "Input.h";


class Player
{
public:
	Player();
	~Player();
	void updatePlayer(char matriz[][5], Input::Key k);			//A esta funci�n se le pasan como parametros un puntero a la matriz y la tecla pulsada
	void prueba(char array[][5]);								//M�todo de prueba de matrices dinamicas y paso y acceso de matrices por funciones

private:
	int x;
	int y;
	int score;
};

