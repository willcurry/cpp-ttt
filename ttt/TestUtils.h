#pragma once
#include <vector>
#include "gmock/gmock.h"

using std::vector;

class TestUtils
{
public:
	TestUtils();
	~TestUtils();
	static vector<char> CreateBoardState();
};

