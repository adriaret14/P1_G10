#pragma once
#include <ostream>

class Map
{
public:
	Map(int difficulty);														//Constructor
	//~Map(void);																	//Destructor
	friend std::ostream& operator<< (std::ostream &out, Map x);					//output stream operator overload
	void updateCell(int i, int j, char c);										//Setter de celda
	int getRows();																//Getter de rows
	int getCols();																//Getter de cols
	char getCell(int i, int j);													//Getter de celda

private:

	char **md;
	int rows;
	int cols;

};