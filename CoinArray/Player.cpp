#include "Player.h"
#include <iostream>


Player::Player(int mapSize) :
	x(rand()%mapSize),
	y(rand()%mapSize),
	score(0)
{
}


Player::~Player()
{
}

void Player::updatePlayer(char matriz[][5], Input::Key k)
{
	int prev_x = x;
	int prev_y = y;

	switch (k) {
	case Input::Key::W:
		y = y - 1;
		break;
	case Input::Key::A:
		x = x - 1;
		break;
	case Input::Key::S:
		y = y + 1;
		break;
	case Input::Key::D:
		x = x + 1;
		break;
	}

	//Modificamos la posicion del jugador
	matriz[prev_x][prev_y]='.';
	matriz[x][y] = '@';

	//Comprobamos si ha recogido una moneda
	if (matriz[x][y] == '$') {
		score = score + 1;
	}
}

void Player::prueba(char array[][5])
{
	array[1][3] = 'x';
	std::cout << array[1][3];
}
