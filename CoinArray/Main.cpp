#include "Player.h"
#include "Map.h"
#include "CoinManager.h"
#include "Input.h"
#include <iostream>
#include <ctime>


void main() {
	srand(static_cast<unsigned int>(time(nullptr)));
	int dificultad;

	//Pedimos la dificultad del juego
	do{
		system("cls");
		std::cout << "Escoge una dificultad de juego:\n\t-FACIL(1)\n\t-MEDIO(2)\n\t-DIFICIL(3)\n";
		std::cin >> dificultad;

	} while (dificultad < 1 || dificultad>3);
	system("cls");
	//Creamos el mapa
	Map m(dificultad);
	//m.updateCell(4, 2, '@');
	//Creamos al jugador
	std::cout << m;
	
}