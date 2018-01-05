#pragma once
#include "..\ttt-core\Player.h";
#include <vector>

using std::vector;

class TestPlayer : public Player
{
public:
	TestPlayer(char mark, vector<int> moves);
	~TestPlayer();
	virtual int NextMove();
private:
	vector<int> moves;
	int nextPosition;
};

