#include "Player.h"
#include "Map.h"
#include "CoinManager.h"
#include "Input.h"
#include <iostream>
#include <ctime>


void main() {
	/*char array[3][5]{{'h', 'a', 'l', 'o', '\0'},{ 'h', 'o', 'l', 'a', '\0' },{ 'h', 'o', 'l', 'a', '\0' } };
	Player p1;
	p1.prueba(array);*/

	srand(static_cast<unsigned int>(time(nullptr)));
	int dificultad;


	//Pedimos la dificultad del juego
	do{
		system("cls");
		std::cout << "Escoge una dificultad de juego:\n\t-FACIL(1)\n\t-MEDIO(2)\n\t-DIFICIL(3)\n";
		std::cin >> dificultad;

	} while (dificultad < 1 || dificultad>3);

	//Creamos el mapa
	Map m(dificultad);
	//m.updateCell(4, 2, '@');
	//Creamos al jugador
	std::cout << m;

	Player p(m);
	std::cout <<p.getX() << "\t" << p.getY();
	
}