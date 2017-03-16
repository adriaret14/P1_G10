#include "CoinManager.h"

CoinManager::CoinManager(Map map)
{
	createCoins(map);
}

CoinManager::~CoinManager()
{
	delete &coins;
}

void CoinManager::updateCoins(Map map)
{
	coins--;
	if (coins == 0)
	{
		createCoins(map);
	}
}

void CoinManager::createCoins(Map map)
{
	coins = (map.getSize()*map.getSize()) / 100 * 3 + rand() % (map.getSize()*map.getSize() / 10);
	int count = 0;
	while (count <= coins)
	{
		int x = rand() % map.getSize();
		int y = rand() % map.getSize();

		if (map.getCell(x, y) == '.')
		{
			map.updateCell(x, y, '$');
			count++;
		}
	}
}