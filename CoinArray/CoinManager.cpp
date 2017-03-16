#include "CoinManager.h"



CoinManager::CoinManager()
{
}


CoinManager::~CoinManager()
{
}

void CoinManager::updateCoins()
{
	coins = coins - 1;
	if (coins == 0) {

	}
}
