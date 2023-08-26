#pragma once
#include "Tile.h"
#define RED_TEXT "\033[31m"
#define BLUE_TEXT "\033[34m"
#define DEFAULT_COLOR "\033[0m"

class Board {
private:
	static const int rows = 6;
	static const int columns = 7;
	Tile board[rows][columns];  // 2D array of tiles
public:
	void SetBoard();
	void PrintBoard();
	bool UpdateBoard();
	bool HorizontalCheck();
	bool VerticalCheck();
	bool LeftDiagonalCheck();
	bool RightDiagonalCheck();
};