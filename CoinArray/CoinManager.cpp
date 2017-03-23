#include "CoinManager.h"

CoinManager::CoinManager(Map &map) :
	m(map)
{
	createCoins();
}

CoinManager::~CoinManager()
{
}

void CoinManager::updateCoins()
{
	coins--;
	if (coins <= 0)
	{
		createCoins();
	}
}

void CoinManager::createCoins()
{
	do {
		coins = static_cast<int>((static_cast<float>(m.getRows())*static_cast<float>(m.getCols())) / 100 * 3 + rand() % static_cast<int>(static_cast<float>(m.getRows())*static_cast<float>(m.getCols()) / 10));
	} while (coins == 0);
	int count = 0;
	while (count < coins)
	{
		int x = rand() % m.getCols();
		int y = rand() % m.getRows();

		if (m.getCell(x, y) == '.')
		{
			m.updateCell(x, y, '$');
			count++;
		}
	}
}

int CoinManager::getCoins() {
	return coins;
}