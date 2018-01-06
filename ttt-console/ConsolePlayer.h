#pragma once
#include "..\ttt-core\Player.h"
#include <ostream>
#include <string>

using std::istream;
using std::string;

class ConsolePlayer : public Player
{
public:
	ConsolePlayer(char mark, istream& input);
	~ConsolePlayer();
	int NextMove(Board& board);
private:
	istream& input;
};

