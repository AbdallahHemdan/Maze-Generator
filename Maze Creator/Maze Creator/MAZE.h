#pragma once
#include "UnionFindSet.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class MAZE
{
private:
	bool** Con; // To Create The Maze (2D Array)
	int Width;
	int Height;
	UnionFindSet UFSet;

public:
	MAZE();
	MAZE(int Wid, int Hei);
	void Reset(int Wid, int Hei);
	void SetColume(int R1, int Tail);
	void SetRow(int R1, int Tail);
	void Expand(int Now, int R, int Step, int MaxStep);
	void Create();
	void Print();
	void PrintToFile(string FileName);
	~MAZE();
};
