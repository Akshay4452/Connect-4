#include "Game.h"

void Game::WrongInput() {
    std::cout << "*------------------------------------------*\n"
        << "|                                          |\n"
        << "|             WRONG INPUT...               |\n"
        << "|              TRY AGAIN                   |\n"
        << "|                                          |\n"
        << "*------------------------------------------*\n";
}

void Game::OutOfBoundsInput(int col) {
    std::cout << "*----------------------------------------------------------*\n"
        << "|                                                          |\n"
        << "|                         WRONG INPUT...                   |\n"
        << "|                     Column " << col + 1 << " is already full.            |\n"
        << "|                                                          |\n"
        << "*----------------------------------------------------------*\n";
}

void Game::GameRules() {
    std::cout << "*---------------------------------------------------------------------------------------*\n"
        << "|                                                                                       |\n"
        << "|                              WELCOME TO CONNECT-4 GAME                                |\n"
        << "|                                                                                       |\n"
        << "*---------------------------------------------------------------------------------------*\n"
        << "|                                                                                       |\n"
        << "|                                      RULES:                                           |\n"
        << "|                                                                                       |\n"
        << "| 1. Two-Player (Red-R & Blue-B) game.                                                  |\n"
        << "| 2. Board size (6 Rows X 7 Columns).                                                   |\n"
        << "| 3. A Player wins if manages to connect 4 dots Horizontally, Vertically or Diagonally. |\n"
        << "| 4. Draw when board is fully filled.                                                   |\n"
        << "|                                                                                       |\n"
        << "*---------------------------------------------------------------------------------------*\n"
        << "|                                                                                       |\n"
        << "|                                   HOW TO PLAY:                                        |\n"
        << "|                                                                                       |\n"
        << "| 1. Game starts with Red Player.                                                       |\n"
        << "| 2. In each step, choose column to drop ball.                                          |\n"
        << "| 3. Rows will be filled from bottom to top in any column.                              |\n"
        << "|                                                                                       |\n"
        << "*---------------------------------------------------------------------------------------*\n";

    board.PrintBoard();
}

void Game::GameStatus(int row, int col) {
    // Checks if either of the player has won or game is drawn
    if (tilesLeft == 0) {
        isGameDraw = true;
        isGameOver = true;
    }
    else {
        isGameOver = board.HorizontalCheck(row, col) || board.VerticalCheck(row, col) || 
            board.LeftDiagonalCheck(row, col) || board.RightDiagonalCheck(row, col);
    }
}

void Game::PlayerInput(Player currentPlayer) {
    int row, col = -1;
    std::string currentValue = " ";
    bool isInputCorrect = false;
    while (!isInputCorrect) {
        std::cout << "\n * --------------------INPUT-------------------- * \n";
        std::cout << "Player " << static_cast<int>(currentPlayer) + 1 << " (" << (currentPlayer == Player::Player1 ? "R" : "B") << 
            ") - Enter column (1-7)"; // typecasting Player enum
        std::cin >> col;
        if (col >= 1 && col <= 7) {
            col--;
            // update the value to be printed in the tile
            currentValue = currentPlayer == Player::Player1 ? "R" : "B";
            for (int i = 5; i >= 0; i--) {
                if (board.UpdateGrid(col, currentValue, i)) {
                    row = i;
                    isInputCorrect = true;
                    break;
                }
            }
            if (!isInputCorrect) {
                OutOfBoundsInput(col);
            }
        }
        else {
            WrongInput();
        }
    }
    tilesLeft--;
    GameStatus(row, col);  // checks if either of player has won
}

void Game::Play() {
    GameRules(); // Print the game rules
    while (!isGameOver) {
        PlayerInput(currentPlayer);
        board.PrintBoard();
        if (currentPlayer == Player::Player1) { currentPlayer = Player::Player2; }
        else { currentPlayer = Player::Player1; }
    }
    PlayerWon();
}

void Game::PlayerWon() {
    std::string winner = currentPlayer == Player::Player1 ? "Player 2 (B) Won!" :
        "Player 1 (R) Won!";
    winner = isGameDraw ? "*-------------------- IT'S A DRAW !! --------------------*" : winner;
    std::cout << "\n*-------------------- GAME OVER --------------------*";
    std::cout << std::endl << winner << std::endl;
    std::cout << "*---------------------------------------------------------------------------------------*\n"
        << "|                                                                                       |\n"
        << "|                        THANK YOU FOR PLAYING CONNECT-4 GAME                           |\n"
        << "|                                                                                       |\n"
        << "*---------------------------------------------------------------------------------------*\n";
}

void Game::ResetGame() {
    // set the board to empty values
    board.SetBoard();
    isGameDraw = false;
    isGameOver = false;
    tilesLeft = board.GetRows() * board.GetColumns();

    // set the current player to player1
    currentPlayer = Player::Player1;
}

// Invoke the constructor

Game::Game() {
    ResetGame();
    Play();
}