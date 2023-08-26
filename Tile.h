#pragma once
#include "Player.h"
#include <string>

class Tile {
private:
	std::string m_tileValue;
public:
	Tile();
	std::string GetTileValue();
	void SetTileValue(std::string value);
};