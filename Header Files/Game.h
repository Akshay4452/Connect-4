#pragma once
#include "Board.h"

class Game {
public:
	Game();  // Default constructor
public:
	Board board;
	bool isGameOver, isGameDraw;
	int tilesLeft;
	Player currentPlayer;
	void WrongInput();
	void OutOfBoundsInput(int col);
	void GameRules();
	void GameStatus(int row, int col);
	void PlayerInput(Player currentPlayer);
	void Play();
	void PlayerWon();
	void ResetGame();
public:
	~Game() {
		std::cout << "Game object destroyed\n";
	}
};