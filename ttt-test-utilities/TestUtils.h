#pragma once
#include <vector>
using std::vector;

class TestUtils
{
public:
	TestUtils();
	~TestUtils();
	static vector<char> CreateBoardState();
	static vector<char> CreateBoardStateWithMarks(vector<int> positions, char mark);
};