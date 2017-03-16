#pragma once
#include "map.h"
class CoinManager
{
public:
	//Constructor
	CoinManager(Map map);
	//Destructor
	~CoinManager();
	//coin update method
	void updateCoins(Map map);
private:
	int coins;
};

