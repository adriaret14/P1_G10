#include "map.h"
#include <iostream>

Map::Map(int difficulty) :
	size(5 * difficulty + rand() % 11)
{
	md = new char*[size];
	for (int i = 0; i < size; i++)
		md[i] = new char[size];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			md[i][j] = '.';
		}
	}
}

Map::~Map(void)
{
	for (int i = 0; i < size; i++)
		delete md[i];
	delete[] md;
}

//Cell modifier method
void Map::updateCell(int j, int i, char c)
{
	md[i][j] = c;
}

int Map::getSize()
{
	return size;
}

char Map::getCell(int j, int i)
{
	return md[i][j];
}

std::ostream & operator<<(std::ostream & out, Map x)
{
	// TODO: insert return statement here
	for (int i = 0; i < x.getSize(); i++) {
		for (int j = 0; j < x.getSize(); j++) {
			out << x.getCell(i, j) << " ";
		}
		out << std::endl;
	}
	return out;
}