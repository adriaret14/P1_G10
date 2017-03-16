#include "map.h"
#include <iostream>
#include <fstream>
#include <sstream>

Map::Map(int difficulty) :
	difficulty(difficulty),
	rows(5 * difficulty + rand() % 11),
	columns(rows)
{
	md = new char*[rows];
	for (int i = 0; i < rows; i++)
		md[i] = new char[columns];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			md[i][j] = '.';
		}
	}
}

Map::~Map(void)
{
	for (int i = 0; i < rows; i++)
		delete md[i];
	delete[] md;
}

//Cell modifier method
void Map::cellUpdate(int i, int j, char c)
{
	md[i][j] = c;
}

int Map::size()
{
	return rows;
}

char Map::cell(int i, int j)
{
	return md[i][j];
}

std::ostream & operator<<(std::ostream & out, Map x)
{
	// TODO: insert return statement here
	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < x.size(); j++) {
			out << x.cell(i, j) << " ";
		}
		out << std::endl;
	}
	return out;
}