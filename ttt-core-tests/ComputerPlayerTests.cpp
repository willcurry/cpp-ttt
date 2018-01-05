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