#include "pch.h"
#include "Board.h"
#include "gmock/gmock.h"

using namespace testing;

void MakeXWinRow(Board& board) {
	board.PlaceMark(0, 'x');
	board.PlaceMark(8, 'x');
	board.PlaceMark(1, 'x');
	board.PlaceMark(7, 'x');
	board.PlaceMark(2, 'x');
}

void MakeXWinColumn(Board& board) {
	board.PlaceMark(0, 'x');
	board.PlaceMark(1, 'x');
	board.PlaceMark(3, 'x');
	board.PlaceMark(8, 'x');
	board.PlaceMark(6, 'x');
}

void MakeXWinRightDiagonal(Board& board) {
	board.PlaceMark(0, 'x');
	board.PlaceMark(1, 'x');
	board.PlaceMark(4, 'x');
	board.PlaceMark(6, 'x');
	board.PlaceMark(8, 'x');
}

void MakeXWinLeftDiagonal(Board& board) {
	board.PlaceMark(2, 'x');
	board.PlaceMark(1, 'x');
	board.PlaceMark(4, 'x');
	board.PlaceMark(8, 'x');
	board.PlaceMark(6, 'x');
}

TEST(Board, BoardIsCreated) {
	Board board;
	ASSERT_THAT(board.GetBoard(), ElementsAre(
		'-', '-', '-', 
		'-', '-', '-', 
		'-', '-', '-'));
}

TEST(Board, MarkIsPlaced) {
	Board board;
	board.PlaceMark(0, 'x');
	ASSERT_EQ(board.GetBoard()[0], 'x');
}

TEST(Board, PlayerSwitches) {
	Board board;
	board.PlaceMark(0, 'x');
	board.PlaceMark(1, 'x');
	ASSERT_EQ(board.GetBoard()[0], 'x');
	ASSERT_EQ(board.GetBoard()[1], 'o');
}

TEST(Board, KnowIfAPositionIsEmpty) {
	Board board;
	board.PlaceMark(0, 'x');
	ASSERT_FALSE(board.PositionIsEmpty(0));
}

TEST(Board, WinningRow) {
	Board board;
	MakeXWinRow(board);
	ASSERT_TRUE(board.IsWon());
}

TEST(Board, WinningColumn) {
	Board board;
	MakeXWinColumn(board);
	ASSERT_TRUE(board.IsWon());
}

TEST(Board, WinningRightDiagonal) {
	Board board;
	MakeXWinRightDiagonal(board);
	ASSERT_TRUE(board.IsWon());
}

TEST(Board, WinningLeftDiagonal) {
	Board board;
	MakeXWinLeftDiagonal(board);
	ASSERT_TRUE(board.IsWon());
}

TEST(Board, KnowsWhenThereIsNoWinner) {
	Board board;
	board.PlaceMark(2, 'x');
	board.PlaceMark(1, 'x');
	ASSERT_FALSE(board.IsWon());
}