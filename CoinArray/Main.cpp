#include "Player.h"
#include "Map.h"
#include "CoinManager.h"
#include "Input.h"
#include <iostream>
#include <ctime>


void main() {
	srand(static_cast<unsigned int>(time(nullptr)));
	/*
	char array[3][5]{{'h', 'a', 'l', 'o', '\0'},{ 'h', 'o', 'l', 'a', '\0' },{ 'h', 'o', 'l', 'a', '\0' } };
	Player p1;
	p1.prueba(array);
	*/
	int difficulty = 1;
	std::cout << "Escoge la dificultad del juego (1, 2 o 3): " << std::endl;
	do {
		if (difficulty > 3 || difficulty < 1)
		{
			system("cls");
			std::cout << "Dificultad fuera del rango. Escoge de nuevo: " << std::endl;
		}
		std::cin >> difficulty;
	} while (difficulty > 3 || difficulty < 1);

	Map m(difficulty);
	Player p(m);
	m.updateCell(p.getX(), p.getY(), '@');
	std::cout << m;
}