#include "Level.h"

#include <cstring>

Level::Level()
{
}

Level::~Level()
{
}

void Level::LoadResources(const unsigned short* a_tiles, const short a_palette)
{
	memcpy(palette_sp_block_address(0), a_tiles, a_palette);
	memcpy(palette_sp_block_address(0), a_tiles, a_palette);
}
