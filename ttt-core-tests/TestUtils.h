#pragma once
#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using std::vector;
using namespace testing;

class TestUtils
{
public:
	TestUtils();
	~TestUtils();
	static vector<char> CreateBoardState();
	static vector<char> CreateBoardStateWithMarks(vector<int> positions, char mark);
};