#pragma once
#include <vector>
#include <ostream>
#include <string>

using std::vector;
using std::ostream;
using std::string;

class ConsoleGameType
{
public:
	ConsoleGameType();
	~ConsoleGameType();
	void DisplayBoard(vector<char> state, ostream& output);
};

