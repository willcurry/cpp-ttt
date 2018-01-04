#include "stdafx.h"
#include "Combinations.h"

Combinations::Combinations(int size)
{
	this->size = size;
	AddRows();
	AddColumns();
	AddDiagonals();
}

Combinations::~Combinations()
{
	combinations.clear();
}

vector<vector<vector<int>>> Combinations::GetAll()
{
	return combinations;
}

void Combinations::AddRows()
{
	vector<vector<int>> rows;
	for (int i = 0; i < size * size; i += size) {
		vector<int> row;
		for (int j = i; j < i + size; j++) {
			row.push_back(j);
		}
		rows.push_back(row);
	}
	combinations.push_back(rows);
}

void Combinations::AddColumns()
{
	vector<vector<int>> columns;
	for (int i = 0; i < size; i++) {
		vector<int> column;
		for (int j = i; j < size * size; j += size) {
			column.push_back(j);
		}
		columns.push_back(column);
	}
	combinations.push_back(columns);
}

void Combinations::AddDiagonals()
{
	vector<vector<int>> diagonals;
	diagonals.push_back(GetLeftDiagonal());
	diagonals.push_back(GetRightDiagonal());
	combinations.push_back(diagonals);
}

vector<int> Combinations::GetLeftDiagonal()
{
	vector<int> leftDiagonal;
	for (int i = size; i > 0; i--) {
		int position = i * size - i;
		leftDiagonal.push_back(position);
	}
	return leftDiagonal;
}

vector<int> Combinations::GetRightDiagonal()
{
	vector<int> rightDiagonal;
	for (int i = 0; i < size; i++) {
		int position = i * size + i;
		rightDiagonal.push_back(position);
	}
	return rightDiagonal;
}