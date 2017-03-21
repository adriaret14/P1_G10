#include "Player.h"
#include <iostream>


Player::Player(Map &map, CoinManager &coin) :
	m(map),
	c(coin),
	x(rand() % m.getSize()),
	y(rand() % m.getSize()),
	score(0)
{
	m.updateCell(x,y,'@');
}


Player::~Player()
{
}

void Player::updatePlayer(Input::Key k)
{
	int prev_x = x;
	int prev_y = y;

	//Miramos desde el Input
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

	//Updateamos el score del player
	if (m.getCell(x, y) == '$')
	{
		score++;
		c.updateCoins(m);
	}

	//Updateamos la posicion del player
	m.updateCell(prev_x, prev_y, '.');
	m.updateCell(x, y, '@');

}

/*void Player::prueba(char array[][5])
{
	array[1][3] = 'x';
	std::cout << array[1][3];
}*/

int Player::getScore()
{
	return score;
}

int Player::getX()
{
	return x;
}

int Player::getY()
{
	return y;
}
