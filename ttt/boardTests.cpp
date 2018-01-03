#include "pch.h"
#include "Board.h"
#include "TestUtils.h"

using namespace testing;

void MakeXWinRow(Board& board) {
	board.PlaceMark(0, 'x');
	board.PlaceMark(1, 'x');
	board.PlaceMark(2, 'x');
}

void MakeXWinColumn(Board& board) {
	board.PlaceMark(0, 'x');
	board.PlaceMark(3, 'x');
	board.PlaceMark(6, 'x');
}

void MakeXWinRightDiagonal(Board& board) {
	board.PlaceMark(0, 'x');
	board.PlaceMark(4, 'x');
	board.PlaceMark(8, 'x');
}

void MakeXWinLeftDiagonal(Board& board) {
	board.PlaceMark(2, 'x');
	board.PlaceMark(4, 'x');
	board.PlaceMark(6, 'x');
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
	board.PlaceMark(0, 'x');
	ASSERT_EQ(board.GetState()[0], 'x');
}

TEST(Board, KnowIfAPositionIsEmpty) {
	Board board(TestUtils::CreateBoardState());
	board.PlaceMark(0, 'x');
	ASSERT_FALSE(board.PositionIsEmpty(0));
}

TEST(Board, WinningRow) {
	Board board(TestUtils::CreateBoardState());
	MakeXWinRow(board);
	ASSERT_TRUE(board.IsWon());
}

TEST(Board, WinningColumn) {
	Board board(TestUtils::CreateBoardState());
	MakeXWinColumn(board);
	ASSERT_TRUE(board.IsWon());
}

TEST(Board, WinningRightDiagonal) {
	Board board(TestUtils::CreateBoardState());
	MakeXWinRightDiagonal(board);
	ASSERT_TRUE(board.IsWon());
}

TEST(Board, WinningLeftDiagonal) {
	Board board(TestUtils::CreateBoardState());
	MakeXWinLeftDiagonal(board);
	ASSERT_TRUE(board.IsWon());
}

TEST(Board, KnowsWhenThereIsNoWinner) {
	Board board(TestUtils::CreateBoardState());
	board.PlaceMark(2, 'x');
	board.PlaceMark(1, 'x');
	ASSERT_FALSE(board.IsWon());
}