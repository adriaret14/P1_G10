#pragma once
#include "map.h"
class CoinManager
{
public:
	CoinManager(Map map);							//Constructor
	~CoinManager();									//Destructor
	void updateCoins(Map map);						//coin update method
	void CoinManager::createCoins(Map map);			//coin creation method
private:
	int coins;
};

