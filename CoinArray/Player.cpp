#include "Player.h"
#include <iostream>


Player::Player(Map &map, CoinManager &coin) :
	m(map),
	c(coin),
	x(0),
	y(0),
	score(0)
{
	x = (rand() % m.getRows());
	y = (rand() % m.getCols());
	m.updateCell(x,y,'@');
}

void Player::updatePlayer(Input::Key k)
{
	int prev_x = x;
	int prev_y = y;

	//Miramos desde el Input
	switch (k) {
	case Input::Key::W:
		if (y > 0) {
			y = y - 1;
		}
		break;
	case Input::Key::A:
		if (x > 0) {
			x = x - 1;
		}
		break;
	case Input::Key::S:
		if (y < m.getCols() - 1) {
			y = y + 1;
		}
		break;
	case Input::Key::D:
		if (x < m.getRows() - 1) {
			x = x + 1;
		}
		break;
	}

	//Updateamos el score del player
	if (m.getCell(x, y) == '$')
	{
		score++;
		c.updateCoins();
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
