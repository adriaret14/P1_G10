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

	//std::cout << nMonedas;

	//Creamos el mapa
	Map m(dificultad);
	//Creamos el coin manager
	CoinManager c(m);
	//Creamos al jugador
	Player p(m, c);
	//std::cout << m;
	//std::cout << m.getCell(p.getX(), p.getY());
	//std::cout << m;
	//p.updatePlayer(Input::Key::W);
	//system("cls");
	std::cout << m << std::endl << "BB HEADSHOTS: " << p.getScore() << "/" << nMonedas;
	//std::cout << m;
	Input::Key input;
	do {
		input = Input::getKey();
		if (input != Input::Key::NONE) {
			p.updatePlayer(input);
			system("cls");
			std::cout << m << std::endl << "BB HEADSHOTS: " << p.getScore() << "/" << nMonedas ;
		}
	} while ((input != Input::Key::ESC) && (p.getScore() < nMonedas));
	
	//m.~Map();
	system("cls");
	std::cout << "Fin de la partida";
}