#include "../Header/Pch.h"
#include "../Header/Build.h"

using namespace std;

Build::Build(int rows, int bricks)
{
	if (rows < 1)
	{
		cout << "Error en las las filas"<<endl; //TODO: Lanzar exepcion aqui
		return;
	}
	if (bricks < 1)
	{
		cout << "Error en los ladrillos" << endl; //TODO: Lanzar exepcion aqui
		return;
	}
	if (rows * bricks > 10000)
	{
		cout << "Naah, too much...here's my resignation." << endl;
		return;
	}

	
	this->rows = rows;
	this->bricks = bricks;
	this->full[0] = 220;
	this->full[1] = 220;
	this->half = 220;
	this->mort = '|';

	makeWall();

}

Build::Build(int& rows, int& bricks)
{
	if (rows < 1)
	{
		cout << "Error en las las filas" << endl; //TODO: Lanzar exepcion aqui
		return;
	}
	if (bricks < 1)
	{
		cout << "Error en los ladrillos" << endl; //TODO: Lanzar exepcion aqui
		return;
	}
	if (rows * bricks > 10000)
	{
		cout << "Naah, too much...here's my resignation." << endl;
		return;
	}


	this->rows = rows;
	this->bricks = bricks;
	this->full[0] = 220;
	this->full[1] = 220;
	this->half = 220;
	this->mort = '|';

	makeWall();
}

void Build::makeWall()
{
	bool comLine = true;// To altarnate between make a line using only full brick and other start with half brick.
	bool hlf = false; // Para restar 1 a rw cuando entre half
	string line = "";
		
	for (int rw = 0; rw < rows; rw++)
	{
		//TODO: ACOMODAR PARA QUE SOLO SE INSERTEN LA MITDAD DE LOS BLOQUES CUANDO SE NECESITEN,VER EL README.
		for (int br = 0; br < bricks; br++)
		{
			line.append(full,2);
			line.push_back(mort);
		}
		if (comLine)
		{
			cout << line << "\n";
		}
		else
		{
			line.append(full, 2);
			line.erase(0, 1); // To erase a half block from the begining, to erase 0 to 1.
			line.erase(line.end() - 2); //To erase using end iterator -2;
			line.push_back(mort);
			cout << line << "\n";
		}
		
		comLine = !comLine;
		line.clear();	

	}		
}
