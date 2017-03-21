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
	coins = (m.getRows()*m.getCols()) / 100 * 3 + rand() % (m.getRows()*m.getCols() / 10);
	int count = 0;
	while (count <= coins)
	{
		int x = rand() % m.getRows();
		int y = rand() % m.getCols();

		if (m.getCell(x, y) == '.')
		{
			m.updateCell(x, y, '$');
			count++;
		}
	}
}