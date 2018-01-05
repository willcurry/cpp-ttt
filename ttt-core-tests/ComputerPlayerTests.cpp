#include "..\ttt-core\ComputerPlayer.h"
#include "..\ttt-test-utilities\TestUtils.h"
#include "tests.h"

TEST(ComputerPlayer, BlocksRowWin) {
	vector<int> moves;
	moves.push_back(0);
	moves.push_back(1);
	Board board(TestUtils::CreateBoardStateWithMarks(moves, 'x'));
	ComputerPlayer player('o');
	ASSERT_EQ(player.NextMove(board), 2);
}

TEST(ComputerPlayer, GoesInTheOnlyFreePosition) {
	vector<int> moves;
	moves.push_back(0);
	moves.push_back(1);
	moves.push_back(2);
	moves.push_back(3);
	moves.push_back(4);
	moves.push_back(5);
	moves.push_back(6);
	moves.push_back(7);
	Board board(TestUtils::CreateBoardStateWithMarks(moves, 'x'));
	ComputerPlayer player('o');
	ASSERT_EQ(player.NextMove(board), 8);
}