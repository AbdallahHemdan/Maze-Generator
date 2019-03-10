#pragma once

class UnionFindSet
{
private:
	int* Parent;
	int Size;

public:
	UnionFindSet();
	UnionFindSet(int SIZE);
	void Reset(int SIZE);
	int FindRoot(int Value);
	void Union(int Root1, int Root2);
	~UnionFindSet();
};