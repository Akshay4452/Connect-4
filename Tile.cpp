#include "Tile.h"

Tile::Tile() {}

std::string Tile::GetTileValue() {
	return m_tileValue;
}

void Tile::SetTileValue(std::string value) {
	m_tileValue = value;
}