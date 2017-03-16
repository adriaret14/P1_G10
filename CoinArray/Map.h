#pragma once
#include <ostream>

class Map
{
public:
	//constructors
	Map(int difficulty);

	//destructor
	~Map(void);

	//Cell modifier method
	void updateCell(int i, int j, char c);

	//output stream operator overload
	friend std::ostream& operator<< (std::ostream &out, Map x);

	//Atribute retrieving methods
	int getSize();
	char getCell(int i, int j);

private:

	char **md;
	int rows;
	int columns;

};