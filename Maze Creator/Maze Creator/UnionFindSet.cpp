#include "UnionFindSet.h"

UnionFindSet::UnionFindSet()
{
	Parent = nullptr;
}

UnionFindSet::UnionFindSet(int SIZE)
{
	Parent = nullptr;
	Reset(SIZE);
}

void UnionFindSet::Reset(int SIZE)
{
	Size = SIZE;
	Parent = new int[Size];
	for (int Vertix = 0; Vertix < Size; Vertix++)
	{
		Parent[Vertix] = Vertix;
	}
}

int UnionFindSet::FindRoot(int Vertix)
{
	while (Parent[Vertix] != Vertix)
	{
		Vertix = Parent[Vertix];
	}
	return Vertix;
}

void UnionFindSet::Union(int Root1, int Root2)
{
	Parent[FindRoot(Root2)] = FindRoot(Root1);
}

UnionFindSet::~UnionFindSet()
{
	delete[] Parent;
}