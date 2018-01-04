#pragma once
#include <vector>

using std::vector;

class Combinations
{
public:
	Combinations(int size = 3);
	~Combinations();
	vector<vector<vector<int>>> GetAll();
private:
	void AddRows();
	void AddColumns();
	void AddDiagonals();
	vector<int> GetLeftDiagonal();
	vector<int> GetRightDiagonal();
	int size;
	vector<vector<vector<int>>> combinations;
};

