#include "map.h"
#include <iostream>

Map::Map(int difficulty)
{
	rows = (5 * difficulty + rand() % 5);
	cols = (5 * difficulty + rand() % 5);
	md = new char*[rows];
	for (int i = 0; i < rows; i++) {
		md[i] = new char[cols + 1];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			md[i][j] = '.';
		}
	}
}

/*Map::~Map(void)
{
	for (int i = 0; i < rows; i++)
		delete md[i];
	delete[] md;
}*/

//Cell modifier method
void Map::updateCell(int i, int j, char c)
{
	md[j][i] = c;
}

int Map::getRows()
{
	return rows;
}

int Map::getCols()
{
	return cols;
}

char Map::getCell(int i, int j)
{
	return md[j][i];
}

std::ostream & operator<<(std::ostream & out, Map x)
{
	// TODO: insert return statement here
	for (int i = 0; i < x.getRows(); i++) {
		for (int j = 0; j < x.getCols(); j++) {
			out << x.getCell(j, i) << " ";
		}
		out << std::endl;
	}
	return out;
}