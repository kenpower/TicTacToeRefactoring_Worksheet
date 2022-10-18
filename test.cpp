#include "pch.h"
#include "TicTacToe.h"

TEST(TicTacToe, FirstAvailableMove5) {
	TicTacToe ttt("XOXOX-OXO");
	EXPECT_EQ(5, ttt.move('X'));
}

TEST(TicTacToe, FirstAvailableMove8) {
	TicTacToe ttt("XOXOXOOX-");
	EXPECT_EQ(8, ttt.move('X'));
}

TEST(TicTacToe, FirstAvailableMove0) {
	TicTacToe ttt("---------");
	EXPECT_EQ(0, ttt.move('X'));
}

TEST(TicTacToe, FirstAvailableMoveNone) {
	TicTacToe ttt("XXXXXXXX");
	EXPECT_EQ(-1, ttt.move('X'));
}

TEST(TicTacToe, WinningMove) {
	TicTacToe ttt("XO-XX-OOX");
	EXPECT_EQ(5, ttt.move('X'));
}
