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
	bool com = true;// To altarnate between complet and half brick.
	bool hlf = false; // Para restar 1 a rw cuando entre half
	string line = "";
		
	for (int rw = 0; rw < rows; rw++)
	{
		for (int br = 0; br < bricks; br++)
		{
			if (com)
			{
				line.append(full,2);
				com = false;
			}
			else
			{
				if (hlf)
				{
					line.push_back(half);
					hlf = false;
				}
				else
				{
					line.push_back(half);
					--br;
					hlf = true;
				}

				com = true;
			}
			line.push_back(mort);
		}		
		cout << line << "\n";
		line.clear();
	}
}
