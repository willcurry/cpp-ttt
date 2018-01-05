#pragma once
class Player
{
public:
	Player(char mark);
	~Player();
	virtual char GetMark();
	virtual int NextMove();
private:
	char mark;
};

