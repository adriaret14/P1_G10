#pragma once
#include "map.h"
class CoinManager
{
public:
	CoinManager(Map &map);							//Constructor
	~CoinManager();									//Destructor
	void updateCoins();						//coin update method
	void createCoins();			//coin creation method
private:
	int coins;
	Map &m;
};

