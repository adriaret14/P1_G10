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

	int nMonedas = 30 * dificultad + rand() % 30;

	//Creamos el mapa
	Map m(dificultad);
	//Creamos el coin manager
	CoinManager c(m);
	//Creamos al jugador
	Player p(m, c);


	//m.updateCell(3, 1, '#');

	//Player p(m);
	//std::cout <<p.getX() << "\t" << p.getY();
