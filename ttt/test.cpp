#include "pch.h"
#include "Board.h"
#include "gmock/gmock.h"

using namespace testing;

TEST(Board, TestName) {
	Board board;
	ASSERT_THAT(board.GetBoard(), ElementsAre('-', '-', '-', 
											  '-', '-', '-', 
											  '-', '-', '-'));
}