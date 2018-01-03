#pragma once

#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using std::vector;
using namespace testing;

class ConsoleTests
{
public:
	ConsoleTests();
	~ConsoleTests();
	static vector<char> CreateBoardState();
};

