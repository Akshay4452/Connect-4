#include "Board.h"

void Board::SetBoard() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			board[i][j].SetTileValue(" ");
		}
	}
}

void Board::PrintBoard() {
	std::cout << std::endl << "********** GAME BOARD **********" << std::endl;
	std::cout << "Column:  1  2  3  4  5  6  7  " << std::endl;
	std::cout << "------------------------------" << std::endl;
	for (int i = 0; i < rows; i++) {
		std::cout << "        |";
		for (int j = 0; j < columns; j++) {
			std::cout << board[i][j].GetTileValue() << " |";
		}
		std::cout << std::endl << "        ----------------------" << std::endl;
	}
	std::cout << "------------------------------" << std::endl;
}