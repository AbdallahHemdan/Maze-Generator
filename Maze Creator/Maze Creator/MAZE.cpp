#include "MAZE.h"

MAZE::MAZE()
{
	Con = nullptr;
}

MAZE::MAZE(int Wid, int Hei)
{
	Con = nullptr;
	Reset(Wid, Hei);
}

void MAZE::Reset(int Wid, int Hei)
{
	if (Con != nullptr)
	{
		Con = nullptr;
	}
	Width = Wid;
	Height = Hei;

	int Total = (Wid + 1) * (Hei + 1);
	Con = new bool*[Total];

	for (int i = 0; i < Total; i++)
	{
		Con[i] = new bool[Total];
		for (int j = 0; j < Total; j++)
		{
			Con[i][j] = false;
		}
	}
	UFSet.Reset(Total + 1);
}

void MAZE::SetColume(int R1, int Tail)
{
	int R2 = R1 + Height + 1;
	while (R1 < Tail)
	{
		UFSet.Union(R1, R2);
		Con[R1][R2] = true;
		Con[R2][R1] = true;
		R1 = R2;
		R2 += Height + 1;
	}
}

void MAZE::SetRow(int R1, int Tail)
{
	int R2 = R1 + 1;

	while (R1 < Tail)
	{
		UFSet.Union(R1, R2);
		Con[R1][R2] = true;
		Con[R2][R1] = true;

		R1++;
		R2++;
	}
}

void MAZE::Expand(int Now, int R, int Step, int MaxStep)
{
	int Direction[4] = { -Height - 1, Height + 1, -1, 1 };
	int Next, Total = 0, b[4];
	bool flag = false;
	if (Step == MaxStep)
		return;
	srand(time(0));
	if (rand() % 32 == 1)
		return;
	for (int i = 0; i < 4; i++)
	{
		Next = Now + Direction[i];
		if ((Next >= 0) && (Next <= (Width + 1) * (Height + 1)))
		{
			if ((!Con[Next][Now]) && (!Con[Now][Next]) && (UFSet.FindRoot(Next) != R)
				&& (UFSet.FindRoot(Next) != UFSet.FindRoot(Now)))
			{
				b[Total] = Next;
				Total++;
				flag = true;
			}
		}
	}
	if (flag)
	{
		srand(time(0));
		Next = b[rand() % Total];
		Step++;
		Con[Now][Next] = true;
		Con[Next][Now] = true;
		UFSet.Union(Now, Next);
		UFSet.Union(Next, Now);
		Expand(Next, R, Step, MaxStep);
	}
}

void MAZE::Create()
{
	int tot = (Width + 1) * (Height + 1), Select;
	bool* Check;

	UFSet.Reset(tot);

	SetColume(Height + 1, Width * (Height + 1));
	SetRow(Width * (Height + 1), (Width + 1) * (Height + 1) - 1);

	SetRow(0, Height);
	SetColume(Height, Width * (Height + 1) - 1);
	Check = new bool[Width];

	for (int i = 0; i < Width; i++)
		Check[i] = false;

	for (int i = 1; i <= Width / 2; i++)
	{
		int j = 1;
		srand(time(0));
		Select = rand() % (Width - 2) + 1;
		while (Check[Select])
		{
			j++;
			srand(j * time(0));
			Select = rand() % (Width - 2) + 1;
		}
		Expand(Select * (Height + 1), 0, 0, tot / 3);
		Check[Select] = true;
	}
	for (int i = 0; i < Width; i++)
		Check[i] = false;

	for (int i = 1; i <= Width / 2; i++)
	{
		int j = 1;
		srand(time(0));
		Select = rand() % (Width - 2) + 1;
		while (Check[Select])
		{
			j++;
			srand(j * time(0));
			Select = rand() % (Width - 2) + 1;
		}
		Expand((Select + 1) * (Height + 1) - 1, Height + 1, 0, tot / 3);
		Check[Select] = true;
	}
	Check = NULL;
	Check = new bool[Height];

	for (int i = 0; i < Height; i++)
		Check[i] = false;

	for (int i = 1; i <= Height / 2; i++)
	{
		int j = 1;
		srand(time(0));
		Select = rand() % (Height - 2) + 1;
		while (Check[Select])
		{
			j++;
			srand(j * time(0));
			Select = rand() % (Height - 2) + 1;
		}
		Expand(Select, Height + 1, 0, tot / 3);
		Check[Select] = true;
	}

	for (int i = 0; i < Height; i++)
		Check[i] = false;

	for (int i = 1; i <= Height / 2; i++)
	{
		int j = 1;
		srand(time(0));
		Select = rand() % (Height - 2) + 1;
		while (Check[Select])
		{
			j++;
			srand(j * time(0));
			Select = rand() % (Height - 2) + 1;
		}
		Expand(Width * (Height + 1) + Select, 0, 0, tot / 3);
		Check[Select] = true;
	}
}

void MAZE::Print()
{
	for (int i = 0; i < Height; i++)
		cout << " _";
	cout << endl;
	for (int i = Height + 1; i < (Width + 1) * (Height + 1); i++)
	{
		if (i == (Width + 1) * (Height + 1) - 1)
		{
			cout << " " << endl;
			continue;
		}
		if (Con[i][i - (Height + 1)])
			cout << "|";
		else
			cout << " ";
		if ((Con[i][i + 1]) && (i % (Height + 1) < Height))
			cout << "_";
		else
			cout << " ";
		if (i % (Height + 1) == Height)
		{
			cout << endl;
		}
	}
}

void MAZE::PrintToFile(string FileName)
{
	ofstream Output;
	Output.open(FileName +".txt");

	for (int i = 0; i < Height; i++)
		Output << " _";
	Output << endl;
	for (int i = Height + 1; i < (Width + 1) * (Height + 1); i++)
	{
		if (i == (Width + 1) * (Height + 1) - 1)
		{
			Output << " " << endl;
			continue;
		}
		if (Con[i][i - (Height + 1)])
			Output << "|";
		else
			Output << " ";
		if ((Con[i][i + 1]) && (i % (Height + 1) < Height))
			Output << "_";
		else
			Output << " ";
		if (i % (Height + 1) == Height)
			Output << endl;
	}
	Output.close();
}

MAZE::~MAZE()
{
}
