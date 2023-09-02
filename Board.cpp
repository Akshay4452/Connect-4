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

bool Board::HorizontalCheck(int row, int column)
{
    int counter = 1;
    for (int i = 1; i < columns; i++)
    {
        if (board[row][i].GetTileValue() != " " && board[row][i].GetTileValue() == board[row][i - 1].GetTileValue())
        {
            counter += 1;
            if (counter == 4)
            {
                return true;
            }
        }
        else
        {
            counter = 1;
        }
    }
    return false;
}

bool Board::VerticalCheck(int row, int column)
{
    int counter = 1;
    for (int i = 1; i < rows; i++)
    {
        if (board[i][column].GetTileValue() != " " && board[i][column].GetTileValue() == board[i - 1][column].GetTileValue())
        {
            counter += 1;
            if (counter == 4)
            {
                return true;
            }
        }
        else
        {
            counter = 1;
        }
    }
    return false;
}

bool Board::LeftDiagonalCheck(int row, int column)
{
    int count = 1;
    int right = std::min(5 - row, 6 - column);
    int left = std::min(row, column);
    for (int i = -left + 1; i <= right; i++)
    {
        int rowIndex = row + i;
        int colIndex = column + i;
        if (board[rowIndex][colIndex].GetTileValue() != " " && board[rowIndex][colIndex].GetTileValue() == board[rowIndex - 1][colIndex - 1].GetTileValue())
        {
            count += 1;
            if (count == 4)
            {
                return true;
            }
        }
        else
        {
            count = 1;
        }
    }
    return false;
}

bool Board::RightDiagonalCheck(int row, int column)
{
    int count = 1;
    int right = std::min(row, 6 - column);
    int left = std::min(5 - row, column);
    for (int i = -left + 1; i <= right; i++)
    {
        int rowIndex = row - i;
        int colIndex = column + i;
        if (board[rowIndex][colIndex].GetTileValue() != " " && board[rowIndex][colIndex].GetTileValue() == board[rowIndex + 1][colIndex - 1].GetTileValue())
        {
            count += 1;
            if (count == 4)
            {
                return true;
            }
        }
        else
        {
            count = 1;
        }
    }
    return false;
}