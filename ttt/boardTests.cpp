#include "pch.h"
#include "Board.h"
#include "TestUtils.h"

using namespace testing;

Board CreateBoardWithRowWin() {
	vector<int> positions(3);
	positions.push_back(0);
	positions.push_back(1);
	positions.push_back(2);
	return TestUtils::CreateBoardStateWithMarks(positions, 'x');
}

Board CreateBoardWithColumnWin() {
	vector<int> positions(3);
	positions.push_back(0);
	positions.push_back(3);
	positions.push_back(6);
	return TestUtils::CreateBoardStateWithMarks(positions, 'x');
}

Board CreateBoardWithRightDiagonalWin() {
	vector<int> positions(3);
	positions.push_back(0);
	positions.push_back(4);
	positions.push_back(8);
	return TestUtils::CreateBoardStateWithMarks(positions, 'x');
}

Board CreateBoardWithLeftDiagonalWin() {
	vector<int> positions(3);
	positions.push_back(2);
	positions.push_back(4);
	positions.push_back(6);
	return TestUtils::CreateBoardStateWithMarks(positions, 'x');
}

void SetUpTestCase() {
	Board board(TestUtils::CreateBoardState());
}

TEST(Board, BoardIsCreated) {
	Board board(TestUtils::CreateBoardState());
	ASSERT_THAT(board.GetState(), ElementsAre(
		'-', '-', '-', 
		'-', '-', '-', 
		'-', '-', '-'));
}

TEST(Board, MarkIsPlaced) {
	Board board(TestUtils::CreateBoardState());
	Board newBoard = board.PlaceMark(0, 'x');
	ASSERT_EQ(newBoard.GetState()[0], 'x');
}

TEST(Board, KnowIfAPositionIsEmpty) {
	Board board(TestUtils::CreateBoardState());
	board.PlaceMark(0, 'x');
	ASSERT_FALSE(board.PositionIsEmpty(0));
}

TEST(Board, WinningRow) {
	Board board(CreateBoardWithRowWin());
	ASSERT_TRUE(board.IsWon());
}

TEST(Board, WinningColumn) {
	Board board(CreateBoardWithColumnWin());
	ASSERT_TRUE(board.IsWon());
}

TEST(Board, WinningRightDiagonal) {
	Board board(CreateBoardWithRightDiagonalWin());
	ASSERT_TRUE(board.IsWon());
}

TEST(Board, WinningLeftDiagonal) {
	Board board(CreateBoardWithLeftDiagonalWin());
	ASSERT_TRUE(board.IsWon());
}

TEST(Board, KnowsWhenThereIsNoWinner) {
	Board board(TestUtils::CreateBoardState());
	Board newBoard = board.PlaceMark(1, 'x');
	ASSERT_FALSE(newBoard.IsWon());
}