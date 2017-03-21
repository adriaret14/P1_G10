#include "CoinManager.h"

CoinManager::CoinManager(Map &map) :
	m(map)
{
	createCoins();
}

CoinManager::~CoinManager()
{
	delete &coins;
}

void CoinManager::updateCoins()
{
	coins--;
	if (coins == 0)
	{
		createCoins();
	}
}

void CoinManager::createCoins()
{
	coins = (m.getSize()*m.getSize()) / 100 * 3 + rand() % (m.getSize()*m.getSize() / 10);
	int count = 0;
	while (count <= coins)
	{
		int x = rand() % m.getSize();
		int y = rand() % m.getSize();

		if (m.getCell(x, y) == '.')
		{
			m.updateCell(x, y, '$');
			count++;
		}
	}
}