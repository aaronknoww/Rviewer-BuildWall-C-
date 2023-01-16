#pragma once

class Build
{
private:
	int rows;
	int bricks;
	char full [2];
	char half;
	char mort;
public:
	Build(int rows, int bricks);
	Build(int &rows, int &bricks);
	//~Build();

private:
	void makeWall();

};
