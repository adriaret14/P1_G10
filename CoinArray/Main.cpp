#include "Player.h"
#include "Map.h"
#include "CoinManager.h"
#include "Input.h"
#include <iostream>
#include <ctime>


void main() {
	srand(static_cast<unsigned int>(time(nullptr)));
	int dificultad;
	double timeStart, timeNow;
	int mins, secs;

	//Pedimos la dificultad del juego
	do {
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
	timeStart = clock();
	std::cout << m << std::endl << "Monedas: " << p.getScore() << "/" << nMonedas;
	//std::cout << m;
	Input::Key input;
	do {
		timeNow = clock();
		mins = static_cast<int>((timeNow - timeStart) / static_cast<double>(CLOCKS_PER_SEC) / 60);
		secs = static_cast<int>((timeNow - timeStart) / static_cast<double>(CLOCKS_PER_SEC)) % 60;
		input = Input::getKey();
		if (input != Input::Key::NONE) {
			p.updatePlayer(input);
			system("cls");
			std::cout << m << std::endl << "Monedas: " << p.getScore() << "/" << nMonedas;
		}
	} while ((input != Input::Key::ESC) && (p.getScore() < nMonedas));

	//m.~Map();
	system("cls");
	std::cout << "\t" << "Fin de la partida" << std::endl;
	if (!(p.getScore() < nMonedas))
	{
		std::cout << std::endl;
		std::cout << "Monedas conseguidas: \t" << p.getScore() << std::endl;
		std::cout << "Tiempo invertido: \t" << mins << ":" << secs << std::endl;
	}
	do
	{
		input = Input::getKey();
	} while (input != Input::Key::ESC);
}