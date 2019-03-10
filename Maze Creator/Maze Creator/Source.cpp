/*Author : Abdallah Hemdan */
/***************************/
/* ___  __
* |\  \|\  \
* \ \  \_\  \
*  \ \   ___ \emdan
*   \ \  \\ \ \
*    \ \__\\ \_\
*     \|__| \|__|
*/
#include <iostream>
#include "MAZE.h"
#define endl '\n'

using namespace std;

void Intro()
{
	cout << endl;
	cout << " Abdallah Hemdan" << endl;
	cout << endl;
	cout << "\t\t\t\t\t Welcome To Our Maze Generator" << endl;
	cout << "\t\t\t\t\t-------------------------------" << endl;
}

int main()
{
	MAZE Maze;
	Intro();
	
	int Width, Height;
	cout << " - Please, enter the maze width  --> ";
	cin >> Width;
	cout << endl;
	cout << " - Please, enter the maze height --> ";
	cin >> Height;

	Maze.Reset(Width, Height);
	Maze.Create();

	cout << endl << endl;
	cout << " - Choose The Output format.." << endl << endl;
	cout << " 1- File Output " << endl << endl;
	cout << " 2- Console Output " << endl;

	int OutPutType;
	cout << " == ";
	cin >> OutPutType;

	if (OutPutType == 1)
	{
		string FileName;
		cout << endl;
		cout << "Please Suggest a Name for The Result File : "; 
		cin >> FileName;
		cout << endl;
		Maze.PrintToFile(FileName);
		cout << "Done.." << endl;
		cout << "Your Output File Name : " << FileName  << ".txt" << endl;
	}
	else
	{
		cout << "Done.." << endl;
		Maze.Print();
	}

	cout << endl << endl;
	cout << "\t\t\t\t      Thanks to use our maze generator..!!" << endl;
	cout << "\t\t\t\t\t-------------------------------" << endl;
	return 0;
}