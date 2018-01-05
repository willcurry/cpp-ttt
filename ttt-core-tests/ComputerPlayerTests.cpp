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

TEST(ComputerPlayer, BlocksColumnWin) {
	vector<int> moves;
	moves.push_back(0);
	moves.push_back(3);
	Board board(TestUtils::CreateBoardStateWithMarks(moves, 'x'));
	ComputerPlayer player('o');
	ASSERT_EQ(player.NextMove(board), 6);
}

TEST(ComputerPlayer, BlocksDiagonalWin) {
	vector<int> moves;
	moves.push_back(0);
	moves.push_back(4);
	Board board(TestUtils::CreateBoardStateWithMarks(moves, 'x'));
	ComputerPlayer player('o');
	ASSERT_EQ(player.NextMove(board), 8);
}

TEST(ComputerPlayer, GoesForRowWin) {
	vector<int> moves;
	moves.push_back(0);
	moves.push_back(1);
	Board board(TestUtils::CreateBoardStateWithMarks(moves, 'o'));
	ComputerPlayer player('o');
	ASSERT_EQ(player.NextMove(board), 2);
}

TEST(ComputerPlayer, GoesForColumnWin) {
	vector<int> moves;
	moves.push_back(0);
	moves.push_back(3);
	Board board(TestUtils::CreateBoardStateWithMarks(moves, 'o'));
	ComputerPlayer player('o');
	ASSERT_EQ(player.NextMove(board), 6);
}

TEST(ComputerPlayer, GoesForDiagonalWin) {
	vector<int> moves;
	moves.push_back(0);
	moves.push_back(4);
	Board board(TestUtils::CreateBoardStateWithMarks(moves, 'o'));
	ComputerPlayer player('o');
	ASSERT_EQ(player.NextMove(board), 8);
}