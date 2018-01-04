#pragma once
#include <vector>
#include <ostream>
#include <string>
#include "..\ttt-core\GameType.h"

using std::vector;
using std::ostream;
using std::istream;
using std::string;

class ConsoleGameType : public GameType
{
public:
	ConsoleGameType(ostream& output, istream& input);
	~ConsoleGameType();
	void DisplayBoard(vector<char> state);
	void Start();
private:
	ostream& output;
	istream& input;
};

